#include "Stage02.h"

Stage02::Stage02()
{
	cout << "스테이지2에 입장했습니다." << endl;
}

Stage02::~Stage02()
{
}

void Stage02::Start(Sound* sound)
{
	m_bChangeScene = false;
	m_SceneTime = 0;
	m_MonsterCounter = 0;
	m_bAppearBoss = false;
	m_bGameOverSE = false;
	m_bStageClearSE = false;
	m_bClear = false;

	m_pSound = sound;
	m_pSound->Stop();
	m_pSound->PlayBGM("Sound/Stage01.mp3");

	m_tBackGround01.Start(L"Image/Stage02/BackGround01.png");
	m_tBackGround02.Start(L"Image/Stage02/BackGround02.png");
	m_tBackGround03.Start(L"Image/Stage02/BackGround03.png");

	m_BackGround01.Start(m_tBackGround01, 250.f);
	m_BackGround02.Start(m_tBackGround02, 200.f);
	m_BackGround03.Start(m_tBackGround03, 150.f);

	m_tPlayer.Start(L"Image/Player.png");
	m_Player.Start(m_tPlayer, m_pSound);

	m_tFire_Small.Start(L"Image/FireSmall.png");
	m_tFire_Big.Start(L"Image/FireBig.png");
	for (int i = 1; i <= 15; i++)
		m_Fire[i - 1].Start(m_tFire_Small, m_tFire_Big, m_pSound, &m_Player, i);

	m_tMonster01.Start(L"Image/Stage02/Monster01.png");
	m_tMonster02.Start(L"Image/Stage02/Monster02.png");
	m_tMonster03.Start(L"Image/Stage02/Monster03.png");
	m_tBoss.Start(L"Image/Stage02/Boss.png");
	m_tMonsterBullet.Start(L"Image/MonsterBullet.png");

	m_tEffect.Start(L"Image/FireEffect.png");
	m_tMEffect.Start(L"Image/BulletEffect.png");

	m_tBarBG.Start(L"Image/BarBG.png");
	m_tBar.Start(L"Image/Bar.png");
	m_Bar.Start(m_tBarBG, m_tBar);

	m_tGameOver.Start(L"Image/GameOver.png");
	m_GameOver.Start(m_tGameOver);

	m_tStageClear.Start(L"Image/Clear.png");
	m_tStageClearLight.Start(L"Image/ClearLight.png");
	m_StageClear.Start(m_tStageClear, m_tStageClearLight);

	//radius, rowNum, lastNum, maxHP, attackSpeed, moveSpeed
	m_MonsterData01 = { 35.0f, 2, 2, 4, 0.5f, 10.0f };
	m_MonsterData02 = { 35.0f, 3, 6, 4, 0.5f, 10.0f };
	m_MonsterData03 = { 40.0f, 3, 7, 4, 0.5f, 10.0f };

	LoadMonsters("Data/Stage02Monsters.txt");

	m_pBoss = new Boss02;
}

void Stage02::Update(float deltaTime)
{
	m_SceneTime += deltaTime;

	if (m_Player.GetFireCount() > 0)
	{
		m_BackGround01.Update(deltaTime);
		m_BackGround02.Update(deltaTime);
		m_BackGround03.Update(deltaTime);

		m_Player.Update(deltaTime);

		for (int i = 0; i < 15; i++)
			m_Fire[i].Update(deltaTime);

		if (m_bAppearBoss)
			dynamic_cast<Boss02*>(m_pBoss)->Update(deltaTime);

		UpdateMonster(deltaTime); //몬스터 전체 Update
		UpdateBullet(deltaTime);
		UpdateEffect(deltaTime);
		UpdateMEffect(deltaTime);

		m_Bar.Update(deltaTime, m_Player.GetPoint());

		CheckMonsterShoot();
		Collision();

		if (m_SceneTime > m_MonsterFileData[m_MonsterCounter].time && m_MonsterDataLine > m_MonsterCounter)
		{
			D3DXVECTOR3 temppos = { 800,250,0 };
			switch (m_MonsterFileData[m_MonsterCounter].type)
			{
			case 0: //보스
				dynamic_cast<Boss02*>(m_pBoss)->Start(m_tBoss, m_pSound);
				m_bAppearBoss = true;
				break;
			case 1:
				AddMonster(new Monster(m_tMonster01, m_pSound, m_MonsterFileData[m_MonsterCounter].pattern, m_MonsterData01));
				break;
			case 2:
				AddMonster(new Monster(m_tMonster02, m_pSound, m_MonsterFileData[m_MonsterCounter].pattern, m_MonsterData02));
				break;
			case 3:
				AddMonster(new Monster(m_tMonster03, m_pSound, m_MonsterFileData[m_MonsterCounter].pattern, m_MonsterData03));
				break;
			}
			m_MonsterCounter++;
		}

		if (KeyInput(VK_ESCAPE))
		{
			ChangeScene(sMainMenu);
		}
	}
	else
	{
		if (!m_bGameOverSE)
		{
			m_pSound->Stop();
			m_pSound->PlaySE("Sound/GameOver.mp3");
			m_bGameOverSE = true;
		}
		m_GameOver.Update(deltaTime);
		if (KeyInput(VK_RETURN) || KeyInput(VK_SPACE))
		{
			ChangeScene(sMainMenu);
		}
	}

	if (m_bAppearBoss)
	{
		if (m_pBoss->GetHP() <= 0)
		{
			if (!m_bStageClearSE)
			{
				m_pSound->Stop();
				m_pSound->PlaySE("Sound/Clear.mp3");
				m_bStageClearSE = true;
				m_bClear = true;
				m_Player.SetCanInput(false);
			}
			m_StageClear.Update(deltaTime);
			if (KeyInput(VK_RETURN) || KeyInput(VK_SPACE))
			{
				ChangeScene(sStage3);
			}
		}
	}
}

void Stage02::Draw()
{
	m_BackGround03.Draw(); //원경부터 그리기
	m_BackGround02.Draw();
	m_BackGround01.Draw();

	DrawMonster(); //몬스터 전체 Draw

	if (m_bAppearBoss)
		dynamic_cast<Boss02*>(m_pBoss)->Draw();

	if (m_Player.GetFireCount() > 0)
	{
		m_Player.Draw();
	}

	DrawBullet();

	if (m_Player.GetFireCount() > 0)
	{
		for (int i = 14; i >= 0; i--)
			m_Fire[i].Draw();
	}

	DrawEffect();
	DrawMEffect();

	m_Bar.Draw();

	if (m_Player.GetFireCount() <= 0)
	{
		m_GameOver.Draw();
	}

	if (m_bClear)
	{
		m_StageClear.Draw();
	}
}