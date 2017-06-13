#include "StageSelector.h"

StageSelector::StageSelector()
{
}

StageSelector::~StageSelector()
{
}

void StageSelector::Start(Texture bg1, Texture bg2, Texture bg3, Texture bg4, Texture bg5,
	Texture s1, Texture s2, Texture s3, Texture s4, Texture s5, Sound* sound)
{
	m_bActive = true;

	m_pSprite = Device::GetSprite();
	m_pSound = sound;
	
	m_pBGTexture[0] = bg1.GetTexture();
	m_pBGTexture[1] = bg2.GetTexture();
	m_pBGTexture[2] = bg3.GetTexture();
	m_pBGTexture[3] = bg4.GetTexture();
	m_pBGTexture[4] = bg5.GetTexture();

	m_pStageTexture[0] = s1.GetTexture();
	m_pStageTexture[1] = s2.GetTexture();
	m_pStageTexture[2] = s3.GetTexture();
	m_pStageTexture[3] = s4.GetTexture();
	m_pStageTexture[4] = s5.GetTexture();

	m_AniTimer = 0;
	m_AniNum = 0;

	m_alpha = 0;
	m_color = D3DCOLOR_ARGB(m_alpha, 255, 255, 255);
	m_rect = { 0, 0, 960, 540 };
	m_vPos = D3DXVECTOR3(0, 0, 0);
	m_width = (float)m_rect.right;
	m_height = (float)m_rect.bottom;

	for (int i = 0; i < 5; i++)
	{
		m_vStagePos[i] = D3DXVECTOR3(i * 660, 0, 0);
	}

	m_StageNum = 1;
	m_bMove = false;
	m_MoveSpeed = 7;
}

void StageSelector::Update(float deltaTime)
{
	FadeIn(&m_alpha, deltaTime);

	for (int i = 1; i < 5; i++)
		m_vStagePos[i].x = m_vStagePos[0].x + 660 * i; //스테이지1을 기준으로 660px씩 떨어지게 정렬

	Input();
	if (m_vStagePos[0].x != -660 * (m_StageNum - 1)) //입력을 받았을 때
	{
		m_bMove = true;
		m_vStagePos[0].x += (-660 * (m_StageNum - 1) - m_vStagePos[0].x) * m_MoveSpeed * deltaTime;
		if (fabs(-660 * (m_StageNum - 1) - m_vStagePos[0].x) < 3.0f) //일정 범위 안에 들어가면 멈춤
		{
			m_vStagePos[0].x = - 660 * (m_StageNum - 1);
		}
	}
	else
	{
		m_bMove = false;
	}
}

void StageSelector::Input()
{
	if (KeyInput(VK_LEFT) && m_StageNum > 1)
	{
		m_StageNum--;
		m_pSound->PlaySE("Sound/Button.mp3");
	}
	if (KeyInput(VK_RIGHT) && m_StageNum < 5)
	{
		m_StageNum++;
		m_pSound->PlaySE("Sound/Button.mp3");
	}
}

void StageSelector::Draw()
{
	if (m_bActive)
	{
		//배경 그리기
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pSprite->Draw(m_pBGTexture[0], &m_rect, NULL, &m_vPos, m_color);
		m_pSprite->End();

		//스테이지 오브젝트 그리기
		for (int i = 0; i < 5; i++)
		{
			m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
			m_pSprite->Draw(m_pStageTexture[i], &m_rect, NULL, &m_vStagePos[i], m_color);
			m_pSprite->End();
		}
	}
}