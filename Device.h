#pragma once
#include "Define.h"

class Device
{
public:
	static Device* GetInstance();

	Device() : m_pD3D(NULL), m_pd3dDevice(NULL) { };
	virtual ~Device();

	HRESULT Start(HWND hWnd, UINT Width, UINT Height);

	static HWND GetHWND() { return GetInstance()->m_hWnd; };
	static LPDIRECT3DDEVICE9 GetDevice() { return GetInstance()->m_pd3dDevice; };
	static LPD3DXSPRITE GetSprite() { return GetInstance()->m_pSprite; };

private:
	// 윈도우즈 기본 정보
	HWND m_hWnd;
	UINT m_Width, m_Height;

	// 다이렉트 기본 정보
	LPDIRECT3D9             m_pD3D;
	LPDIRECT3DDEVICE9       m_pd3dDevice;
	LPD3DXSPRITE			m_pSprite;

	friend class Device;
};

