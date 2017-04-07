#pragma once

#include "Device.h"
#include "Texture.h"
#include <fstream> //입출력

struct MobData
{
	float time;
	int type;
	int pattern;
};

class Scene
{
protected:
	float m_SceneTime;
	bool m_bChangeScene;
	int m_NextScene;

	MobData *m_Mobdata; //몬스터 데이터를 저장하는 구조체 배열
	int m_MobCounter; //몇 번째 몬스터가 나올 차례인지
	int m_MobdataLine; //txt파일의 총 라인 수

public:
	Scene();
	~Scene();

	virtual void Start();
	virtual void Update(float deltaTime);
	virtual void Draw();

	void ChangeScene(int next);

	void LoadMonsters(const char* mobdata); //몬스터 데이터 불러오기

	//Getter
	bool GetChangeScene() { return m_bChangeScene; }
	int GetNextScene() { return m_NextScene; }
};