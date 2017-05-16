#include "StageClear.h"

StageClear::StageClear()
{
}

StageClear::~StageClear()
{
}

void StageClear::Start(Texture texture, Texture texture2)
{
	m_bActive = true;

	m_pSprite = Device::GetSprite();
	m_pTexture = texture.GetTexture(); //밑배경
	m_pTexture2 = texture2.GetTexture(); //라이트

	m_AniTimer = 0;
	m_AniNum = 0;
	m_alpaTimer = 0;

	m_alpha = 0;
	m_alpha2 = 0;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_color2 = D3DCOLOR_ARGB(m_alpha2, 255, 255, 255);
	m_rect = { 0, 0, (LONG)texture.GetWidth(), (LONG)texture.GetHeight() };
	m_vPos = D3DXVECTOR3(0, 0, 0);

	m_width = (float)m_rect.right;
	m_height = (float)m_rect.bottom;

	m_bAlpaUp = true;
}

void StageClear::Update(float deltaTime)
{
	FadeIn(&m_alpha, deltaTime);

	m_alpaTimer += deltaTime;

	if (m_alpaTimer >= 0.02f)
	{
		if (m_bAlpaUp)
		{
			m_alpha2 += 10;
			m_color2 = D3DCOLOR_ARGB(m_alpha2, 255, 255, 255);
			if (m_alpha2 > 180)
				m_bAlpaUp = false;
		}
		else
		{
			m_alpha2 -= 10;
			m_color2 = D3DCOLOR_ARGB(m_alpha2, 255, 255, 255);
			if (m_alpha2 < 30)
				m_bAlpaUp = true;
		}
		m_alpaTimer = 0;
	}
}

void StageClear::Draw()
{
	if (m_bActive)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture, &m_rect, NULL, &m_vPos, m_color);
		m_pSprite->End();

		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture2, &m_rect, NULL, &m_vPos, m_color2);
		m_pSprite->End();
	}
}