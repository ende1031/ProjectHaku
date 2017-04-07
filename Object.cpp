#include "Object.h"

Object::Object()
{
	m_vPos = D3DXVECTOR3(0, 0, 0);
	m_bDraw = true;
}

Object::~Object()
{
}

void Object::Start(Texture t1)
{
	m_pSprite = Device::GetSprite();
	m_pTexture = t1.GetTexture();

	m_alpha = 0;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, (LONG)t1.GetWidth(), (LONG)t1.GetHeight() }; //텍스쳐의 크기를 자동으로 받아옴. 직접 수치 입력할 필요 없음.
	m_vPos = D3DXVECTOR3(0, 0, 0);
}

void Object::Update(float deltaTime)
{
	FadeIn(&m_alpha, deltaTime);
}

void Object::Draw()
{
	if (m_bDraw)
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

void Object::Animation(float *timer, int *aniNum, int width, int height, int rowNum, int lastNum, float delayTime)
{
	if (*timer > delayTime)
	{
		m_rect.left = width * (*aniNum % rowNum);
		m_rect.top = height * (*aniNum / rowNum);
		m_rect.right = width * (*aniNum % rowNum + 1);
		m_rect.bottom = height * (*aniNum / rowNum + 1);

		(*aniNum)++;
		*timer = 0;
		*aniNum %= lastNum;
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