#pragma once
#include "Object.h"

class StageSelectArrow : public Object
{
private:
	bool m_bAlpaUp;
	float m_alpaTimer;

public:
	StageSelectArrow();
	~StageSelectArrow();

	void	Start(Texture texture);
	void	Update(float deltaTime);
};