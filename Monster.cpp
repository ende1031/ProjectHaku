#include "Monster.h"

Monster::Monster(Texture texture, Sound* sound, int pattern, MonsterData data)
{
	Start(texture, sound, pattern, data);
	cout << pattern << "패턴 몬스터 생성" << endl;
}

Monster::~Monster()
{
}

void Monster::Start(Texture texture, Sound* sound, int pattern, MonsterData data)
{
	m_bActive = true;
	m_MonsterData = data;
	m_Pattern = pattern;

	m_pSprite = Device::GetSprite();
	m_pTexture = texture.GetTexture();

	m_AniTimer = 0;
	m_AniNum = 0;
	m_ColTimer = 1.0f;
	m_ariveTime = 0;

	m_radius = m_MonsterData.radius;
	m_HP = m_MonsterData.maxHP;

	m_alpha = 0;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, (LONG)texture.GetWidth() / m_MonsterData.rowNum, (LONG)texture.GetHeight() / ((m_MonsterData.lastNum - 1) / m_MonsterData.rowNum + 1) };

	m_width = (float)m_rect.right;
	m_height = (float)m_rect.bottom;

	m_bShootBullet = false;
	m_ShootTimer = 0;
	m_attackCount = 2;

	m_sinAngle = 0;
	m_bMoveUp = false;

	//패턴별 시작 위치 등 설정
	switch (m_Pattern)
	{
	case 0:
		m_vPos = D3DXVECTOR3(1000 - m_width / 2, 135 - m_height / 2, 0);
		break;
	case 1:
		m_vPos = D3DXVECTOR3(1000 - m_width / 2, 270 - m_height / 2, 0);
		break;
	case 2:
		m_vPos = D3DXVECTOR3(1000 - m_width / 2, 405 - m_height / 2, 0);
		break;
	case 3:
		m_vPos = D3DXVECTOR3(1000 - m_width / 2, 95 - m_height / 2, 0);
		break;
	case 4:
		m_vPos = D3DXVECTOR3(1000 - m_width / 2, 230 - m_height / 2, 0);
		break;
	case 5:
		m_vPos = D3DXVECTOR3(1000 - m_width / 2, 365 - m_height / 2, 0);
		break;
	case 6:
		m_vPos = D3DXVECTOR3(1000 - m_width / 2, 135 - m_height / 2, 0);
		break;
	case 7:
		m_bMoveUp = true;
		m_vPos = D3DXVECTOR3(1000 - m_width / 2, 405 - m_height / 2, 0);
		break;
	}
}

void Monster::Update(float deltaTime)
{
	m_ariveTime += deltaTime;
	m_ColTimer += deltaTime;
	m_ShootTimer += deltaTime;
	FadeIn(&m_alpha, deltaTime);
	Animation(m_MonsterData.rowNum, m_MonsterData.lastNum, 0.1f, deltaTime);

	if (m_HP <= 0)
	{
		m_bActive = false;
	}

	//패턴별 움직임 설정
	switch (m_Pattern)
	{
	case 0:	case 1:	case 2: //그냥 앞으로 이동
		Move(-300, 0, deltaTime);
		break;
	case 3:	case 4:	case 5: //사인곡선
		Move(-300, 200 * sin(m_sinAngle * (D3DX_PI / 180)), deltaTime);
		m_sinAngle += 5;
		if (m_sinAngle > 360.0f)
			m_sinAngle -= 360.0f;
		break;
	case 6: case 7: //크게 왔다갔다
		Move(-300, 0, deltaTime);
		if (m_bMoveUp)
		{
			Move(0, -200, deltaTime);
			if (GetvCenterPos().y < 100)
				m_bMoveUp = false;
		}
		else
		{
			Move(0, 200, deltaTime);
			if (GetvCenterPos().y > ScreenSizeY - 100)
				m_bMoveUp = true;
		}
		break;
	}

	//스크린 밖에서 생성되기 때문에 스크린 밖에 있어도 생성후 일정시간이 지난 몬스터만 삭제
	if (m_ariveTime > 2.0f)
	{
		if (GetOutsideScreen())
		{
			cout << "화면 밖으로 나간 몬스터 삭제" << endl;
			m_bActive = false;
		}
	}

	if (m_ariveTime > 1.0f && m_ShootTimer > 0.5f)
	{
		/*
		if (m_attackCount > 2)
		{
			ShootBullet(false, 3, 170.0f, 10.0f);
			m_attackCount = 0;
		}
		else
		{
			ShootBullet(false, 1, 180.0f, 0);
			m_attackCount++;
		}
		*/
		ShootBullet(false, 1, 180.0f, 0);
		m_ShootTimer = 0;
	}
}

void Monster::ColFire()
{
	//if (m_ColTimer > 0.2f)
	{
		cout << "몬스터 타격" << endl;
		m_HP--;
		m_ColTimer = 0;
	}
}

bool Monster::GetCanCol()
{
	if (m_ColTimer > 0.2f)
	{
		return true;
	}
	else
		return false;
}

bool Monster::GetShoot()
{
	if (m_bShootBullet)
	{
		cout << "몬스터 불릿 발사" << endl;
		m_bShootBullet = false;
		return true;
	}
	else
		return false;
}

void Monster::ShootBullet(bool toPlayer)
{
	m_BulletData.startAngle = 180;
	m_BulletData.toPlayer = toPlayer;
	m_bShootBullet = true;
}

void Monster::ShootBullet(bool toPlayer, int count, float startAngle, float angle)
{
	m_BulletData.toPlayer = toPlayer;
	m_BulletData.count = count;
	m_BulletData.startAngle = startAngle;
	m_BulletData.angle = angle;
	m_bShootBullet = true;
}