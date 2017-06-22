#include "Stage.h"

Stage::Stage()
{
}

Stage::~Stage()
{
	SAFE_DELETE_ARRAY(m_MonsterFileData);
	SAFE_DELETE(m_pBoss);
}

void Stage::Collision()
{
	for (auto it = m_MonsterList.begin(); it != m_MonsterList.end(); ++it)
	{
		//몬스터 - 여우령 충돌
		for (int i = 0; i < 15; i++)
		{
			if (m_Fire[i].GetActive())
			{
				float distance = D3DXVec3Length(&((*it)->GetvCenterPos() - m_Fire[i].GetvCenterPos()));
				if (distance < (*it)->GetRadius() + m_Fire[i].GetRadius())
				{
					//충돌
					if (m_Fire[i].GetCanCol())
					{
						AddEffect(new Effect(m_tEffect, m_pSound, m_Fire[i].GetvCenterPos()));
						m_Player.SetPointUP(1);
						(*it)->ColFire();
						m_Fire[i].ColMonster();
					}
				}
			}
		}

		//몬스터 - 플레이어 충돌
		float distance = D3DXVec3Length(&((*it)->GetvCenterPos() - m_Player.GetvCenterPos()));
		if (distance < (*it)->GetRadius() + m_Player.GetRadius())
		{
			//충돌
			m_Player.ColMonster();
		}
	}

	//보스 - 여우령 충돌
	for (int i = 0; i < 15; i++)
	{
		if (m_Fire[i].GetActive() && m_pBoss->GetActive())
		{
			float distance = D3DXVec3Length(&(m_pBoss->GetvCenterPos() - m_Fire[i].GetvCenterPos()));
			if (distance < m_pBoss->GetRadius() + m_Fire[i].GetRadius())
			{
				//충돌
				if (m_Fire[i].GetCanCol())
				{
					m_Player.SetPointUP(1);
					AddEffect(new Effect(m_tEffect, m_pSound, m_Fire[i].GetvCenterPos()));
					m_pBoss->ColFire();
					m_Fire[i].ColMonster();
				}
			}
		}
	}

	//몬스터불릿 - 플레이어 충돌
	for (auto it = m_BulletList.begin(); it != m_BulletList.end(); ++it)
	{
		float distance = D3DXVec3Length(&((*it)->GetvCenterPos() - m_Player.GetvCenterPos()));
		if (distance < (*it)->GetRadius() + m_Player.GetRadius())
		{
			//충돌
			AddMEffect(new MBulletEffect(m_tMEffect, m_pSound, (*it)->GetvCenterPos()));
			m_Player.ColMonster();
			(*it)->SetActive(false);
		}
	}
}

void Stage::AddMonster(Monster* monster)
{
	m_MonsterList.push_back(monster);
}

void Stage::AddBullet(MonsterBullet* bullet)
{
	m_BulletList.push_back(bullet);
}

void Stage::AddEffect(Effect* effect)
{
	m_EffectList.push_back(effect);
}

void Stage::AddMEffect(MBulletEffect* effect)
{
	m_MEffectList.push_back(effect);
}

void Stage::UpdateMonster(float deltaTime)
{
	for (auto it = m_MonsterList.begin(); it != m_MonsterList.end();)
	{
		auto obj = *it;
		if (!obj->GetActive()) //몬스터의 Active가 false면 삭제
		{
			it = m_MonsterList.erase(it);
			SAFE_DELETE(obj);
		}
		else
		{
			(*it)->Update(deltaTime);
			++it;
		}
	}
}

void Stage::UpdateBullet(float deltaTime)
{
	for (auto it = m_BulletList.begin(); it != m_BulletList.end();)
	{
		auto obj = *it;
		if (!obj->GetActive())
		{
			it = m_BulletList.erase(it);
			SAFE_DELETE(obj);
		}
		else
		{
			(*it)->Update(deltaTime);
			++it;
		}
	}
}

void Stage::UpdateEffect(float deltaTime)
{
	for (auto it = m_EffectList.begin(); it != m_EffectList.end();)
	{
		auto obj = *it;
		if (!obj->GetActive())
		{
			it = m_EffectList.erase(it);
			SAFE_DELETE(obj);
		}
		else
		{
			(*it)->Update(deltaTime);
			++it;
		}
	}
}

void Stage::UpdateMEffect(float deltaTime)
{
	for (auto it = m_MEffectList.begin(); it != m_MEffectList.end();)
	{
		auto obj = *it;
		if (!obj->GetActive())
		{
			it = m_MEffectList.erase(it);
			SAFE_DELETE(obj);
		}
		else
		{
			(*it)->Update(deltaTime);
			++it;
		}
	}
}

void Stage::DrawMonster()
{
	for (auto it = m_MonsterList.begin(); it != m_MonsterList.end(); ++it)
	{
		(*it)->Draw();
	}
}

void Stage::DrawBullet()
{
	for (auto it = m_BulletList.begin(); it != m_BulletList.end(); ++it)
	{
		(*it)->Draw();
	}
}

void Stage::DrawEffect()
{
	for (auto it = m_EffectList.begin(); it != m_EffectList.end(); ++it)
	{
		(*it)->Draw();
	}
}

void Stage::DrawMEffect()
{
	for (auto it = m_MEffectList.begin(); it != m_MEffectList.end(); ++it)
	{
		(*it)->Draw();
	}
}

void Stage::LoadMonsters(const char* mobdata)
{
	ifstream Data;
	m_MonsterDataLine = 1;

	//line 수 구하기
	Data.open(mobdata, ios::in);
	char c;
	while (Data.get(c))
	{
		if (c == '\n') ++m_MonsterDataLine;
	}
	Data.close();

	m_MonsterFileData = new MonsterFileData[m_MonsterDataLine];

	//데이터 불러오기
	Data.open(mobdata, ios::in);
	for (int i = 0; i < m_MonsterDataLine; i++)
	{
		Data >> m_MonsterFileData[i].time >> m_MonsterFileData[i].type >> m_MonsterFileData[i].pattern;
	}
	Data.close();

	cout << mobdata << "에서 몬스터 데이터가 로드되었습니다." << endl << "===========================================" << endl;
	for (int i = 0; i < m_MonsterDataLine; i++)
	{
		cout << "시간 : " << m_MonsterFileData[i].time << "\t타입 : " << m_MonsterFileData[i].type << "\t패턴 : " << m_MonsterFileData[i].pattern << endl;
	}
	cout << "===========================================" << endl;
}

void Stage::CheckMonsterShoot()
{
	//몬스터 불릿 발사 체크
	for (auto it = m_MonsterList.begin(); it != m_MonsterList.end(); ++it)
	{
		if ((*it)->GetShoot())
		{
			if ((*it)->GetBulletData().toPlayer)
			{
				AddBullet(new MonsterBullet(m_tMonsterBullet, m_pSound, (*it)->GetvCenterPos(), m_Player.GetvCenterPos()));
			}
			else
			{
				for (int i = 0; i < (*it)->GetBulletData().count; i++)
				{
					AddBullet(new MonsterBullet(m_tMonsterBullet, m_pSound, (*it)->GetvCenterPos(), (*it)->GetBulletData().startAngle + (*it)->GetBulletData().angle * i));
				}
			}
		}
	}

	//보스 불릿 발사 체크
	if (m_pBoss->GetShoot())
	{
		if (m_pBoss->GetBulletData().toPlayer)
		{
			AddBullet(new MonsterBullet(m_tMonsterBullet, m_pSound, m_pBoss->GetvCenterPos(), m_Player.GetvCenterPos()));
		}
		else
		{
			for (int i = 0; i < m_pBoss->GetBulletData().count; i++)
			{
			AddBullet(new MonsterBullet(m_tMonsterBullet, m_pSound, m_pBoss->GetvCenterPos(), m_pBoss->GetBulletData().startAngle + m_pBoss->GetBulletData().angle * i));
			}
		}
	}
}