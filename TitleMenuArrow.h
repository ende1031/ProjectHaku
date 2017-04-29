#pragma once
#include "Object.h"

class TitleMenuArrow : public Object
{
private:
	bool m_bAlpaUp;
	float m_alpaTimer;

public:
	TitleMenuArrow();
	~TitleMenuArrow();

	void	Start(Texture texture);
	void	Update(float deltaTime);
};