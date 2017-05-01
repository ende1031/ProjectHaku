#pragma once

#include "Scene.h"
#include "Background.h"
#include "Player.h"
#include "Fire.h"
#include "Monster.h"

//Stge에서 파일입출력으로 몬스터파일을 저장할 구조체
class MonsterFileData
{
public:
	float time; //몬스터가 나오는 시간
	int type; //몬스터 타입 (1 ~ 2)
	int pattern; //몬스터 패턴 (0 ~ 미정)
};

//모든 스테이지용 씬의 상위 클래스
class Stage : public Scene
{
public:
	Stage();
	~Stage();

	void Collision();

	void AddMonster(Monster* monster); //몬스터를 리스트에 추가
	void UpdateMonster(float deltaTime);
	void DrawMonster();

	void LoadMonsters(const char* mobdata); //몬스터 데이터 불러오기

protected:
	Player m_Player;
	Fire m_Fire[15];

	std::list<Monster*> m_MonsterList;
	std::list<Monster*>* GetMonsterList() { return &m_MonsterList; }

	MonsterFileData *m_MonsterFileData; //몬스터 데이터를 저장하는 구조체 배열
	int m_MonsterCounter; //몇 번째 몬스터가 나올 차례인지
	int m_MonsterDataLine; //txt파일의 총 라인 수

	MonsterData m_MonsterData01;
	MonsterData m_MonsterData02;
	MonsterData m_MonsterData03;
	//BossData m_BossData;
};