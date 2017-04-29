#include "TitleBackWhite.h"

TitleBackWhite::TitleBackWhite()
{
}

TitleBackWhite::~TitleBackWhite()
{
}

void TitleBackWhite::Start(Texture texture)
{
	m_bActive = true;

	m_pSprite = Device::GetSprite();
	m_pTexture = texture.GetTexture();

	m_AniTimer = 0;
	m_AniNum = 0;

	m_alpha = 0;
	m_bAlpaUp = true;
	m_alpaTimer = 0;

	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, (LONG)texture.GetWidth(), (LONG)texture.GetHeight() }; //텍스쳐의 크기를 자동으로 받아옴. 직접 수치 입력할 필요 없음.
	m_vPos = D3DXVECTOR3(0, 0, 0);

	m_width = (float)m_rect.right;
	m_height = (float)m_rect.bottom;
}

void TitleBackWhite::Update(float deltaTime)
{
	m_alpaTimer += deltaTime;

	if (m_alpaTimer >= 0.03f)
	{
		if (m_bAlpaUp)
		{
			m_alpha += 5;
			m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
			if (m_alpha > 200)
				m_bAlpaUp = false;
		}
		else
		{
			m_alpha -= 5;
			m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
			if (m_alpha < 20)
				m_bAlpaUp = true;
		}
		m_alpaTimer = 0;
	}
}