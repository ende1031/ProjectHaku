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
}

void TestStage::Update(float deltaTime)
{
	m_BG.Update(deltaTime);
	m_Player.Update(deltaTime);

	if (KeyInput(VK_ESCAPE))
	{
	ChangeScene(sMainMenu);
	}
}

void TestStage::Draw()
{
	m_BG.Draw();
	m_Player.Draw();
}

void TestStage::CreateMonster()
{
	
}