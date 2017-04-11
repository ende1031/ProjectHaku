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

	bool				m_bActive;
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
	bool		GetActive()	{ return m_bActive; };
	D3DXVECTOR3	GetvPos()	{ return m_vPos; };
	float		GetRadius()	{ return m_radius; };
	D3DXVECTOR3 GetvCenterPos() { return D3DXVECTOR3(m_vPos.x + (m_width / 2), m_vPos.y + (m_height / 2), 0); };

	//Setter
	void	SetRect(RECT rect) { m_rect = rect; }
	void	SetActive(bool live) { m_bActive = live; };

};

