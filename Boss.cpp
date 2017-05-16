#include "Boss.h"

Boss::Boss()
{
}

Boss::~Boss()
{
}

void Boss::ColFire()
{
	//if (m_ColTimer > 0.2f)
	{
		cout << "보스 타격" << endl;
		m_HP--;
		m_ColTimer = 0;
	}
}

bool Boss::GetCanCol()
{
	if (m_ColTimer > 0.2f)
	{
		return true;
	}
	else
		return false;
}

bool Boss::GetShoot()
{
	if (m_bShootBullet)
	{
		cout << "보스 불릿 발사" << endl;
		m_bShootBullet = false;
		return true;
	}
	else
		return false;
}

void Boss::ShootBullet(bool toPlayer)
{
	m_BulletData.angle = 180;
	m_BulletData.toPlayer = toPlayer;
	m_bShootBullet = true;
}

void Boss::ShootBullet(bool toPlayer, int count, float startAngle, float angle)
{
	m_BulletData.toPlayer = toPlayer;
	m_BulletData.count = count;
	m_BulletData.startAngle = startAngle;
	m_BulletData.angle = angle;
	m_bShootBullet = true;
}