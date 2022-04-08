#include <Windows.h>
#include "WindowMessageMap.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static WindowsMessageMap mm;
	OutputDebugString( (mm(msg, lParam, wParam).c_str()) );
	switch (msg)
	{
	case WM_CLOSE:
		PostQuitMessage(69);
		break;
	case WM_KEYDOWN:
		if (wParam == 'F')
		{
			SetWindowText(hWnd, "cock");
		}
		break;
	case WM_CHAR:
	{
		static std::string title;
		title.push_back(char(wParam));
		SetWindowText(hWnd,title.c_str());
	}
	break;
	case WM_LBUTTONDOWN: 
	{
		const POINTS pt = MAKEPOINTS(lParam);
		std::ostringstream oss;
		oss << "(" << pt.x << "," << pt.y << ")";
		SetWindowText(hWnd, oss.str().c_str());
	}
	break;
	}
	return DefWindowProc(hWnd,msg,wParam,lParam);
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	const auto pClassName = "K3D";

	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName;
	wc.hIconSm = nullptr;

	RegisterClassEx(&wc);

	HWND hWnd = CreateWindowEx( 0,pClassName,"K3D engine", WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, 200, 200, 800, 640, nullptr,nullptr,hInstance,nullptr);

	ShowWindow(hWnd, SW_SHOW);
	MSG msg = { 0 };
	BOOL gResult;
	while ( (gResult= GetMessage(&msg,nullptr,0,0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	if (gResult == -1) 
	{
		return -1;
	}
	else
	{
		return msg.wParam;
	}
}