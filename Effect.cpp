#include "Effect.h"

Effect::Effect(Texture texture, Sound* sound, D3DXVECTOR3 pos)
{
	Start(texture, sound, pos);
}

Effect::~Effect()
{
}

void Effect::Start(Texture texture, Sound* sound, D3DXVECTOR3 pos)
{
	m_bActive = true;

	m_pSound = sound;
	m_pSprite = Device::GetSprite();
	m_pTexture = texture.GetTexture();

	m_AniTimer = 0;
	m_AniNum = 0;

	m_alpha = 255;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, 164, 155 };

	m_width = (float)m_rect.right;
	m_height = (float)m_rect.bottom;

	m_vPos = D3DXVECTOR3(pos.x - m_width / 2, pos.y - m_height / 2, 0);

	m_pSound->PlaySE("Sound/MonsterHit.mp3");
}

void Effect::Update(float deltaTime)
{
	if (m_bActive)
	{
		Animation(3, 5, 0.03f, deltaTime);
	}
}

void Effect::Animation(int rowNum, int lastNum, float delayTime, float deltaTime)
{
	m_AniTimer += deltaTime;

	if (m_AniTimer > delayTime)
	{
		m_rect.left = (LONG)m_width * (m_AniNum % rowNum);
		m_rect.top = (LONG)m_height * (m_AniNum / rowNum);
		m_rect.right = (LONG)m_width * (m_AniNum % rowNum + 1);
		m_rect.bottom = (LONG)m_height * (m_AniNum / rowNum + 1);

		m_AniNum++;
		m_AniTimer = 0;
		if (m_AniNum == lastNum)
			m_bActive = false; //애니메이션 재생 후 제거
	}
}