#include "Define.h"
#include "Device.h"
#include "Looper.h"

LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) // 윈도우 프로시저
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_SETCURSOR:
		SetCursor(NULL);
		break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

INT WINAPI wWinMain(HINSTANCE hInst, HINSTANCE, LPWSTR, INT) // 프로그램 진입점
{
	//콘솔창 띄우기
	//AllocConsole();
	//freopen("CONOUT$", "wt", stdout);

	Looper Looper;

	DWORD first_time = 0;
	float deltaTime = 0;

	// 윈도우 클래스 정의,등록
	WNDCLASSEX wc =
	{
		sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L,
		GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
		L"NoName", NULL
	};
	RegisterClassEx(&wc);

	// 윈도우 생성
	HWND hWnd = CreateWindow(L"NoName", L"NoName",
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		ScreenSizeX + GetSystemMetrics(SM_CXFRAME) * 4, ScreenSizeY + GetSystemMetrics(SM_CYFRAME) * 4 + GetSystemMetrics(SM_CYCAPTION),
		NULL, NULL, wc.hInstance, NULL);

	// Direct3D초기화
	if (SUCCEEDED(Device::GetInstance()->Start(hWnd, ScreenSizeX, ScreenSizeY)))
	{
		cout << "성공적으로 게임을 실행했습니다." << endl;
		// 윈도우 출력
		ShowWindow(hWnd, SW_SHOWDEFAULT);
		UpdateWindow(hWnd);

		Looper.Start();

		MSG msg;
		// 메시지 루프
		while (true)
		{
			if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				first_time = GetTickCount();

				Looper.Update(deltaTime);

				deltaTime = (float)(GetTickCount() - first_time) / (float)1000;
			}
			if (msg.message == WM_QUIT)
			{
				break;
			}
		}
	}

	UnregisterClass(L"NoName", wc.hInstance); // 등록된 클래스 소거

	return 0;
}