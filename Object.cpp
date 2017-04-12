#include "Object.h"

Object::Object()
{
	m_vPos = D3DXVECTOR3(0, 0, 0);
	m_bActive = true;
}

Object::~Object()
{
}

void Object::Start(Texture tecture)
{
	m_pSprite = Device::GetSprite();
	m_pTexture = tecture.GetTexture();

	m_AniTimer = 0;
	m_AniNum = 0;

	m_alpha = 0;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, (LONG)tecture.GetWidth(), (LONG)tecture.GetHeight() }; //텍스쳐의 크기를 자동으로 받아옴. 직접 수치 입력할 필요 없음.
	m_vPos = D3DXVECTOR3(0, 0, 0);

	m_width = m_rect.right;
	m_height = m_rect.bottom;
}

void Object::Update(float deltaTime)
{
	FadeIn(&m_alpha, deltaTime);
}

void Object::Draw()
{
	if (m_bActive)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pTexture, &m_rect, NULL, &m_vPos, m_color);
		m_pSprite->End();
	}
}

void Object::Move(float x, float y, float deltaTime)
{
	m_vPos.x += x * deltaTime;
	m_vPos.y += y * deltaTime;
}

void Object::Animation(int rowNum, int lastNum, float delayTime, float deltaTime)
{
	m_AniTimer += deltaTime;

	if (m_AniTimer > delayTime)
	{
		m_rect.left = m_width * (m_AniNum % rowNum);
		m_rect.top = m_height * (m_AniNum / rowNum);
		m_rect.right = m_width * (m_AniNum % rowNum + 1);
		m_rect.bottom = m_height * (m_AniNum / rowNum + 1);

		m_AniNum++;
		m_AniTimer = 0;
		m_AniNum %= lastNum;
	}
}

void Object::FadeIn(unsigned int *alpha, float deltaTime)
{
	if (*alpha < 255)
		(*alpha) += 900 * deltaTime;

	if (*alpha >= 255)
		*alpha = 255;

	m_color = D3DCOLOR_ARGB(*alpha, 255, 255, 255);
}