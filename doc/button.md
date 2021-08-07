[button.h](../include/ui/button.h)
```c
bool button_isCreated(HWND me); //Whether button window already created ?
void button_setWidth(HWND me, int WIDTH); //Change width of button
void button_setHeight(HWND me, int HEIGHT); //Change height of button
void button_setX(HWND me, int X);
void button_setY(HWND me, int Y);
void button_setText(HWND me, const wchar_t *TEXT);
HWND button_create(HWND me, HWND PARENT);
```

Example:
```c
HWND b1 = 0;
button_setHeight(b1, 50);
button_setWidth(b1, 50);
button_setX(b1, 10);
button_setY(b1, 10);
button_setText(b1, L"button1");
b1 =  button_create(parent);

HWND b2 = 0;
button_setHeight(b2, 50);
button_setWidth(b2, 50);
button_setX(b2, 100);
button_setY(b2, 100);
button_setText(b2, L"button2");
b2 = button_create(parent);
```
