#pragma once
#include "Object.h"

class StageClear : public Object
{
public:
	StageClear();
	~StageClear();

	void	Start(Texture texture, Texture texture2);
	void	Update(float deltaTime);
	void	Draw();

private:
	unsigned int m_alpha2;
	D3DCOLOR m_color2;
	LPDIRECT3DTEXTURE9 m_pTexture2;

	bool m_bAlpaUp;
	float m_alpaTimer;
};

