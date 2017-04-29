#include "Stage.h"

Stage::Stage()
{
}

Stage::~Stage()
{
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
					(*it)->ColFire();
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
}

void Stage::AddMonster(Monster* monster)
{
	m_MonsterList.push_back(monster);
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

void Stage::DrawMonster()
{
	for (auto it = m_MonsterList.begin(); it != m_MonsterList.end(); ++it)
	{
		(*it)->Draw();
	}
}