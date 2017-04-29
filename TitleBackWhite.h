#pragma once
#include "Object.h"

class TitleBackWhite : public Object
{
private:
	bool m_bAlpaUp;
	float m_alpaTimer;

public:
	TitleBackWhite();
	~TitleBackWhite();

	void	Start(Texture texture);
	void	Update(float deltaTime);
};

