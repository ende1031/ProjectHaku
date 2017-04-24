#pragma once
#include "Object.h"

class TitleHaku : public Object
{
public:
	TitleHaku();
	~TitleHaku();

	void	Update(float deltaTime);
	void	Start(Texture tecture);
};

