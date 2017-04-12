#pragma once
#include "Object.h"

class BackGround : public Object
{
private:
	D3DXVECTOR3 m_vPos2;
	float m_MoveSpeed;

public:
	BackGround();
	~BackGround();

	void	Start(Texture texture, float speed);
	void	Update(float deltaTime);
	void	Draw();
};