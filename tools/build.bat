@echo off
rem Compile ONLY (no run). Used as preLaunchTask for the debugger.
rem Usage: tools\build.bat <source.cpp>
rem Output: build\<same-name>.exe
rem Adaptive: project root from this script's location, toolchain via toolchain.bat.
rem NOTE: ASCII-only on purpose (cmd parses batch in ANSI codepage).
setlocal
call "%~dp0toolchain.bat"
if errorlevel 1 exit /b 1
set "ROOT=%~dp0.."

if "%~1"=="" (
  echo Usage: tools\build.bat ^<source.cpp^>
  exit /b 2
)
set "SRC=%~1"
if not exist "%SRC%" if exist "%ROOT%\%SRC%" set "SRC=%ROOT%\%SRC%"
if not exist "%SRC%" (
  echo Error: source file not found: %~1
  exit /b 1
)
if not exist "%ROOT%\build" mkdir "%ROOT%\build"

rem Project-local runtime: sync MSYS2 runtime DLLs into build\.
rem Windows resolves DLLs by "exe's own directory before PATH"; without this, VS Code's
rem debugger loads an old incompatible libstdc++ and the first std::cout segfaults.
copy /y "%MINGW_BIN%\libstdc++-6.dll" "%ROOT%\build\" >nul 2>nul
copy /y "%MINGW_BIN%\libgcc_s_seh-1.dll" "%ROOT%\build\" >nul 2>nul
copy /y "%MINGW_BIN%\libwinpthread-1.dll" "%ROOT%\build\" >nul 2>nul

echo ==^> Compiling: %SRC%
"%GXX%" -std=c++17 -Wall -Wextra -g -o "%ROOT%\build\%~n1.exe" "%SRC%"
exit /b %ERRORLEVEL%
