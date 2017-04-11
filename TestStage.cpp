#include "TestStage.h"

TestStage::TestStage()
{
}

TestStage::~TestStage()
{
}

void TestStage::Start()
{
	m_bChangeScene = false;
	m_SceneTime = 0;

	m_tBG.Start(L"Image/Background2.png");//텍스쳐 초기화
	m_BG.Start(m_tBG);//오브젝트 초기화

	m_tPlayer.Start(L"Image/Player.png");
	m_Player.Start(m_tPlayer);

	m_tFire_Small.Start(L"Image/Fire_Small.png");
	m_tFire_Big.Start(L"Image/Fire_Big.png");
	for(int i = 1; i <= 15; i++)
		m_Fire[i-1].Start(m_tFire_Small, m_tFire_Big, &m_Player, i);
}

void TestStage::Update(float deltaTime)
{
	m_BG.Update(deltaTime);
	m_Player.Update(deltaTime);
	for (int i = 0; i < 15; i++)
		m_Fire[i].Update(deltaTime);

	if (KeyInput(VK_A))
	{
		m_Player.InsertFire(1);
	}
	if (KeyInput(VK_S))
	{
		m_Player.RemoveFire(1);
	}

	if (KeyInput(VK_ESCAPE))
	{
		ChangeScene(sMainMenu);
	}
}

void TestStage::Draw()
{
	m_BG.Draw();
	m_Player.Draw();
	for (int i = 0; i < 15; i++)
		m_Fire[i].Draw();
}

void TestStage::CreateMonster()
{
	
}