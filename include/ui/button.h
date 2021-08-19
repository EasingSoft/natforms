#include <windows.h>
typedef struct
{
	LPCWSTR text;
	HWND parent, me;
	int x, y, width, height,ID;
	BOOLEAN visible;

} button;

button Button()
{
	button btn;
	btn.text = L"";
	btn.x = 0;
	btn.y = 0;
	btn.width = 10;
	btn.height = 10;
	btn.visible = 1;
	return btn;
}

//Events
#define BUTTON_CLICK WM_COMMAND
//Events

BOOL button_setVisible(button *b, BOOL VISIBLE)
{
	b->visible = VISIBLE;
	return ShowWindow(b->me, (VISIBLE ? SW_SHOW : SW_HIDE));
}

BOOL button_draw(button *b)
{
	b->me = CreateWindowExW(0, L"button", b->text, (b->visible ? WS_VISIBLE | WS_CHILD : WS_CHILD), b->x, b->y, b->width, b->height, b->parent, (HMENU)b->ID, NULL, NULL);
	return b->me != NULL;
}

BOOL button_setID(button *b, int ID)
{
	b->ID = ID;
	return SetMenu(b->me, (HMENU)ID);
}

BOOL button_setParent(button *b, HWND PARENT)
{
	b->parent = PARENT;
	return SetParent(b->me, PARENT) != NULL;
}

BOOL button_setWidth(button *b, int WIDTH)
{
	b->width = WIDTH;
	return SetWindowPos(b->me, 0, 0, 0, WIDTH, b->height, SWP_NOMOVE | (b->visible ? SWP_SHOWWINDOW : SWP_HIDEWINDOW));
}

BOOL button_setHeight(button *b, int HEIGHT)
{
	b->height = HEIGHT;
	return SetWindowPos(b->me, 0, 0, 0, b->width, HEIGHT, SWP_NOMOVE | (b->visible ? SWP_SHOWWINDOW : SWP_HIDEWINDOW));
}

BOOL button_setX(button *b, int X)
{
	b->x = X;
	return SetWindowPos(b->me, 0, X, b->y, 0, 0, SWP_NOSIZE | (b->visible ? SWP_SHOWWINDOW : SWP_HIDEWINDOW));
}

BOOL button_setY(button *b, int Y)
{
	b->y = Y;
	return SetWindowPos(b->me, 0, b->x, Y, 0, 0, SWP_NOSIZE | (b->visible ? SWP_SHOWWINDOW : SWP_HIDEWINDOW));
}

BOOL button_setText(button *b, LPCWSTR TEXT)
{
	b->text = TEXT;
	return SetWindowTextW(b->me, TEXT);
}
