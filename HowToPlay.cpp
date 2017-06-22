#include "HowToPlay.h"

HowToPlay::HowToPlay()
{
	cout << "조작방법 화면" << endl;
}

HowToPlay::~HowToPlay()
{
}

void HowToPlay::Start(Sound* sound)
{
	m_bChangeScene = false;
	m_SceneTime = 0;

	m_pSound = sound;
	m_pSound->Stop();

	//텍스쳐 초기화
	m_tBackground.Start(L"Image/HowToPlay.png");
	m_tLight.Start(L"Image/Title/Light.png");

	//오브젝트 초기화
	m_Background.Start(m_tBackground);
	m_Light.Start(m_tLight);

	m_pSound->PlayBGM("Sound/HowToPlay.mp3");
}

void HowToPlay::Update(float deltaTime)
{
	m_Background.Update(deltaTime);
	m_Light.Update(deltaTime);

	//엔터를 누르면 스테이지 변경
	if (KeyInput(VK_RETURN) || KeyInput(VK_SPACE) || KeyInput(VK_ESCAPE))
	{
		ChangeScene(sMainMenu);
	}
}

void HowToPlay::Draw()
{
	m_Background.Draw();
	m_Light.Draw();
}
