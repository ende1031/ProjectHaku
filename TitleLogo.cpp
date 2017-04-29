#include "TitleLogo.h"

TitleLogo::TitleLogo()
{
}

TitleLogo::~TitleLogo()
{
}

void TitleLogo::Start(Texture texture)
{
	m_bActive = true;

	m_pSprite = Device::GetSprite();
	m_pTexture = texture.GetTexture();

	m_AniTimer = 0;
	m_AniNum = 0;

	m_alpha = 0;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, 410, 410 };
	m_vPos = D3DXVECTOR3(65, 10, 0);

	m_width = (float)m_rect.right;
	m_height = (float)m_rect.bottom;
}

void TitleLogo::Update(float deltaTime)
{
	FadeIn(&m_alpha, deltaTime);
	Animation(3, 9, 0.1f, deltaTime);
}