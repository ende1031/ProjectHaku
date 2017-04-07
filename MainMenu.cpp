#include "MainMenu.h"

MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::Start()
{
	m_bChangeScene = false;
	m_SceneTime = 0;

	//텍스쳐 초기화
	m_tBG.Start(L"Image/Background.png");

	//오브젝트 초기화
	m_BG.Start(m_tBG);
}

void MainMenu::Update(float deltaTime)
{
	m_BG.Update(deltaTime);

	//엔터를 누르면 스테이지 변경
	if (KeyInput(VK_RETURN)) //KeyDown이 아니라 KeyInput인게 중요.
	{
		ChangeScene(sTestStage);
	}
}

void MainMenu::Draw()
{
	m_BG.Draw();
}
