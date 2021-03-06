#include "hDirectX.h"

int Width = 800;
int Height = 600;
const MARGINS Margin = {0, 0, Width, Height};

char lWindowName[256] = "Overlay";
HWND hWnd;

char tWindowName[256] = "Sea of Thieves"; 
HWND tWnd;
RECT tSize;
MSG Message;

LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	switch (Message)
	{
	case WM_PAINT:
		Render();
		break;

	case WM_CREATE:
		DwmExtendFrameIntoClientArea(hWnd, &Margin);
		break;

	case WM_DESTROY:
		exit(1);
		break;

	default:
		return DefWindowProc(hWnd, Message, wParam, lParam);
		break;
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hSecInstance, LPSTR nCmdLine, INT nCmdShow)
{
	CreateThread(0, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(SetWindowToTarget), nullptr, 0, nullptr);

	WNDCLASSEX wClass;
	wClass.cbClsExtra = 0;
	wClass.cbSize = sizeof(WNDCLASSEX);
	wClass.cbWndExtra = 0;
	wClass.hbrBackground = static_cast<HBRUSH>(CreateSolidBrush(RGB(0, 0, 0)));
	wClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wClass.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wClass.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
	wClass.hInstance = hInstance;
	wClass.lpfnWndProc = WinProc;
	wClass.lpszClassName = lWindowName;
	wClass.lpszMenuName = lWindowName;
	wClass.style = CS_VREDRAW | CS_HREDRAW;

	if (!RegisterClassEx(&wClass))
		exit(1);

	tWnd = FindWindow(nullptr, tWindowName);
	if (tWnd)
	{
		GetWindowRect(tWnd, &tSize);
		Width = tSize.right - tSize.left;
		Height = tSize.bottom - tSize.top;
		hWnd = CreateWindowEx(WS_EX_TOPMOST | WS_EX_TRANSPARENT | WS_EX_LAYERED, lWindowName, lWindowName, WS_POPUP, 1, 1, Width, Height, 0, 0, 0, 0);
		SetLayeredWindowAttributes(hWnd, 0, 1.0f, LWA_ALPHA);
		SetLayeredWindowAttributes(hWnd, 0, RGB(0, 0, 0), LWA_COLORKEY);
		ShowWindow(hWnd, SW_SHOW);
	}

	DirectXInit(hWnd);

	for (;;)
	{
		if (PeekMessage(&Message, hWnd, 0, 0, PM_REMOVE))
		{
			DispatchMessage(&Message);
			TranslateMessage(&Message);
		}
		Sleep(20);
	}
	return 0;
}

void SetWindowToTarget()
{
	char ErrorMsg[125];
	sprintf(ErrorMsg, "ESP by ForaN! F9 �����, F8 �����-���, F7 ��������, F6 ��������", tWindowName);
	MessageBox(0, ErrorMsg, "����", MB_OK | MB_ICONERROR);
	while(true)
	{
		tWnd = FindWindow(0, tWindowName);
		if (tWnd)
		{
			GetWindowRect(tWnd, &tSize);
			Width = tSize.right - tSize.left;
			Height = tSize.bottom - tSize.top;

			tSize.top += 23;
			Height -= 23;

			MoveWindow(hWnd, tSize.left, tSize.top, Width, Height, true);
		}
		else
		{
			char ErrorMsg[125];
			sprintf(ErrorMsg, "������� %s !", tWindowName);
			MessageBox(0, ErrorMsg, "������ - �� ���� ����� ����!", MB_OK | MB_ICONERROR);
			exit(1);
		}
		Sleep(100);
	}
}