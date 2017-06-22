#include "SelectStage.h"

SelectStage::SelectStage()
{
	cout << "스테이지 선택 화면" << endl;
}

SelectStage::~SelectStage()
{
}

void SelectStage::Start(Sound* sound)
{
	m_bChangeScene = false;
	m_SceneTime = 0;

	m_pSound = sound;
	m_pSound->Stop();

	//텍스쳐 초기화
	m_tTitle.Start(L"Image/SelectStage/title.png");
	m_tSSBG1.Start(L"Image/SelectStage/BG1.png");
	m_tSSBG2.Start(L"Image/SelectStage/BG2.png");
	m_tSSBG3.Start(L"Image/SelectStage/BG3.png");
	m_tSSBG4.Start(L"Image/SelectStage/BG4.png");
	m_tSSBG5.Start(L"Image/SelectStage/BG5.png");
	m_tSS1.Start(L"Image/SelectStage/Stage1.png");
	m_tSS2.Start(L"Image/SelectStage/Stage2.png");
	m_tSS3.Start(L"Image/SelectStage/Stage3.png");
	m_tSS4.Start(L"Image/SelectStage/Stage4.png");
	m_tSS5.Start(L"Image/SelectStage/Stage5.png");
	m_tKey.Start(L"Image/SelectStage/key.png");

	//오브젝트 초기화
	m_Title.Start(m_tTitle);
	m_StageSelector.Start(m_tSSBG1, m_tSSBG2, m_tSSBG3, m_tSSBG4, m_tSSBG5,
		m_tSS1, m_tSS2, m_tSS3, m_tSS4, m_tSS5, m_pSound);
	m_Key.Start(m_tKey);

	m_pSound->PlayBGM("Sound/SelectStage.mp3");
}

void SelectStage::Update(float deltaTime)
{
	m_Title.Update(deltaTime);
	m_StageSelector.Update(deltaTime);
	m_Key.Update(deltaTime);

	if (KeyInput(VK_RETURN) || KeyInput(VK_SPACE))
	{
		if (m_StageSelector.GetIsMove() == false)
		{
			switch (m_StageSelector.GetStageNum())
			{
			case 1:
				ChangeScene(sStage1);
				break;
			case 2:
				ChangeScene(sStage2);
				break;
			case 3:
				ChangeScene(sStage3);
				break;
			case 4:
				ChangeScene(sStage4);
				break;
			case 5:
				ChangeScene(sStage5);
				break;
			}
		}
	}

	if (KeyInput(VK_ESCAPE))
	{
		ChangeScene(sMainMenu);
	}
}

void SelectStage::Draw()
{
	m_StageSelector.Draw();
	m_Title.Draw();
	m_Key.Draw();
}
