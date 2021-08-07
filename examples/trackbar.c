#include <windows.h>
#include "../include/ui/trackbar.h"
#define Name "Trackbar Example"

void DrawTrackbar(HWND parent)
{
	HWND trackbar1 = 0;
	trackbar_setHeight(trackbar1, 30);
	trackbar_setWidth(trackbar1, 150);
	trackbar_setX(trackbar1, 10);
	trackbar_setY(trackbar1, 10);
	trackbar_setMin(trackbar1, 50);
	trackbar_setMax(trackbar1, 100);
	trackbar_setSteps(trackbar1, 10);	
	trackbar1 =  trackbar_create(parent);

	HWND trackbar2 = 0;
	trackbar_setHeight(trackbar2, 30);
	trackbar_setWidth(trackbar2, 150);
	trackbar_setX(trackbar2, 10);
	trackbar_setY(trackbar2, 50);
	trackbar_setMin(trackbar2, 0);
	trackbar_setMax(trackbar2, 50);	
	trackbar_setSteps(trackbar2, 5);	
	trackbar2 = trackbar_create(parent);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) 
	{
	    case WM_CREATE:
	    	DrawTrackbar(hwnd);
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

