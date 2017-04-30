#pragma once
#include "Object.h"

class TitleMenu : public Object
{
public:
	TitleMenu();
	~TitleMenu();

	void	Update(float deltaTime);
	void	Start(Texture texture, Sound* sound);

	int		GetMenuNum() { return m_iMenuNum; }
	void 	SetMenuNum(int num) { m_iMenuNum = num; }

private:
	int m_iMenuNum; // 0:게임시작, 1:게임종료, 2:조작방법

	void Input();
};

