#include "Bar.h"

Bar::Bar()
{
}

Bar::~Bar()
{
}

void Bar::Start(Texture BG, Texture Bar)
{
	m_bActive = true;

	m_pSprite = Device::GetSprite();
	m_pTexture = BG.GetTexture();
	m_pTexture2 = Bar.GetTexture();

	m_AniTimer = 0;
	m_AniNum = 0;

	m_alpha = 0;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, (LONG)BG.GetWidth(), (LONG)BG.GetHeight() };
	m_vPos = D3DXVECTOR3(700, 440, 0);

	m_rect2 = { 0, 0, (LONG)Bar.GetWidth(), (LONG)Bar.GetHeight() };
	m_vPos2 = D3DXVECTOR3(726, 440, 0);

	m_width = (float)m_rect.right;
	m_height = (float)m_rect.bottom;

	m_maxPoint = 10;
	m_point = 0;
}

void Bar::Update(float deltaTime, int point)
{
	FadeIn(&m_alpha, deltaTime);
	m_point = point;
	if (m_point > m_maxPoint)
		m_point = m_maxPoint;
	m_rect2.right = 162.0f / m_maxPoint * m_point;
}

void Bar::Draw()
{
	if (m_bActive)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture, &m_rect, NULL, &m_vPos, m_color);
		m_pSprite->End();

		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture2, &m_rect2, NULL, &m_vPos2, m_color);
		m_pSprite->End();
	}
}