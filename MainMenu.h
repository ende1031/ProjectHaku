#pragma once

#include "Scene.h"
#include "Object.h"
#include "TitleBackWhite.h"
#include "TitleLogo.h"
#include "TitleHaku.h"
#include "TitleMenu.h"
#include "TitleMenuArrow.h"

class MainMenu : public Scene
{
private:
	Object m_Back;
	Texture m_tBack;

	Object m_Background;
	Texture m_tBackground;

	TitleBackWhite m_BackWhite;
	Texture m_tBackWhite;

	TitleLogo m_Logo;
	Texture m_tLogo;

	TitleBackWhite m_Light;
	Texture m_tLight;

	TitleHaku m_Haku;
	Texture m_tHaku;

	TitleMenu m_Menu;
	Texture m_tMenu;

	TitleMenuArrow m_Arrow;
	Texture m_tArrow;

public:
	MainMenu();
	~MainMenu();

	void Start();
	void Update(float deltaTime);
	void Draw();
};