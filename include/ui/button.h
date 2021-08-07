#include <windows.h>
const wchar_t *text = L"";
int width, height, x, y = 10;

HWND button_create(HWND PARENT)
{
    return CreateWindowExW(0, L"button", text, WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, x, y, width, height, PARENT, 0, 0, 0);
}

BOOLEAN isCreated(HWND me)
{
    return me != 0;
}

void button_setWidth(HWND me, int WIDTH)
{
	if (me != 0) SetWindowPos(me, 0, 0, 0, WIDTH, height, SWP_NOMOVE | SWP_SHOWWINDOW);
	width = WIDTH;
}

void button_setHeight(HWND me, int HEIGHT)
{
	if (me != 0) SetWindowPos(me, 0, 0, 0, width, HEIGHT, SWP_NOMOVE | SWP_SHOWWINDOW);
	height = HEIGHT;
}

void button_setX(HWND me, int X)
{
	if (me != 0) SetWindowPos(me, 0, X, y, 0, 0, SWP_NOSIZE | SWP_SHOWWINDOW);
	x = X;
}

void button_setY(HWND me, int Y)
{
	if (me != 0) SetWindowPos(me, 0, x, Y, 0, 0, SWP_NOSIZE | SWP_SHOWWINDOW);
	y = Y;
}

void button_setText(HWND me, const wchar_t *TEXT)
{
	if (me != 0) SetWindowTextW(me, TEXT);
	text = TEXT;
}
