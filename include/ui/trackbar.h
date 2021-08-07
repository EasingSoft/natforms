#include <windows.h>
#define WM_USER                         0x0400
#define TBS_AUTOTICKS           0x0001
#define TBS_ENABLESELRANGE      0x0020
#define TBM_SETRANGE            (WM_USER+6)
#define TBM_SETTICFREQ          (WM_USER+20)

int width, height, x, y,min,max,steps = 10;

HWND trackbar_create(HWND PARENT)
{
    return CreateWindowExW(0, L"msctls_trackbar32", L"", WS_CHILD | WS_VISIBLE | TBS_AUTOTICKS | TBS_ENABLESELRANGE,x, y, width, height,PARENT, 0, 0, 0);
}

BOOLEAN isCreated(HWND me)
{
    return me != 0;
}

void trackbar_setWidth(HWND me, int WIDTH)
{
    if (me != 0) SetWindowPos(me, 0, 0, 0, WIDTH, height, SWP_NOMOVE | SWP_SHOWWINDOW);
    width = WIDTH;
}

void trackbar_setHeight(HWND me, int HEIGHT)
{
    if (me != 0) SetWindowPos(me, 0, 0, 0, width, HEIGHT, SWP_NOMOVE | SWP_SHOWWINDOW);
    height = HEIGHT;
}

void trackbar_setX(HWND me, int X)
{
    if (me != 0) SetWindowPos(me, 0, X, y, 0, 0, SWP_NOSIZE | SWP_SHOWWINDOW);
    x = X;
}

void trackbar_setY(HWND me, int Y)
{
    if (me != 0) SetWindowPos(me, 0, x, Y, 0, 0, SWP_NOSIZE | SWP_SHOWWINDOW);
    y = Y;
}

void trackbar_setMin(HWND me, int MIN)
{
    if (me != 0) SendMessageW(me, TBM_SETRANGE, TRUE, MAKELONG(MIN, max));  
    min = MIN;
}

void trackbar_setMax(HWND me, int MAX)
{
    if (me != 0) SendMessageW(me, TBM_SETRANGE, TRUE, MAKELONG(min, MAX));  
    max = MAX;
}

void trackbar_setSteps(HWND me, int STEPS)
{
    if (me != 0) SendMessageW(me, TBM_SETTICFREQ, STEPS, 0);
    steps = STEPS;
}

