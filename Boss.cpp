#include "Boss.h"

Boss::Boss()
{
}

Boss::~Boss()
{
}

void Boss::ColFire()
{
	//if (m_ColTimer > 0.2f)
	{
		cout << "보스 타격" << endl;
		m_HP--;
		m_ColTimer = 0;
	}
}

bool Boss::GetCanCol()
{
	if (m_ColTimer > 0.2f)
	{
		return true;
	}
	else
		return false;
}