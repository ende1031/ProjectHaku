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
	m_rect = { 0, 0, 106, 82};
	m_vPos = D3DXVECTOR3(150, 250, 0);

	m_width = m_rect.right;
	m_height = m_rect.bottom;

	m_FireCount = 1;
	m_FireRotateSpeed_Small = 200;
	m_FireRotateSpeed_Big = 100;
	m_FireAngle_Small = 0;
	m_FireAngle_Big = 0;
	for (int i = 0; i < 15; i++) m_bFireAttack[i] = false;
	m_AttackSpeed = 0.1f;
	m_AttackSpeedTimer = 0.f;
}

void Player::Update(float deltaTime)
{
	FadeIn(&m_alpha, deltaTime);
	Animation(2, 4, 0.1f, deltaTime);
	FireRotate(deltaTime);

	m_AttackSpeedTimer += deltaTime;

	Input();
}

void Player::Draw()
{
	if (m_bActive)
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
	if (KeyDown(VK_Z))
	{
		Ataack();
	}
	if (KeyDown(VK_X))
	{
		AllAtaack();
	}
	if (KeyInput(VK_A))
	{
		InsertFire(1);
	}
	if (KeyInput(VK_S))
	{
		RemoveFire(1);
	}
}

void Player::InsertFire(int Num)
{
	for (int i = 1; i <= Num; i++)
	{
		if (m_FireCount < 15)
		{
			cout << "여우령 생성" << endl;
			m_FireCount += 1;
		}
		else
			break;
	}
}

void Player::RemoveFire(int Num)
{
	for (int i = 1; i <= Num; i++)
	{
		if (m_FireCount > 0)
		{
			cout << "여우령 삭제" << endl;
			m_FireCount -= 1;
		}
		else
			break;
	}
}

void Player::FireRotate(float deltaTime)
{
	m_FireAngle_Small += m_FireRotateSpeed_Small * deltaTime;
	if (m_FireAngle_Small > 360.f)
		m_FireAngle_Small -= 360.f;
	if (m_FireAngle_Small < 0)
		m_FireAngle_Small += 360.f;

	m_FireAngle_Big += m_FireRotateSpeed_Big * deltaTime;
	if (m_FireAngle_Big > 360.f)
		m_FireAngle_Big -= 360.f;
	if (m_FireAngle_Big < 0)
		m_FireAngle_Big += 360.f;
}

void Player::Ataack()
{
	if (m_AttackSpeedTimer > m_AttackSpeed)
	{
		for (int i = 0; i < 5; i++)
		{
			if (!m_bFireAttack[i])
			{
				cout << "여우령 공격" << endl;
				m_bFireAttack[i] = true;
				m_AttackSpeedTimer = 0;
				break;
			}
		}
	}
}

void Player::AllAtaack()
{
	bool ready = true;
	if (m_AttackSpeedTimer > m_AttackSpeed)
	{
		for (int i = 0; i < m_FireCount; i++)
		{
			if (m_bFireAttack[i] == true)
			{
				ready = false;
				break;
			}
		}
		if (ready)
		{
			for (int i = 0; i < m_FireCount; i++)
			{
				m_bFireAttack[i] = true;
			}
			cout << "여우령 전체 공격" << endl;
			m_AttackSpeedTimer = 0;
		}
	}
}