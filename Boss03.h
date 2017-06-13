#pragma once
#include "Boss.h"

class Boss03 : public Boss
{
public:
	Boss03();
	~Boss03();

	void Start(Texture texture, Sound* sound);
	void Update(float deltaTime);

private:
	void Phase01(float deltaTime);
	int m_attackCount;
	int m_specialCount;

	bool m_bMoveBack;
	bool m_bMoveUp;
};

