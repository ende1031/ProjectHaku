#pragma once
#include "Object.h"

class Boss : public Object
{
public:
	Boss();
	~Boss();

	int GetPhase() { return m_Phase; };

	bool GetCanCol();
	void ColFire(); //여우령과 충돌

	BulletData GetBulletData() { return m_BulletData; }
	bool GetShoot();

	D3DXVECTOR3	GetvCenterPos() { return m_vCenterPos; };
	int GetHP() { return m_HP; };

protected:
	D3DXVECTOR3 m_vCenterPos;

	int m_Phase;
	int m_MaxHP;
	int m_HP;

	float m_AttackSpeed;
	float m_MoveSpeed;

	float m_ColTimer;

	BulletData m_BulletData;
	bool m_bShootBullet; //true면 Stage에서 불릿을 만들어줌
	float m_ShootTimer;

	float m_ariveTime; //살아있던 시간

	void ShootBullet(bool toPlayer);
	void ShootBullet(bool toPlayer, int count, float startAngle, float angle);
};