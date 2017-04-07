#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Start(Texture texture)
{
	m_pSprite = Device::GetSprite();
	m_pTexture = texture.GetTexture();

	m_AniTimer = 0;
	m_AniNum = 0;

	m_alpha = 0;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, 106, 82}; //106,82
	m_vPos = D3DXVECTOR3(0, 0, 0);

	m_width = m_rect.right;
	m_height = m_rect.bottom;
}

void Player::Update(float deltaTime)
{
	FadeIn(&m_alpha, deltaTime);
	Animation(2, 4, 0.1f, deltaTime);

	Input();
}

void Player::Draw()
{
	if (m_bDraw)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture, &m_rect, NULL, &m_vPos, m_color);
		m_pSprite->End();
	}
}

void Player::Input()
{
	if (KeyDown(VK_LEFT))
	{
		if (m_vPos.x > -40)
			m_vPos.x -= 5;
	}
	if (KeyDown(VK_RIGHT))
	{
		if (m_vPos.x < ScreenSizeX - m_width)
			m_vPos.x += 5;
	}
	if (KeyDown(VK_UP))
	{
		if (m_vPos.y > 0)
			m_vPos.y -= 5;
	}
	if (KeyDown(VK_DOWN))
	{
		if (m_vPos.y < ScreenSizeY - m_height)
			m_vPos.y += 5;
	}
}