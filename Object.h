#pragma once
#include "Device.h"
#include "Texture.h"

class Object
{
protected:
	LPDIRECT3DTEXTURE9	m_pTexture;
	LPD3DXSPRITE		m_pSprite;

	D3DXVECTOR3			m_vPos;
	RECT				m_rect;
	D3DCOLOR			m_color;
	unsigned int		m_alpha;

	bool				m_bDraw;
	float				m_deltaTime;

	float				m_width;
	float				m_height;

	float				m_radius;

	float				m_AniTimer;
	int					m_AniNum;

public:
	Object();
	virtual ~Object();

	void	Start(Texture tecture);
	void	Update(float deltaTime);
	void	Draw();

	void	Animation(int rowNum, int lastNum, float delayTime, float deltaTime);
	void	FadeIn(unsigned int *alpha, float deltaTime);
	void	Move(float x, float y, float deltaTime);

	//Getter
	bool		GetLive() { return m_bDraw; };
	D3DXVECTOR3	GetvPos() { return m_vPos; };
	float		GetRadius() { return m_radius; };

	//Setter
	void	SetRect(RECT rect) { m_rect = rect; }
	void	SetLive(bool live) { m_bDraw = live; };

};

