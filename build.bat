@ECHO OFF
setlocal enabledelayedexpansion

set "tcc=%CD%/tcc/tcc.exe"
set "tcc64=%CD%/tcc/tcc64.exe"

MKDIR bin 
cd bin
MKDIR x86
MKDIR x64
cd..

REM 32 bit Build
for %%f in (examples\*.c) do (
  %tcc% -Iinclude -o "bin/x86/%%~nf.exe" "%%f"
)

REM 64 bit Build
for %%f in (examples\*.c) do (
  %tcc64% -Iinclude -o "bin/x64/%%~nf64.exe" "%%f"
)
