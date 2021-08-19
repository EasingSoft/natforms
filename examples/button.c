#include <windows.h>
#include "../include/ui/button.h"
#include "../include/events.h"
#define Name "Button Example"

void DrawButton(HWND parent)
{
	button button1 = Button();
	button_setParent(&button1, parent);
	button_draw(&button1);
	button_setX(&button1, 10);
	button_setY(&button1, 10);
	button_setWidth(&button1, 200);
	button_setHeight(&button1, 30);
	button_setText(&button1, L"Button1");

	button button2 = Button();
	button_setParent(&button2, parent);
	button_draw(&button2);
	button_setY(&button2, 50);
	button_setX(&button2, 10);
	button_setWidth(&button2, 200);
	button_setHeight(&button2, 30);
	button_setText(&button2, L"Button2");
}


int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
	MSG msg;
	WNDCLASS wc;
	
	ZeroMemory(&wc, sizeof wc);
	wc.hInstance = hInstance;
	wc.lpszClassName = Name;
	wc.lpfnWndProc = (WNDPROC)handle_all_events;
	wc.style = CS_DBLCLKS | CS_VREDRAW | CS_HREDRAW;
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);

	if (FALSE == RegisterClass(&wc)) return 0;
	HWND hwnd = CreateWindow(Name, Name, WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT,CW_USEDEFAULT,
		360, 
		240, 
		0,0,hInstance,0);
		
	DrawButton(hwnd);
	while (GetMessage(&msg, NULL, 0, 0) > 0) 
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

