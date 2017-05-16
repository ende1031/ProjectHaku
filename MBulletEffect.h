#pragma once
#include "Object.h"

class MBulletEffect : public Object
{
public:
	MBulletEffect(Texture texture, Sound* sound, D3DXVECTOR3 pos);
	~MBulletEffect();

	void Start(Texture texture, Sound* sound, D3DXVECTOR3 pos);
	void Update(float deltaTime);

	void Animation(int rowNum, int lastNum, float delayTime, float deltaTime);
};