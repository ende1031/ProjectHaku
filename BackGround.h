#pragma once
#include "Object.h"

class BackGround : public Object
{
private:
	D3DXVECTOR3 m_vPos2;
public:
	BackGround();
	~BackGround();

	void	Start(Texture texture);
	void	Update(float deltaTime);
	void	Draw();
};

