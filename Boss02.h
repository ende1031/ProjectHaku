#pragma once
#include "Boss.h"

class Boss02 : public Boss
{
public:
	Boss02();
	~Boss02();

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
};

