#include "TestStage.h"

TestStage::TestStage()
{
	cout << "테스트용 씬이 로드되었습니다." << endl;
}

TestStage::~TestStage()
{
}

void TestStage::Start()
{
	m_bChangeScene = false;
	m_SceneTime = 0;

	m_tBackGround[0].Start(L"Image/Stage01/BackGround01.png");
	m_tBackGround[1].Start(L"Image/Stage01/BackGround02.png");
	m_tBackGround[2].Start(L"Image/Stage01/BackGround03.png");
	m_BackGround[0].Start(m_tBackGround[0], 400.f);
	m_BackGround[1].Start(m_tBackGround[1], 300.f);
	m_BackGround[2].Start(m_tBackGround[2], 200.f);

	m_tPlayer.Start(L"Image/Player.png");
	m_Player.Start(m_tPlayer);

	m_tFire_Small.Start(L"Image/Fire_Small.png");
	m_tFire_Big.Start(L"Image/Fire_Big.png");
	for(int i = 1; i <= 15; i++)
		m_Fire[i-1].Start(m_tFire_Small, m_tFire_Big, &m_Player, i);
}

void TestStage::Update(float deltaTime)
{
	for(int i = 0; i < 3; i++)
		m_BackGround[i].Update(deltaTime);
	m_Player.Update(deltaTime);
	for (int i = 0; i < 15; i++)
		m_Fire[i].Update(deltaTime);

	if (KeyInput(VK_ESCAPE))
	{
		ChangeScene(sMainMenu);
	}
}

void TestStage::Draw()
{
	for(int i = 3; i >= 0; i--) //원경부터 그리기
		m_BackGround[i].Draw();
	m_Player.Draw();
	for (int i = 14; i >= 0; i--)
		m_Fire[i].Draw();
}

void TestStage::CreateMonster()
{
	
}