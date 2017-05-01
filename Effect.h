#pragma once
#include "Object.h"

class Effect : public Object
{
public:
	Effect(Texture texture, Sound* sound, D3DXVECTOR3 pos);
	~Effect();

	void Start(Texture texture, Sound* sound, D3DXVECTOR3 pos);
	void Update(float deltaTime);

	void Animation(int rowNum, int lastNum, float delayTime, float deltaTime);
};

