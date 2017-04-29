#include "TitleMenu.h"

TitleMenu::TitleMenu()
{
}

TitleMenu::~TitleMenu()
{
}

void TitleMenu::Start(Texture texture)
{
	m_bActive = true;

	m_pSprite = Device::GetSprite();
	m_pTexture = texture.GetTexture();

	m_AniTimer = 0;
	m_AniNum = 0;

	m_alpha = 0;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 144, 600, 216 };
	m_vPos = D3DXVECTOR3(184, 424, 0);

	m_width = (float)m_rect.right;
	m_height = (float)m_rect.bottom;

	m_iMenuNum = 0;
}

void TitleMenu::Update(float deltaTime)
{
	Input();
	switch (m_iMenuNum)
	{
	case 0:
		m_rect = { 0, 144, 600, 216 };
		break;
	case 1:
		m_rect = { 0, 72, 600, 144 };
		break;
	case 2:
		m_rect = { 0, 0, 600, 72 };
		break;
	}
	FadeIn(&m_alpha, deltaTime);
}

void TitleMenu::Input()
{
	if (KeyInput(VK_RIGHT))
	{
		m_iMenuNum += 1;
		if (m_iMenuNum >= 3)
			m_iMenuNum = 0;
	}
	if (KeyInput(VK_LEFT))
	{
		m_iMenuNum -= 1;
		if (m_iMenuNum < 0)
			m_iMenuNum = 2;
	}
}