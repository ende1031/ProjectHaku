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

	D3DXVECTOR3	GetvCenterPos() { return m_vCenterPos; };

protected:
	D3DXVECTOR3 m_vCenterPos;

	int m_Phase;
	int m_MaxHP;
	int m_HP;

	float m_AttackSpeed;
	float m_MoveSpeed;

	float m_ColTimer;
};