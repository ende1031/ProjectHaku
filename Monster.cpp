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
	m_rect = { 0, 0, (LONG)m_MonsterData.rectRight, (LONG)m_MonsterData.rectBottom };
	m_width = (float)m_rect.right;
	m_height = (float)m_rect.bottom;

	m_bShootBullet = false;
	m_ShootTimer = 0;

	//패턴별 시작 위치 등 설정
	switch (m_Pattern)
	{
	case 0:
		m_vPos = D3DXVECTOR3(1000 - m_width / 2, 135 - m_height/2, 0);
		break;
	case 1:
		m_vPos = D3DXVECTOR3(1000 - m_width / 2, 270 - m_height / 2, 0);
		break;
	case 2:
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
	case 0:
		Move(-300, 0, deltaTime);
		break;
	case 1:
		Move(-300, 0, deltaTime);
		break;
	case 2:
		Move(-300, 0, deltaTime);
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
		ShootBullet(false, 180);
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
	m_BulletData.angle = 180;
	m_BulletData.toPlayer = toPlayer;
	m_bShootBullet = true;
}

void Monster::ShootBullet(bool toPlayer, float angle)
{
	m_BulletData.angle = angle;
	m_BulletData.toPlayer = toPlayer;
	m_bShootBullet = true;
}