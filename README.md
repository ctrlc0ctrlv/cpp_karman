# Overview
Windows application for numerical simulation of Karman tracks (turbulent flows)

# Requirements
1. cl.exe
2. Microsoft C++ toolset (to use vcvars64.bat)
3. Bluu Next Cyrillic font installed

vscode tip: Add "compilerArgs": ["/clr"] to c_cpp_properties.json (see: https://github.com/microsoft/vscode-cpptools/issues/8539)

# Compilation

## cmd

Firstly change path to vcvars64.bat in make.bat file (it may be differ on different computers)

1. Create "obj" subdirectory
2. 
    ```
    make.bat
    MyForm
    ```
3. Select the parameters you need and wait until the simulation ends 

# Further development
Pure C++ version (cleaner code and more optimized computations) is coming soon!

UPD: new version is updating on "refactor" branch
