setlocal
    @REM PREPARATION
    call "C:/Program Files (x86)/Microsoft Visual Studio/2022/BuildTools/VC/Auxiliary/Build/vcvars64.bat"
    set "CC=cl.exe"
    set "SRC=karman.cpp figure.cpp drawer.cpp calculator.cpp"

    @REM SOURCES COMPILATION
    %CC% /Fo.\build\ /clr /c %SRC%

    @REM LINKING
    link ./build/karman.obj ./build/figure.obj ./build/drawer.obj ./build/calculator.obj /SUBSYSTEM:CONSOLE /MACHINE:x64 /OUT:main.exe
endlocal