#pragma once

#include <list>
#include "Device.h"
#include "Texture.h"
#include <fstream> //입출력

class Scene
{
protected:
	Sound* m_pSound; //사운드엔진 포인터. Looper에 있음.

	float m_SceneTime;
	bool m_bChangeScene;
	int m_NextScene;

public:
	Scene();
	~Scene();

	virtual void Start(Sound* sound) = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Draw() = 0;

	void ChangeScene(int next);

	//Getter
	bool GetChangeScene() { return m_bChangeScene; }
	int GetNextScene() { return m_NextScene; }
};