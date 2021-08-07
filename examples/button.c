#include <windows.h>
#include "../include/ui/button.h"
#define Name "Button Example"

void DrawButton(HWND parent)
{
	HWND b1 = 0;
	button_setHeight(b1, 20);
	button_setWidth(b1, 200);
	button_setX(b1, 0);
	button_setY(b1, 0);
	button_setText(b1, L"This is button1");
	b1 =  button_create(parent);

	HWND b2 = 0;
	button_setHeight(b2, 20);
	button_setWidth(b2, 200);
	button_setX(b2, 205);
	button_setY(b2, 25);
	button_setText(b2, L"and this is button2");
	b2 = button_create(parent);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) 
	{
	    case WM_CREATE:
	    	DrawButton(hwnd);
	    	break;
	    case WM_DESTROY:
	    	PostQuitMessage(0);
	    	break;
	    default:
	    	return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}


int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
	MSG msg;
	WNDCLASS wc;
	
	ZeroMemory(&wc, sizeof wc);
	wc.hInstance = hInstance;
	wc.lpszClassName = Name;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.style = CS_DBLCLKS | CS_VREDRAW | CS_HREDRAW;
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);

	if (FALSE == RegisterClass(&wc)) return 0;
	HWND hwnd = CreateWindow(Name, Name, WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT,CW_USEDEFAULT,
		360, 
		240, 
		0,0,hInstance,0);
		
	if (!hwnd) return 0;
	while (GetMessage(&msg, NULL, 0, 0) > 0) 
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

