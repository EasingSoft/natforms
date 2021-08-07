**Header:** [trackbar.h](../include/ui/trackbar.h)
```c
bool trackbar_isCreated(HWND me);                      //Whether trackbar window already created ?
void trackbar_setWidth(HWND me, int WIDTH);            //Change width of trackbar
void trackbar_setHeight(HWND me, int HEIGHT);          //Change height of trackbar
void trackbar_setX(HWND me, int X);                    //Change X axis of trackbar
void trackbar_setY(HWND me, int Y);                    //Change Y axis of trackbar
void trackbar_setText(HWND me, const wchar_t *TEXT);   //Change text of trackbar
void trackbar_setMin(HWND me, int MIN);                //Change minimum tick value
void trackbar_setMax(HWND me, int MAX);                //Change maximum tick value
void trackbar_setSteps(HWND me, int STEPS);	           //Change step value
HWND trackbar_create(HWND me, HWND PARENT);            //Create trackbar
```


**Example:** [trackbar.c](../examples/trackbar.c#L5-L26)
```c
HWND trackbar1 = 0;
trackbar_setHeight(trackbar1, 30);
trackbar_setWidth(trackbar1, 150);
trackbar_setX(trackbar1, 10);
trackbar_setY(trackbar1, 10);
trackbar_setMin(trackbar1, 50);
trackbar_setMax(trackbar1, 100);
trackbar_setSteps(trackbar1, 10);	
trackbar1 =  trackbar_create(parent);

HWND trackbar2 = 0;
trackbar_setHeight(trackbar2, 30);
trackbar_setWidth(trackbar2, 150);
trackbar_setX(trackbar2, 10);
trackbar_setY(trackbar2, 50);
trackbar_setMin(trackbar2, 0);
trackbar_setMax(trackbar2, 50);	
trackbar_setSteps(trackbar2, 5);	
trackbar2 = trackbar_create(parent);
```


**Output:**
```
 ____________________________________
|______________________________|_|_|_|
|                                    |
|    __________________________      |
|   | ___                      |     |
|   | |||___________________   |     |
|   | \_/-------------------   |     |
|   |  |   |   |   |   |   |   |     |
|   |__________________________|     |
|                                    |
|    __________________________      |
|   | ___                      |     |
|   | |||___________________   |     |
|   | \_/-------------------   |     |
|   |  |   |   |   |   |   |   |     |
|   |__________________________|     |
|                                    |
|                                    |
|		                             |
|		                             |
|		                             |
|____________________________________|
```