#pragma once
#include "Object.h"

class MonsterBullet : public Object
{
public:
	MonsterBullet(Texture texture, Sound* sound, D3DXVECTOR3 pos, float angle);
	MonsterBullet(Texture texture, Sound* sound, D3DXVECTOR3 pos, D3DXVECTOR3 target);
	~MonsterBullet();

	void Start(Texture texture, Sound* sound, D3DXVECTOR3 pos, float angle);
	void Start(Texture texture, Sound* sound, D3DXVECTOR3 pos, D3DXVECTOR3 target);
	void Update(float deltaTime);

private:
	float m_Angle;
	D3DXVECTOR2 m_Vector;
	float m_Speed;
	float m_DistanceToTaget;
};