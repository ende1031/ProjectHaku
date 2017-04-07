#pragma once

#include "Scene.h"
#include "Object.h"

class MainMenu : public Scene
{
private:
	Object m_BG;
	Texture m_tBG;

public:
	MainMenu();
	~MainMenu();

	void Start();
	void Update(float deltaTime);
	void Draw();
};