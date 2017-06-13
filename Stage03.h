#pragma once
#include "Stage.h"
#include "Boss03.h"

class Stage03 : public Stage
{
public:
	Stage03();
	~Stage03();

	void Start(Sound* sound);
	void Update(float deltaTime);
	void Draw();

private:

	Texture m_tPlayer;
	Texture m_tFire_Small;
	Texture m_tFire_Big;

	Texture m_tMonster01;
	Texture m_tMonster02;
	Texture m_tMonster03;
	Texture m_tBoss;

	BackGround m_BackGround01;
	BackGround m_BackGround02;
	BackGround m_BackGround03;
	Texture m_tBackGround01;
	Texture m_tBackGround02;
	Texture m_tBackGround03;
};

