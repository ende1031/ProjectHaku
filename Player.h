#pragma once
#include "Object.h"

class Player : public Object
{
public:
	Player();
	~Player();

	void Start(Texture texture);
	void Update(float deltaTime);
	void Draw();

private:
	void Input();
};

