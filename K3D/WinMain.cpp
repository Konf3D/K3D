#include "WindowClass.h"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE prevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Window wnd(800, 170, "K3D Engine");
	Window wnd2(200, 650, "Kekw");

	MSG msg;
	BOOL gResult;

	while ( (gResult = GetMessage(&msg,nullptr,0,0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	if (gResult == -1)
	{
		return -1;
	}

	return msg.wParam;
}