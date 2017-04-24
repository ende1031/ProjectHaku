#include "TitleMenuArrow.h"

TitleMenuArrow::TitleMenuArrow()
{
}

TitleMenuArrow::~TitleMenuArrow()
{
}

void TitleMenuArrow::Start(Texture tecture)
{
	m_pSprite = Device::GetSprite();
	m_pTexture = tecture.GetTexture();

	m_AniTimer = 0;
	m_AniNum = 0;

	m_alpha = 0;
	m_bAlpaUp = true;
	m_alpaTimer = 0;

	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, (LONG)tecture.GetWidth(), (LONG)tecture.GetHeight() }; //텍스쳐의 크기를 자동으로 받아옴. 직접 수치 입력할 필요 없음.
	m_vPos = D3DXVECTOR3(184, 424, 0);

	m_width = m_rect.right;
	m_height = m_rect.bottom;
}

void TitleMenuArrow::Update(float deltaTime)
{
	m_alpaTimer += deltaTime;

	if (m_alpaTimer >= 0.02f)
	{
		if (m_bAlpaUp)
		{
			m_alpha += 10;
			m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
			if (m_alpha > 240)
				m_bAlpaUp = false;
		}
		else
		{
			m_alpha -= 10;
			m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
			if (m_alpha < 50)
				m_bAlpaUp = true;
		}
		m_alpaTimer = 0;
	}
}