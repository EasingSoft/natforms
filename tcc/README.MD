**TCC IS TINY C COMPILER WRITTEN BY Fabrice Bellard. Following introduction is taken from offical tcc website.** 


![tcc logo](https://bellard.org/tcc/tcc-logo.png "tcc logo")
**Tiny C Compiler**

## News

[Note: I am no longer working on TCC. Check the mailing list to get up
to date information.]

## Features

- **SMALL!** You can compile and execute C code everywhere, for
  example on rescue disks (about 100KB for x86 TCC executable,
  including C preprocessor, C compiler, assembler and linker).
- **FAST!** tcc generates x86 code. No byte code
  overhead. Compile, assemble and link several times [faster](#compilation-speed) than `GCC`.
- **UNLIMITED!** Any C dynamic library can be used directly. TCC is
  heading torward full **ISOC99** compliance. TCC can of course compile
  itself.
- **SAFE!** tcc includes an optional **memory and bound checker**. 
  Bound checked code can be mixed freely with standard code.
- Compile and execute C source directly. No linking or assembly
  necessary. Full C preprocessor and GNU-like assembler
  included. 
- C script supported : just add `'#!/usr/local/bin/tcc -run'` at the first
  line of your C source, and execute it directly from the command
  line.
- With `libtcc`, you can use TCC as a backend for dynamic code
generation. 

## [Download](http://download.savannah.gnu.org/releases/tinycc/)

## Compilation Speed

Compilation speed for the [Links Browser project](http://links.twibright.com/download.php). 
There are 76936 lines (including
headers). 1950947 lines (67.2 MBytes) are compiled because the same headers are
included in many files. TinyCC is about **9 times** faster than
GCC.

| Compiler      | Time(s) | lines/second | MBytes/second |
|---------------|---------|--------------|---------------|
| TinyCC 0.9.22 | 2.27    | 859000       | 29.6          |
| GCC 3.2 -O0   | 20.0    | 98000        | 3.4           |

Measures were done on a 2.4 GHz Pentium 4. Real time is measured. Compilation
time includes compilation, assembly and linking.


More up to date tests are available:
[1](http://lists.nongnu.org/archive/html/tinycc-devel/2013-02/msg00056.html),
[2](http://lists.nongnu.org/archive/html/tinycc-devel/2013-02/msg00039.html),
[3](http://lists.nongnu.org/archive/html/tinycc-devel/2013-02/msg00043.html),
[4](http://lists.nongnu.org/archive/html/tinycc-devel/2013-01/msg00007.html).

## [Online Documentation](tcc-doc.html)

## You want to help ?
Here are some suggestions:
- Report bugs to the mailing list (and eventually fix them).

## Links
- [TinyCC mailing list](https://lists.nongnu.org/mailman/listinfo/tinycc-devel)
- [Savannah project page and git repository](http://savannah.gnu.org/projects/tinycc)
- [OTCC](http://bellard.org/otcc) - The smallest self compiling pseudo C compiler
- [FFASN1](http://bellard.org/ffasn1) - My small but powerful ASN.1 compiler.
- [LLVM Compiler Infrastructure](http://llvm.org)
- [SmartEiffel](http://smarteiffel.loria.fr) With TCC you can compile your Eiffel code faster
- [The GNU C Compiler](http://gcc.gnu.org)
- [The LCC Compiler](http://www.cs.princeton.edu/software/lcc)
- [The Small Device C Compiler](http://sdcc.sourceforge.net/)
- [Cyclone](http://cyclone.thelanguage.org), A Safe Dialect of C
- [The D language](http://www.digitalmars.com/d)
- [Programming in C](http://www.lysator.liu.se/c)
- [Scriptometer](http://rigaux.org/language-study/scripting-language) evaluates various scripting languages (including TCC).

## License

TCC is distributed under the GNU Lesser General Public License. 

Copyright (c) 2001-2018 Fabrice Bellard 

Fabrice Bellard - [bellard.org](http://bellard.org) - [tinycc.org](http://tinycc.org)
