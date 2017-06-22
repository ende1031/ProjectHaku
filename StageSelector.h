#pragma once
#include "Object.h"

class StageSelector : public Object
{
public:
	StageSelector();
	~StageSelector();

	void Start(Texture bg1, Texture bg2, Texture bg3, Texture bg4, Texture bg5,
		Texture s1, Texture s2, Texture s3, Texture s4, Texture s5, Sound* sound);
	void Update(float deltaTime);
	void Draw();

	int GetStageNum() { return m_StageNum; }
	bool GetIsMove() { return m_bMove; }

private:
	D3DXVECTOR3			m_vStagePos[5]; //m_vPos는 배경용, 이건 오브젝트용
	LPDIRECT3DTEXTURE9	m_pStageTexture[5];
	LPDIRECT3DTEXTURE9	m_pBGTexture[5];

	D3DCOLOR			m_BGColor[5];
	unsigned int		m_BGAlpha[5];

	int m_StageNum;
	bool m_bMove;
	float m_MoveSpeed;

	void Input();
	void AlphaUp(D3DCOLOR *color, unsigned int *alpha, float deltaTime);
	void AlphaDown(D3DCOLOR *color, unsigned int *alpha, float deltaTime);
};