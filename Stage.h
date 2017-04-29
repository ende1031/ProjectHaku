#pragma once

#include "Scene.h"
#include "Background.h"
#include "Player.h"
#include "Fire.h"
#include "Monster.h"

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

protected:
	Player m_Player;
	Fire m_Fire[15];

	std::list<Monster*> m_MonsterList;
	std::list<Monster*>* GetMonsterList() { return &m_MonsterList; }
};