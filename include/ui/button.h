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
	button lbl;
	lbl.text = L"";
	lbl.x = 0;
	lbl.y = 0;
	lbl.width = 10;
	lbl.height = 10;
	lbl.visible = 1;
	return lbl;
}

//Events
#define BUTTON_CLICK WM_COMMAND
//Events

BOOL button_setVisible(button *l, BOOL VISIBLE)
{
	l->visible = VISIBLE;
	return ShowWindow(l->me, (VISIBLE ? SW_SHOW : SW_HIDE));
}

BOOL button_draw(button *l)
{
	l->me = CreateWindowExW(0, L"button", l->text, (l->visible ? WS_VISIBLE | WS_CHILD : WS_CHILD), l->x, l->y, l->width, l->height, l->parent, (HMENU)l->ID, NULL, NULL);
	return l->me != NULL;
}

BOOL button_setID(button *l, int ID)
{
	l->ID = ID;
	return SetMenu(l->me, (HMENU)ID);
}

BOOL button_setParent(button *l, HWND PARENT)
{
	l->parent = PARENT;
	return SetParent(l->me, PARENT) != NULL;
}

BOOL button_setWidth(button *l, int WIDTH)
{
	l->width = WIDTH;
	return SetWindowPos(l->me, 0, 0, 0, WIDTH, l->height, SWP_NOMOVE | (l->visible ? SWP_SHOWWINDOW : SWP_HIDEWINDOW));
}

BOOL button_setHeight(button *l, int HEIGHT)
{
	l->height = HEIGHT;
	return SetWindowPos(l->me, 0, 0, 0, l->width, HEIGHT, SWP_NOMOVE | (l->visible ? SWP_SHOWWINDOW : SWP_HIDEWINDOW));
}

BOOL button_setX(button *l, int X)
{
	l->x = X;
	return SetWindowPos(l->me, 0, X, l->y, 0, 0, SWP_NOSIZE | (l->visible ? SWP_SHOWWINDOW : SWP_HIDEWINDOW));
}

BOOL button_setY(button *l, int Y)
{
	l->y = Y;
	return SetWindowPos(l->me, 0, l->x, Y, 0, 0, SWP_NOSIZE | (l->visible ? SWP_SHOWWINDOW : SWP_HIDEWINDOW));
}

BOOL button_setText(button *l, LPCWSTR TEXT)
{
	l->text = TEXT;
	return SetWindowTextW(l->me, TEXT);
}
