#include "Fire.h"

Fire::Fire()
{
}

Fire::~Fire()
{
}

void Fire::Start(Texture texture1, Texture texture2, Sound* sound, Player* player, int fireNum)
{
	m_pSprite = Device::GetSprite();

	m_bActive = false;
	m_pPlayer = player;
	m_FireNum = fireNum;
	m_vPlayerPos = m_pPlayer->GetvCenterPos();

	if (m_FireNum <= 5) //작은 여우령
	{
		m_CircleRadius = 70.0f;
		m_RotateAngle = 72.0f * fireNum;
		m_pTexture = texture1.GetTexture();
		m_rect = { 0, 0, 50, 50 };
		m_radius = 15;
	}
	else //큰 여우령
	{
		m_CircleRadius = 130.0f;
		m_RotateAngle = 36.0f * (fireNum - 5);
		m_pTexture = texture2.GetTexture();
		m_rect = { 0, 0, 74, 74 };
		m_radius = 25;
	}

	m_AniTimer = 0;
	m_AniNum = 0;

	m_alpha = 0;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_vPos = D3DXVECTOR3(m_vPlayerPos.x, m_vPlayerPos.y, 0);
	m_width = (float)m_rect.right;
	m_height = (float)m_rect.bottom;

	m_vInCirclePos = m_vPos;

	m_vTargetPos = D3DXVECTOR3(0, 0, 0);
	m_bHaveTarget = false;
	m_MoveSpeed = 1500.f;
	m_vMoveVector = D3DXVECTOR3(0, 0, 0);
	m_AttackRange = 550.f;
	m_DistanceToTaget = m_AttackRange;
	m_TurnBack = false;
}

void Fire::Update(float deltaTime)
{
	FadeIn(&m_alpha, deltaTime);
	Animation(3, 6, 0.1f, deltaTime); // int rowNum, int lastNum, float delayTime, float deltaTime

	
	if (m_pPlayer->GetFireCount() >= m_FireNum)
	{
		m_bActive = true;
	}
	else
	{
		m_bActive = false;
		m_alpha = 0;
	}

	m_vPlayerPos = m_pPlayer->GetvCenterPos();
	
	if (m_bActive)
	{
		//발사
		if (m_pPlayer->GetFireAttack(m_FireNum))
		{
			if (!m_TurnBack) //발사
			{
				if (!m_bHaveTarget)
				{
					m_vTargetPos = D3DXVECTOR3(m_vPlayerPos.x + m_AttackRange, m_vPlayerPos.y, 0);
					m_bHaveTarget = true;
					m_TurnBack = false;
				}
				m_DistanceToTaget = D3DXVec3Length(&(m_vTargetPos - GetvCenterPos()));
				if (m_DistanceToTaget > 15.f)
				{
					m_vMoveVector.x = (GetvCenterPos().x - m_vTargetPos.x) / -m_DistanceToTaget * m_MoveSpeed;
					m_vMoveVector.y = (GetvCenterPos().y - m_vTargetPos.y) / -m_DistanceToTaget * m_MoveSpeed;
				}
				else
				{
					m_bHaveTarget = false;
					m_TurnBack = true;
				}
			}
			else if (m_TurnBack) //돌아옴
			{
				SetInCirclePos();
				m_DistanceToTaget = D3DXVec3Length(&(m_vInCirclePos - m_vPos));
				if (m_DistanceToTaget > 10.f)
				{
					m_vMoveVector.x = (m_vPos.x - m_vInCirclePos.x) / -m_DistanceToTaget * m_MoveSpeed;
					m_vMoveVector.y = (m_vPos.y - m_vInCirclePos.y) / -m_DistanceToTaget * m_MoveSpeed;
				}
				else
				{
					m_pPlayer->SetFireAttack(m_FireNum, false);
					m_TurnBack = false;
				}
			}
			Move(m_vMoveVector.x, m_vMoveVector.y, deltaTime);
		}
		else //회전
		{
			RotateCircle();
		}
	}
	else
	{
		if (m_pPlayer->GetFireAttack(m_FireNum))
		{
			m_pPlayer->SetFireAttack(m_FireNum, false);
		}
	}
}

void Fire::RotateCircle()
{
	SetInCirclePos();
	m_vPos.x = m_vInCirclePos.x;
	m_vPos.y = m_vInCirclePos.y;
}

void Fire::SetInCirclePos()
{
	if (m_FireNum <= 5) //작은 여우령
	{
		if (m_pPlayer->GetFireCount() <= 5)
			m_RotateAngle = 360.0f / m_pPlayer->GetFireCount() * (m_FireNum - 1);
		else
			m_RotateAngle = 360.0f / 5 * m_FireNum;
		m_vInCirclePos.x = cos((m_RotateAngle + m_pPlayer->GetFireAngle_Small()) * (D3DX_PI / 180)) * m_CircleRadius + m_vPlayerPos.x - (m_width / 2);
		m_vInCirclePos.y = sin((m_RotateAngle + m_pPlayer->GetFireAngle_Small()) * (D3DX_PI / 180)) * m_CircleRadius + m_vPlayerPos.y - (m_height / 2);
	}
	else if (m_FireNum > 5)//큰 여우령
	{
		m_RotateAngle = 360.0f / (m_pPlayer->GetFireCount() - 5) * (m_FireNum - 6);
		m_vInCirclePos.x = sin((m_RotateAngle + m_pPlayer->GetFireAngle_Big()) * (D3DX_PI / 180)) * m_CircleRadius + m_vPlayerPos.x - (m_width / 2);
		m_vInCirclePos.y = cos((m_RotateAngle + m_pPlayer->GetFireAngle_Big()) * (D3DX_PI / 180)) * m_CircleRadius + m_vPlayerPos.y - (m_height / 2);
	}
}