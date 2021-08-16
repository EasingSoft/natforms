**Header:** [button.h](../include/ui/button.h)
```c
	button Button();
	BOOL button_setParent(*button, HWND parent);
	BOOL button_draw(*button);
	BOOL button_setX(*button, int X);
	BOOL button_setY(*button, int Y);
	BOOL button_setWidth(*button, int width);
	BOOL button_setHeight(*button, int height);
	BOOL button_setText(*button, LPCWSTR text);
```


**Example:** [button.c](../examples/button.c#L5-L22)
```c
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
```


**Output:**
```
 ____________________________________
|______________________________|_|_|_|
|   ____________________             |
|  |                    |            |
|  |     button1        |            |
|  |____________________|            |
|  			             |
|   ____________________             |
|  |                    |            |
|  |     button2        |            |
|  |____________________|            |
|		                     |
|		                     |
|		                     |
|		                     |
|____________________________________|
```
