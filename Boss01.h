#pragma once
#include "Boss.h"

class Boss01 : public Boss
{
public:
	Boss01();
	~Boss01();

	void Start(Texture texture, Sound* sound);
	void Update(float deltaTime);

private:
	void Phase01(float deltaTime);
};