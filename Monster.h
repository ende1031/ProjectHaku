#pragma once
#include "Object.h"

class MonsterData
{
public:
	float radius;
	float rectRight;
	float rectBottom;
	int rowNum;
	int lastNum;
	int maxHP;
	float attackSpeed;
	float moveSpeed;
};

class Monster : public Object
{
public:
	//Monster() {}
	Monster(Texture texture, Sound* sound, int pattern, MonsterData data);
	~Monster();

	void Start(Texture texture, Sound* sound, int pattern, MonsterData data);
	void Update(float deltaTime);
	int GetHP() { return m_HP; }

	void ColFire(); //여우령과 충돌
	bool GetCanCol();

protected:
	float m_ColTimer;
	
	MonsterData m_MonsterData;
	int m_HP;
	int m_Pattern;

	float m_ariveTime; //살아있던 시간
};