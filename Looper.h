#pragma once
#include "Define.h"

//각 스테이지별 헤더파일 여기에 추가
#include "MainMenu.h"
#include "HowToPlay.h"
#include "SelectStage.h"
#include "Stage01.h"
#include "Stage02.h"
#include "Stage03.h"
#include "Stage04.h"
#include "Stage05.h"

class Looper
{
public:
	Looper();
	~Looper();

	void Start();
	void Update(float deltaTime);
	void Render();

	Sound m_Sound;

	//Setter
	void SetScene(int Scene);

	//Getter
	int GetScene() { return m_iScene; };

private:
	Scene* m_pScene;

	int m_iScene;

};

