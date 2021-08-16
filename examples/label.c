#include <windows.h>
#include "../include/ui/label.h"
#define Name "Label Example"

void DrawLabel(HWND parent)
{
	label label1 = Label();
	label_setParent(&label1, parent);
	label_draw(&label1);
	label_setX(&label1, 10);
	label_setY(&label1, 10);

	label_setWidth(&label1, 200);
	label_setHeight(&label1, 30);
	label_setText(&label1, L"Label1");



	label label2 = Label();
	label_setParent(&label2, parent);
	label_draw(&label2);
	label_setY(&label2, 50);
	label_setX(&label2, 10);
	label_setWidth(&label2, 200);
	label_setHeight(&label2, 30);
	label_setText(&label2, L"Label2");
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) 
	{
	    case WM_CREATE:
	    	DrawLabel(hwnd);
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

