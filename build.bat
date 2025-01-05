@echo off

where /q cl.exe
IF ERRORLEVEL 1 (
  call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x64
)

if not exist "bin" (
  mkdir "bin"
)

cl.exe /std:c++20 /O2 /EHsc /wd4244 fs_bench.cpp /Fe:.\bin\fs_bench.exe

if %errorlevel% neq 0 exit /b %errorlevel%

echo "Built .\bin\fs_bench.exe"
