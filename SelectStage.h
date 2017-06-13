#pragma once
#include "Scene.h"
#include "Object.h"
#include "StageSelector.h"

class SelectStage : public Scene
{
public:
	SelectStage();
	~SelectStage();

	void Start(Sound* sound);
	void Update(float deltaTime);
	void Draw();

private:
	Object m_Title;
	Texture m_tTitle;

	StageSelector m_StageSelector;
	Texture m_tSSBG1;
	Texture m_tSSBG2;
	Texture m_tSSBG3;
	Texture m_tSSBG4;
	Texture m_tSSBG5;
	Texture m_tSS1;
	Texture m_tSS2;
	Texture m_tSS3;
	Texture m_tSS4;
	Texture m_tSS5;
};

