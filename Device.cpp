#include "Device.h"

Device* Device::GetInstance()
{
	static Device Instance;
	return &Instance;
}

Device::~Device()
{
	SAFE_RELEASE(m_pd3dDevice);
	SAFE_RELEASE(m_pD3D);
}

HRESULT Device::Start(HWND hWnd, UINT Width, UINT Height)
{
	// Start의 인자를 클래스 내의 인자로 복사한다.
	m_hWnd = hWnd;
	m_Width = Width;
	m_Height = Height;

	// 디바이스를 생성하기위한 D3D객체 생성
	if (NULL == (m_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
		return E_FAIL;

	// 디바이스를 생성할 구조체
	D3DPRESENT_PARAMETERS d3dpp = { m_Width, m_Height, D3DFMT_A8R8G8B8, 1,
		D3DMULTISAMPLE_NONE, 0, D3DSWAPEFFECT_DISCARD,
		m_hWnd, true, TRUE, D3DFMT_D24S8, 0,
		D3DPRESENT_RATE_DEFAULT, D3DPRESENT_INTERVAL_DEFAULT };

	/// 디바이스 생성
	if (FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &m_pd3dDevice)))
	{
		return E_FAIL;
	}

	D3DXCreateSprite(m_pd3dDevice, &m_pSprite);

	m_pd3dDevice->SetRenderState(D3DRS_ZENABLE, false);

	return S_OK;
}