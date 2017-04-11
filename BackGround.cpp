#include "BackGround.h"

BackGround::BackGround()
{
}

BackGround::~BackGround()
{
}

void BackGround::Start(Texture texture)
{
	m_pSprite = Device::GetSprite();
	m_pTexture = texture.GetTexture();

	m_alpha = 0;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, texture.GetWidth(), texture.GetHeight() };
	m_vPos = D3DXVECTOR3(0, 0, 0);
	m_vPos2 = D3DXVECTOR3((float)m_rect.right, 0, 0);
}

void BackGround::Update(float deltaTime)
{
	FadeIn(&m_alpha, deltaTime);

	Move(-150, 0, deltaTime);
	if (m_vPos2.x <= 0)
	{
		m_vPos.x = m_vPos2.x;
	}
	m_vPos2.x = m_vPos.x + (float)m_rect.right;
}

void BackGround::Draw()
{
	if (m_bActive)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture, &m_rect, NULL, &m_vPos, m_color);
		m_pSprite->End();

		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture, &m_rect, NULL, &m_vPos2, m_color);
		m_pSprite->End();
	}
}