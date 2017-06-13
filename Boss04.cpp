#include "Boss04.h"

Boss04::Boss04()
{
}

Boss04::~Boss04()
{
}

void Boss04::Start(Texture texture, Sound* sound)
{
	cout << "보스 출현!" << endl;
	m_bActive = true;

	m_pSprite = Device::GetSprite();
	m_pTexture = texture.GetTexture();
	m_pSound = sound;
	m_pSound->Stop();
	m_pSound->PlayBGM("Sound/Boss01.mp3");

	m_AniTimer = 0;
	m_AniNum = 0;
	m_ColTimer = 1.0f;
	m_ariveTime = 0;
	m_bShootBullet = false;
	m_ShootTimer = 0;

	m_alpha = 0;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, 158, 120 };

	m_width = (float)m_rect.right;
	m_height = (float)m_rect.bottom;
	m_radius = 60.0f;

	m_vPos = D3DXVECTOR3(900 - m_width / 2, 270 - m_height / 2, 0);
	m_vCenterPos = D3DXVECTOR3(m_vPos.x + 80.f, m_vPos.y + 61.f, 0);

	m_MaxHP = 100;
	m_HP = m_MaxHP;
	m_Phase = 0;

	m_attackCount = 0;
	m_specialCount = 0;

	m_bMoveBack = false;
	m_bMoveUp = false;
}

void Boss04::Update(float deltaTime)
{
	m_vCenterPos = D3DXVECTOR3(m_vPos.x + 80.f, m_vPos.y + 61.f, 0);

	if (m_bActive)
	{
		m_ariveTime += deltaTime;
		m_ColTimer += deltaTime;
		m_ShootTimer += deltaTime;
		FadeIn(&m_alpha, deltaTime);
		Animation(3, 8, 0.1f, deltaTime);

		if (m_HP <= 0)
			m_bActive = false;

		switch (m_Phase)
		{
		case 0:
			Phase01(deltaTime);
			break;
		}
	}
}

void Boss04::Phase01(float deltaTime)
{
	if (m_bMoveBack)
	{
		Move(50, 0, deltaTime);
		if (m_vCenterPos.x > ScreenSizeX - 100)
			m_bMoveBack = false;
	}
	else
	{
		Move(-50, 0, deltaTime);
		if (m_vCenterPos.x < ScreenSizeX - 300)
			m_bMoveBack = true;
	}

	if (m_bMoveUp)
	{
		Move(0, -100, deltaTime);
		if (m_vCenterPos.y < 100)
			m_bMoveUp = false;
	}
	else
	{
		Move(0, 100, deltaTime);
		if (m_vCenterPos.y > ScreenSizeY - 100)
			m_bMoveUp = true;
	}

	if (m_ariveTime > 1.0f && m_ShootTimer > 0.2f)
	{
		if (m_attackCount > 10)
		{
			ShootBullet(false, 12, 0, 360.0f / 12.0f);
			m_specialCount++;
			if (m_specialCount > 3)
			{
				m_attackCount = 0;
				m_specialCount = 0;
			}
		}
		else
		{
			ShootBullet(true);
			m_attackCount++;
		}
		m_ShootTimer = 0;
	}
}