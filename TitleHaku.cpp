#include "TitleHaku.h"

TitleHaku::TitleHaku()
{
}

TitleHaku::~TitleHaku()
{
}

void TitleHaku::Start(Texture tecture)
{
	m_pSprite = Device::GetSprite();
	m_pTexture = tecture.GetTexture();

	m_AniTimer = 0;
	m_AniNum = 0;

	m_alpha = 0;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, 400, 384 };
	m_vPos = D3DXVECTOR3(577, 112, 0);

	m_width = m_rect.right;
	m_height = m_rect.bottom;
}

void TitleHaku::Update(float deltaTime)
{
	FadeIn(&m_alpha, deltaTime);
	Animation(5, 16, 0.1f, deltaTime);
}