setlocal
    @REM PREPARATION
    call "C:/Program Files (x86)/Microsoft Visual Studio/2022/BuildTools/VC/Auxiliary/Build/vcvars64.bat"
    set "CC=cl.exe"
    set "SRC=karman.cpp MyForm.cpp"

    @REM SOURCES COMPILATION
    %CC% /Fo.\obj\ /clr /c %SRC%

    @REM LINKING
    link ./obj/karman.obj ./obj/MyForm.obj /SUBSYSTEM:WINDOWS /MACHINE:x64 /OUT:MyForm.exe
endlocal