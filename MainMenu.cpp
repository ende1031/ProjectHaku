#include "MainMenu.h"

MainMenu::MainMenu()
{
	cout << "메인메뉴가 로드되었습니다." << endl;
}

MainMenu::~MainMenu()
{
}

void MainMenu::Start()
{
	m_bChangeScene = false;
	m_SceneTime = 0;

	//텍스쳐 초기화
	m_tBack.Start(L"Image/Title/Back.png");
	m_tBackWhite.Start(L"Image/Title/BackWhite.png");
	m_tBackground.Start(L"Image/Title/Background.png");
	m_tLogo.Start(L"Image/Title/Title.png");
	m_tHaku.Start(L"Image/Title/Haku.png");
	m_tMenu.Start(L"Image/Title/GameMenu.png");
	m_tArrow.Start(L"Image/Title/Arrow.png");
	m_tLight.Start(L"Image/Title/Light.png");

	//오브젝트 초기화
	m_Back.Start(m_tBack);
	m_BackWhite.Start(m_tBackWhite);
	m_Background.Start(m_tBackground);
	m_Logo.Start(m_tLogo);
	m_Haku.Start(m_tHaku);
	m_Menu.Start(m_tMenu);
	m_Arrow.Start(m_tArrow);
	m_Light.Start(m_tLight);
}

void MainMenu::Update(float deltaTime)
{
	m_Back.Update(deltaTime);
	m_BackWhite.Update(deltaTime);
	m_Background.Update(deltaTime);
	m_Logo.Update(deltaTime);
	m_Haku.Update(deltaTime);
	m_Menu.Update(deltaTime);
	m_Arrow.Update(deltaTime);
	m_Light.Update(deltaTime);

	//엔터를 누르면 스테이지 변경
	if (KeyInput(VK_RETURN)) //KeyDown이 아니라 KeyInput인게 중요.
	{
		switch (m_Menu.GetMenuNum())
		{
		case 0:
			ChangeScene(sTestStage);
			break;
		}
	}
}

void MainMenu::Draw()
{
	m_Back.Draw();
	m_BackWhite.Draw();
	m_Background.Draw();
	m_Logo.Draw();
	m_Haku.Draw();
	m_Menu.Draw();
	m_Arrow.Draw();
	m_Light.Draw();
}
