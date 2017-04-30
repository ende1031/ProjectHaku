#pragma once
#include "Define.h"

//각 스테이지별 헤더파일 여기에 추가
#include "MainMenu.h"
#include "Stage01.h"

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

