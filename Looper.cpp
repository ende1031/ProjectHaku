#include "Looper.h"

Looper::Looper()
{
}


Looper::~Looper()
{
}

void Looper::Start()
{
	m_Sound.Start(); //사운드엔진 초기화

	SetScene(sMainMenu);//게임을 처음 시작하면 메인메뉴 초기화
}

void Looper::Update(float deltaTime)
{
	if (m_pScene->GetChangeScene() == false)
	{
		m_pScene->Update(deltaTime);
	}
	else
	{
		SetScene(m_pScene->GetNextScene());
	}
	Render();
}

void Looper::Render()
{
	if (NULL == g_pDevice)
		return;

	// 백버퍼를 검은색으로
	Device::GetDevice()->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	if (SUCCEEDED(Device::GetDevice()->BeginScene())) // 렌더링 시작
	{
		m_pScene->Draw();
		Device::GetDevice()->EndScene(); // 렌더링 끝
	}

	//백버퍼를 보이는 화면으로
	Device::GetDevice()->Present(NULL, NULL, NULL, NULL);
}

void Looper::SetScene(int Scene)
{
	//스테이지 변경
	m_iScene = Scene;

	//스테이지 초기화
	switch (m_iScene)
	{
	case sMainMenu:
		m_pScene = new MainMenu;
		break;
	case sHowToPlay:
		m_pScene = new HowToPlay;
		break;
	case sStage1:
		m_pScene = new Stage01;
		break;
	case sStage2:
		//
		break;
	}
	m_pScene->Start(&m_Sound);
}