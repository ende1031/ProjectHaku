#pragma once
#include "Boss.h"

class Boss05 : public Boss
{
public:
	Boss05();
	~Boss05();

	void Start(Texture texture, Sound* sound);
	void Update(float deltaTime);

private:
	void Phase01(float deltaTime);
	int m_attackCount;
	int m_specialCount;
	float m_specialStartAngle;

	bool m_bMove;
	bool m_bMoveBack;
	bool m_bMoveUp;
	float m_MoveSpeed;
	bool m_bAttackOn;

	int m_pattern;

};

