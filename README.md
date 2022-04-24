# Natforms
Small C header only wrapper over windows native graphical widgets without spoiling tradition. Currently few widgets are supported even with few properties. 

## Why need of new UI lib, if there are already many present ?
Most ui libraries are written in C++. There were few C libs, even those of mostly very low level or with dirty syntax. Natforms itself uses low level apis, but wrapping it an easy way. Calling natform is same as calling native apis directly. So there is less gap. Whereas, most managed ui libraries create an huge gape between operating system api, thus causing performance issues.  
## How syntax look like ?
```csharp
button button1 = Button();
button_setParent (&button1, parent);
button_setX      (&button1, 10);
button_setY      (&button1, 10);
button_setWidth  (&button1, 200);
button_setHeight (&button1, 30);
button_setText   (&button1, L"Button1");
button_draw      (&button1);
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
