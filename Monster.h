#pragma once
#include "Object.h"

class MonsterData
{
public:
	float radius;
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

	BulletData GetBulletData() { return m_BulletData; }
	bool GetShoot();

private:
	float m_ColTimer;
	
	MonsterData m_MonsterData;
	int m_HP;
	int m_Pattern;

	BulletData m_BulletData;
	bool m_bShootBullet; //true면 Stage에서 불릿을 만들어줌
	float m_ShootTimer;
	int m_attackCount;

	float m_ariveTime; //살아있던 시간

	bool m_bMoveUp;
	float m_sinAngle;

	void ShootBullet(bool toPlayer);
	void ShootBullet(bool toPlayer, int count, float startAngle, float angle);
};