#pragma once
#include "Object.h"

class TitleLogo : public Object
{
public:
	TitleLogo();
	~TitleLogo();

	void	Update(float deltaTime);
	void	Start(Texture texture);
};

