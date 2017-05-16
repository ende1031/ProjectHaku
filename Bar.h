#pragma once
#include "Object.h"

class Bar : public Object
{
public:
	Bar();
	~Bar();

	void	Start(Texture BG, Texture Bar);
	void	Update(float deltaTime, int point);
	void	Draw();

private:
	LPDIRECT3DTEXTURE9	m_pTexture2;
	D3DXVECTOR3			m_vPos2;
	RECT				m_rect2;

	int m_maxPoint;
	int m_point;
};

