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

	SetScene(sMainMenu);//게임을 처음 시작하면 메인메뉴로 씬 설정
}

void Looper::Update(float deltaTime)
{
	if (m_pScene->GetChangeScene() == false) //씬 변경이 없을 경우
	{
		m_pScene->Update(deltaTime); //씬 업데이트
	}
	else //씬 변경
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
		//씬 그리기
		m_pScene->Draw();
		Device::GetDevice()->EndScene(); // 렌더링 끝
	}

	//백버퍼를 보이는 화면으로
	Device::GetDevice()->Present(NULL, NULL, NULL, NULL);
}

void Looper::SetScene(int Scene)
{
	//씬 변경
	m_iScene = Scene;

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
		m_pScene = new Stage02;
		break;
	case sStage3:
		m_pScene = new Stage03;
		break;
	case sStage4:
		m_pScene = new Stage04;
		break;
	case sStage5:
		m_pScene = new Stage05;
		break;
	}

	//씬 초기화
	m_pScene->Start(&m_Sound);
}