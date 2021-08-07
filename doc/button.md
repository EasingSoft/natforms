**Header:** [button.h](../include/ui/button.h)
```c
bool button_isCreated(HWND me); //Whether button window already created ?
void button_setWidth(HWND me, int WIDTH); //Change width of button
void button_setHeight(HWND me, int HEIGHT); //Change height of button
void button_setX(HWND me, int X);
void button_setY(HWND me, int Y);
void button_setText(HWND me, const wchar_t *TEXT);
HWND button_create(HWND me, HWND PARENT);
```


**Example:** [button.c](../examples/button.c#L5-L22)
```c
HWND b1 = 0;                             //declare variable named b1 with type HWND. Remember: 0 or Null or nullptr, all are same
button_setHeight(b1, 30);                //set height of button named b1 as 30px
button_setWidth(b1, 150);                //set width of button named b1 as 150px
button_setX(b1, 10);                     //set X asix of button named b1 as 10px
button_setY(b1, 10);                     //set X asix of button named b1 as 10px
button_setText(b1, L"This is button1");  //set text of button named b1 as "This is button1"
b1 = button_create(parent);              //show button named b1 and insert its window to b2 variable

HWND b2 = 0;                     //declare variable named b2 with type HWND. Remember: 0 or Null or nullptr, all are same
button_setHeight(b2, 30);        //set height of button named b1 as 30px
button_setWidth(b2, 150);        //set width of button named b1 as 150px
button_setX(b2, 10);             //set X asix of button named b1 as 10px
button_setY(b2, 50);             //set X asix of button named b1 as 50px
button_setText(b2, L"and this is button2");  //set text of button named b1 as "and this is button2"
b2 = button_create(parent);      //show button named b1 and insert its window to b2 variable
```


**Output:**
```
 ____________________________________
|______________________________|_|_|_|
|   ____________________             |
|  |                    |            |
|  | this is button1    |            |
|  |____________________|            |
|  			             |
|   _____________________            |
|  |                     |           |
|  | and this is button2 |           |
|  |_____________________|           |
|		                     |
|		                     |
|		                     |
|		                     |
|____________________________________|
```
