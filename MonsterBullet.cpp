#include "MonsterBullet.h"

MonsterBullet::MonsterBullet(Texture texture, Sound* sound, D3DXVECTOR3 pos, float angle)
{
	Start(texture, sound, pos, angle);
}

MonsterBullet::MonsterBullet(Texture texture, Sound* sound, D3DXVECTOR3 pos, D3DXVECTOR3 target)
{
	Start(texture, sound, pos, target);
}

MonsterBullet::~MonsterBullet()
{
}

void MonsterBullet::Start(Texture texture, Sound* sound, D3DXVECTOR3 pos, float angle)
{
	m_bActive = true;

	m_pSprite = Device::GetSprite();
	m_pTexture = texture.GetTexture();
	m_pSound = sound;

	m_Angle = angle;

	m_AniTimer = 0;
	m_AniNum = 0;

	m_alpha = 255;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, 35, 35 };
	m_vPos = pos;

	m_width = (float)m_rect.right;
	m_height = (float)m_rect.bottom;
	m_radius = 16.0f;

	m_Speed = 600.0f;
	m_Vector.x = cos(m_Angle * (D3DX_PI / 180)) * m_Speed;
	m_Vector.y = sin(m_Angle * (D3DX_PI / 180)) * m_Speed;
}

void MonsterBullet::Start(Texture texture, Sound* sound, D3DXVECTOR3 pos, D3DXVECTOR3 target)
{
	m_bActive = true;

	m_pSprite = Device::GetSprite();
	m_pTexture = texture.GetTexture();
	m_pSound = sound;

	m_AniTimer = 0;
	m_AniNum = 0;

	m_alpha = 255;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, 35, 35 };
	m_vPos = pos;

	m_width = (float)m_rect.right;
	m_height = (float)m_rect.bottom;
	m_radius = 16.0f;

	m_Speed = 600.0f;
	m_DistanceToTaget = D3DXVec3Length(&(target - m_vPos));
	m_Vector.x = ((target.x - m_vPos.x) / m_DistanceToTaget) * m_Speed;
	m_Vector.y = ((target.y - m_vPos.y) / m_DistanceToTaget) * m_Speed;
}

void MonsterBullet::Update(float deltaTime)
{
	if (m_bActive)
	{
		Move(m_Vector.x, m_Vector.y, deltaTime);

		FadeIn(&m_alpha, deltaTime);
		Animation(2, 4, 0.1f, deltaTime);

		if (GetOutsideScreen())
		{
			cout << "화면 밖으로 나간 불릿 삭제" << endl;
			m_bActive = false;
		}
	}
}