#include "Boss05.h"

Boss05::Boss05()
{
}

Boss05::~Boss05()
{
}

void Boss05::Start(Texture texture, Sound* sound)
{
	cout << "보스 출현!" << endl;
	m_bActive = true;

	m_pSprite = Device::GetSprite();
	m_pTexture = texture.GetTexture();
	m_pSound = sound;
	m_pSound->Stop();
	m_pSound->PlayBGM("Sound/Boss05.mp3");

	m_AniTimer = 0;
	m_AniNum = 0;
	m_ColTimer = 1.0f;
	m_ariveTime = 0;
	m_bShootBullet = false;
	m_ShootTimer = 0;

	m_alpha = 0;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, 198, 279 };

	m_width = (float)m_rect.right;
	m_height = (float)m_rect.bottom;
	m_radius = 60.0f;

	m_vPos = D3DXVECTOR3(900 - m_width / 2, 270 - m_height / 2, 0);
	m_vCenterPos = D3DXVECTOR3(m_vPos.x + 89.f, m_vPos.y + 192.f, 0);

	m_MaxHP = 300;
	m_HP = m_MaxHP;
	m_Phase = 0;

	m_attackCount = 0;
	m_specialCount = 0;

	m_bMoveBack = false;
	m_bMoveUp = false;
	m_bMove = true;
	m_pattern = 0;
	m_bAttackOn = true;
	m_specialStartAngle = 0;

	m_MoveSpeed = 300;
}

void Boss05::Update(float deltaTime)
{
	m_vCenterPos = D3DXVECTOR3(m_vPos.x + 89.f, m_vPos.y + 192.f, 0);

	if (m_bActive)
	{
		m_ariveTime += deltaTime;
		m_ColTimer += deltaTime;
		m_ShootTimer += deltaTime;
		FadeIn(&m_alpha, deltaTime);
		Animation(3, 6, 0.1f, deltaTime);

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

void Boss05::Phase01(float deltaTime)
{
	if (m_bMove)
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
			Move(0, -m_MoveSpeed, deltaTime);
			if (m_vCenterPos.y < 100)
				m_bMoveUp = false;
		}
		else
		{
			Move(0, m_MoveSpeed, deltaTime);
			if (m_vCenterPos.y > ScreenSizeY - 100)
				m_bMoveUp = true;
		}
	}
	if (m_ariveTime > 0.5f && m_ShootTimer > 0.1f)
	{
		if (m_attackCount < 20) //패턴1
		{
			m_bMove = true;
			m_MoveSpeed = 300.0f;

			if (m_bAttackOn)
			{
				ShootBullet(false, 3, 170.0f, 10.0f);
				m_bAttackOn = false;
			}
			else
				m_bAttackOn = true;
		}
		else if (m_attackCount >= 20 && m_attackCount < 40) //패턴2
		{
			m_MoveSpeed = 50.0f;
			m_bMove = true;

			ShootBullet(false, 4, m_specialStartAngle, 360.0f / 4.0f);
			m_specialCount++;
			m_specialStartAngle += 10.0f;
			if (m_specialStartAngle >= 360.0f)
				m_specialStartAngle -= 360.0f;
		}
		else if (m_attackCount >= 40 && m_attackCount < 43) //패턴3
		{
			m_bMove = false;
			ShootBullet(false, 50, 0, 360.0f / 50.0f);
		}
		else
			m_attackCount = 0;

		m_attackCount++;
		m_ShootTimer = 0;
	}
}