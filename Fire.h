#pragma once
#include "Player.h"

class Fire : public Object
{
public:
	Fire();
	~Fire();

	void Start(Texture texture1, Texture texture2, Sound* sound, Player* player, int fireNum);
	void Update(float deltaTime);

private:
	Player* m_pPlayer;
	int m_FireNum;
	D3DXVECTOR3 m_vPlayerPos;

	void SetInCirclePos();
	void RotateCircle();
	float m_CircleRadius;
	float m_RotateAngle;
	D3DXVECTOR3 m_vInCirclePos; //원 회전중일때 위치

	D3DXVECTOR3 m_vTargetPos;
	bool m_bHaveTarget; //m_vTargetPos를 받았는지
	float m_DistanceToTaget; //m_vTargetPos까지의 거리;
	float m_AttackRange;
	bool m_TurnBack;

	D3DXVECTOR3 m_vMoveVector;
	float m_MoveSpeed;
};