#pragma once
#include "Object.h"

class Player : public Object
{
private:
	void Input(float deltaTime);
	void Ataack();
	void AllAtaack();

	void FireRotate(float deltaTime);
	int m_FireCount;
	float m_FireRotateSpeed_Small;
	float m_FireRotateSpeed_Big;
	float m_FireAngle_Small;
	float m_FireAngle_Big;

	bool m_bFireAttack[15];
	float m_AttackSpeed;
	float m_AttackSpeedTimer;

	float m_ColTimer;

public:
	Player();
	~Player();

	void Start(Texture texture, Sound* sound);
	void Update(float deltaTime);
	void Draw();

	void InsertFire(int Num);
	void RemoveFire(int Num);

	void ColMonster();

	D3DXVECTOR3	GetvCenterPos()		{ return D3DXVECTOR3(m_vPos.x + 65.f, m_vPos.y + 45.f, 0); };
	int		GetFireCount()			{ return m_FireCount; };
	float	GetFireAngle_Small()	{ return m_FireAngle_Small; };
	float	GetFireAngle_Big()		{ return m_FireAngle_Big; };
	bool	GetFireAttack(int num) { return m_bFireAttack[num - 1]; };

	void	SetFireAttack(int num, bool flag) { m_bFireAttack[num - 1] = flag; };
};

