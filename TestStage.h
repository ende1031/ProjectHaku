#pragma once

#include "Scene.h"
#include "Background.h"
#include "Player.h"
#include "Fire.h"

class TestStage : public Scene
{
public:
	TestStage();
	~TestStage();

	void Start();
	void Update(float deltaTime);
	void Draw();

	void CreateMonster(); //몬스터 생성

private:
	BackGround m_BG;
	Texture m_tBG;

	Player m_Player;
	Texture m_tPlayer;

	Fire m_Fire[15];
	Texture m_tFire_Small;
	Texture m_tFire_Big;
};