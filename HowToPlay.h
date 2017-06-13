#pragma once
#include "Scene.h"
#include "Object.h"
#include "TitleBackWhite.h"

class HowToPlay : public Scene
{
private:
	Object m_Background;
	Texture m_tBackground;

	TitleBackWhite m_Light;
	Texture m_tLight;

public:
	HowToPlay();
	~HowToPlay();

	void Start(Sound* sound);
	void Update(float deltaTime);
	void Draw();
};

