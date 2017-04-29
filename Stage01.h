#pragma once
#include "Stage.h"

class Stage01 : public Stage
{
public:
	Stage01();
	~Stage01();

	void Start();
	void Update(float deltaTime);
	void Draw();

private:
	Texture m_tPlayer;
	Texture m_tFire_Small;
	Texture m_tFire_Big;

	Texture m_tMonster01;
	Texture m_tMonster02;
	Texture m_tMonster03;

	BackGround m_BackGround01;
	BackGround m_BackGround02;
	BackGround m_BackGround03;
	Texture m_tBackGround01;
	Texture m_tBackGround02;
	Texture m_tBackGround03;
};