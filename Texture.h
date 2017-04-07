#pragma once
#include "define.h"
#include "Device.h"

class Texture
{
public:
	Texture();
	~Texture();

	void	Start(LPCTSTR lpszFileName);
	void	CleanUp();

	LPDIRECT3DTEXTURE9	GetTexture(void) { return m_pTexture; }

	long	GetWidth() { return m_Width; };
	long	GetHeight() { return m_Height; };

private:
	LPDIRECT3DTEXTURE9	m_pTexture;

	long m_Width;
	long m_Height;
};

