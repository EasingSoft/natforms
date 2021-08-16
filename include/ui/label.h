#include <windows.h>
typedef struct
{
	LPCWSTR text;
	HWND parent, me;
	int x, y, width, height, id;
	BOOLEAN visible;

} label;

label Label()
{
	label lbl;
	lbl.text = L"";
	lbl.x = 0;
	lbl.y = 0;
	lbl.width = 10;
	lbl.height = 10;
	lbl.visible = 1;
	return lbl;
}

BOOL label_draw(label *l)
{
	l->me = CreateWindowExW(0, L"Static", l->text, (l->visible ? WS_VISIBLE | WS_CHILD : WS_CHILD), l->x, l->y, l->width, l->height, l->parent, (HMENU)l->id, NULL, NULL);
	return l->me != NULL;
}

BOOL label_setID(label *l, int ID)
{
	BOOL result = SetMenu(l->me, (HMENU)ID);
	l->id = ID;
	return result;
}

BOOL label_setParent(label *l, HWND PARENT)
{
	BOOL result = SetParent(l->me, PARENT) != NULL; 
	l->parent = PARENT;
	return result;
}

BOOL label_setWidth(label *l, int WIDTH)
{
	BOOL result = SetWindowPos(l->me, 0, 0, 0, WIDTH, l->height, SWP_NOMOVE | (l->visible ? SWP_SHOWWINDOW : SWP_HIDEWINDOW));
	l->width = WIDTH;
	return result;
}

BOOL label_setHeight(label *l, int HEIGHT)
{
	BOOL result = SetWindowPos(l->me, 0, 0, 0, l->width, HEIGHT, SWP_NOMOVE | (l->visible ? SWP_SHOWWINDOW : SWP_HIDEWINDOW));
	l->height = HEIGHT;
	return result;
}

BOOL label_setX(label *l, int X)
{
	BOOL result = SetWindowPos(l->me, 0, X, l->y, 0, 0, SWP_NOSIZE | (l->visible ? SWP_SHOWWINDOW : SWP_HIDEWINDOW));
	l->x = X;
	return result;
}

BOOL label_setY(label *l, int Y)
{
	BOOL result = SetWindowPos(l->me, 0, l->x, Y, 0, 0, SWP_NOSIZE | (l->visible ? SWP_SHOWWINDOW : SWP_HIDEWINDOW));
	l->y = Y;
	return result;
}

BOOL label_setText(label *l, LPCWSTR TEXT)
{
	BOOL result = SetWindowTextW(l->me, TEXT);
	l->text = TEXT;
	return result;
}