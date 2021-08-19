#include <windows.h>
typedef struct
{
	LPCWSTR text;
	HWND parent, me;
	int x, y, width, height,ID;
	BOOLEAN visible;

} label;

label Label()
{
	label btn;
	btn.text = L"";
	btn.x = 0;
	btn.y = 0;
	btn.width = 10;
	btn.height = 10;
	btn.visible = 1;
	return btn;
}


BOOL label_setVisible(label *l, BOOL VISIBLE)
{
	l->visible = VISIBLE;
	return ShowWindow(l->me, (VISIBLE ? SW_SHOW : SW_HIDE));
}

BOOL label_draw(label *l)
{
	l->me = CreateWindowExW(0, L"label", l->text, (l->visible ? WS_VISIBLE | WS_CHILD : WS_CHILD), l->x, l->y, l->width, l->height, l->parent, (HMENU)l->ID, NULL, NULL);
	return l->me != NULL;
}

BOOL label_setID(label *l, int ID)
{
	l->ID = ID;
	return SetMenu(l->me, (HMENU)ID);
}

BOOL label_setParent(label *l, HWND PARENT)
{
	l->parent = PARENT;
	return SetParent(l->me, PARENT) != NULL;
}

BOOL label_setWidth(label *l, int WIDTH)
{
	l->width = WIDTH;
	return SetWindowPos(l->me, 0, 0, 0, WIDTH, l->height, SWP_NOMOVE | (l->visible ? SWP_SHOWWINDOW : SWP_HIDEWINDOW));
}

BOOL label_setHeight(label *l, int HEIGHT)
{
	l->height = HEIGHT;
	return SetWindowPos(l->me, 0, 0, 0, l->width, HEIGHT, SWP_NOMOVE | (l->visible ? SWP_SHOWWINDOW : SWP_HIDEWINDOW));
}

BOOL label_setX(label *l, int X)
{
	l->x = X;
	return SetWindowPos(l->me, 0, X, l->y, 0, 0, SWP_NOSIZE | (l->visible ? SWP_SHOWWINDOW : SWP_HIDEWINDOW));
}

BOOL label_setY(label *l, int Y)
{
	l->y = Y;
	return SetWindowPos(l->me, 0, l->x, Y, 0, 0, SWP_NOSIZE | (l->visible ? SWP_SHOWWINDOW : SWP_HIDEWINDOW));
}

BOOL label_setText(label *l, LPCWSTR TEXT)
{
	l->text = TEXT;
	return SetWindowTextW(l->me, TEXT);
}
