#include "Stage01.h"

Stage01::Stage01()
{
	cout << "스테이지1이 로드되었습니다." << endl;
}

Stage01::~Stage01()
{
}

void Stage01::Start()
{
	m_bChangeScene = false;
	m_SceneTime = 0;

	m_tBackGround01.Start(L"Image/Stage01/BackGround01.png");
	m_tBackGround02.Start(L"Image/Stage01/BackGround02.png");
	m_tBackGround03.Start(L"Image/Stage01/BackGround03.png");

	m_BackGround01.Start(m_tBackGround01, 250.f);
	m_BackGround02.Start(m_tBackGround02, 200.f);
	m_BackGround03.Start(m_tBackGround03, 150.f);

	m_tPlayer.Start(L"Image/Player.png");
	m_Player.Start(m_tPlayer);

	m_tFire_Small.Start(L"Image/Fire_Small.png");
	m_tFire_Big.Start(L"Image/Fire_Big.png");
	for (int i = 1; i <= 15; i++)
		m_Fire[i - 1].Start(m_tFire_Small, m_tFire_Big, &m_Player, i);

	m_tMonster01.Start(L"Image/Stage01/Monster01.png");
	m_tMonster02.Start(L"Image/Stage01/Monster02.png");
	m_tMonster03.Start(L"Image/Stage01/Monster03.png");
}

void Stage01::Update(float deltaTime)
{
	m_SceneTime += deltaTime;

	m_BackGround01.Update(deltaTime);
	m_BackGround02.Update(deltaTime);
	m_BackGround03.Update(deltaTime);

	m_Player.Update(deltaTime);

	for (int i = 0; i < 15; i++)
		m_Fire[i].Update(deltaTime);

	UpdateMonster(deltaTime); //몬스터 전체 Update

	if (m_SceneTime > 0.5f)
	{
		//pattern, radius, rectRight, rectBottom, rowNum, lastNum, maxHP, attackSpeed, moveSpeed
		MonsterData temp = { 0, 35.0f, 65.0f, 97.0f, 2, 2, 1, 0.5f, 10.0f };
		AddMonster(new Monster(m_tMonster01, temp));
		temp = { 1, 35.0f, 65.0f, 97.0f, 2, 2, 1, 0.5f, 10.0f };
		AddMonster(new Monster(m_tMonster02, temp));
		temp = { 2, 40.0f, 97.0f, 93.0f, 6, 6, 1, 0.5f, 10.0f };
		AddMonster(new Monster(m_tMonster03, temp));
		m_SceneTime = 0;
	}

	Collision();

	if (KeyInput(VK_ESCAPE))
	{
		ChangeScene(sMainMenu);
	}
}

void Stage01::Draw()
{
	m_BackGround03.Draw(); //원경부터 그리기
	m_BackGround02.Draw();
	m_BackGround01.Draw();

	DrawMonster(); //몬스터 전체 Draw

	m_Player.Draw();

	for (int i = 14; i >= 0; i--)
		m_Fire[i].Draw();
}