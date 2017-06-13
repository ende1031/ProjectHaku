#include "Texture.h"


Texture::Texture()
{
}


Texture::~Texture()
{
}

void Texture::Start(LPCTSTR	lpszFileName)
{
	D3DXIMAGE_INFO info;
	D3DXGetImageInfoFromFile(lpszFileName, &info);

	//텍스쳐로부터 가로세로 픽셀 값을 받아옴
	m_Width = info.Width;
	m_Height = info.Height;

	//알파값이 들어간 텍스쳐 그리기
	D3DXCreateTextureFromFileEx(Device::GetDevice(), lpszFileName, m_Width, m_Height,
		1, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, 0, &info, NULL, &m_pTexture);
}

void Texture::CleanUp()
{
	SAFE_RELEASE(m_pTexture);
}