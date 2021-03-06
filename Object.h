#pragma once
#include "Device.h"
#include "Texture.h"

class BulletData
{
public:
	bool toPlayer; //true일경우 플레이어를 향해 발사(유도탄은 아님)
	int count; //개수
	float startAngle; //시작 각도
	float angle; //불릿 사이 각도
};

class Object
{
protected:
	Sound*				m_pSound; //사운드엔진 포인터. Looper에 있음.

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

	void	Start(Texture texture);
	void	Start(Texture texture, Sound* sound);
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
	bool		GetOutsideScreen();

	//Setter
	void	SetRect(RECT rect) { m_rect = rect; }
	void	SetPos(D3DXVECTOR3 pos) { m_vPos = pos; }
	void	SetActive(bool live) { m_bActive = live; };

};