# Natforms
Small C header only wrapper over windows native graphical widgets without spoiling tradition. Currently few widgets are supported even with few properties. 

## Why need of new UI lib, if there are already many present ?
Most ui libraries are written in C++. There were few C libs, even those of mostly very low level or with dirty syntax. Natforms itself uses low level apis, but wrapping it an easy way. Calling natform is same as calling native apis directly. So there is less gap. Whereas, most managed ui libraries create an huge gape between operating system api, thus causing performance issues.  
## How syntax look like ?
```c
HWND button1 = 0;                                                     //declare variable named b1 with type HWND. Remember: 0 or Null or nullptr, all are same
button_setHeight(button1,  30);                                       //set height of button named b1 as 30px
button_setWidth (button1, 150);                                       //set width of button named b1 as 150px
button_setX     (button1,  10);                                       //set X asix of button named b1 as 10px
button_setY     (button1,  10);                                       //set X asix of button named b1 as 10px
button_setText  (button1, L"This is button1");                        //set text of button named b1 as "This is button1"
button1 = button_create(parent);                                      //show button named b1 and insert its window to b2 variable
                      
HWND button2 = button_create(parent);                                 //show button named b1 and insert its window to b2 variable
button_setHeight(button2,  30);                                       //set height of button named b1 as 30px
button_setWidth (button2, 150);                                       //set width of button named b1 as 150px
button_setX     (button2,  10);                                       //set X asix of button named b1 as 10px
button_setY     (button2,  50);                                       //set X asix of button named b1 as 50px
button_setText  (button2, L"this is button2");                        //set text of button named b1 as "and this is button2"
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
|   ____________________             |
|  |                    |            |
|  | this is button2    |            |
|  |____________________|            |
|		                     |
|		                     |
|		                     |
|		                     |
|____________________________________|
```

## Features
- Uses C99 for best compatibility
- Separate headers for each widget, include only those which you require
- Fully native and un-managed
- Compilable with any C/C++ compiler, even tcc
- Doesn't create gap between windows traditional functions to prevent your habits being spoiled 

## How to get started ? (Documentation)
- **Examples:** see examples [here](examples)
- **Samples:** see samples [here](doc)
- **Compile:** see how to compile samples [here](build.bat)

## Plans (Inshallah)
- Add more widgets
- Graphical Form Builder (WYSIWYG) like winforms
- Add raising widgets events

# I love Allah, Muhammad, Islam, Pakistan
