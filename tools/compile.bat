@echo off
rem One-shot compile & run for a single C++ file
rem Usage: tools\compile.bat <source.cpp> [args...]
rem Output: build\<same-name>.exe
rem Adaptive: project root is derived from this script's location, toolchain via toolchain.bat.
rem NOTE: ASCII-only on purpose (cmd parses batch in ANSI codepage; UTF-8 Chinese may corrupt parsing).
setlocal
call "%~dp0toolchain.bat"
if errorlevel 1 exit /b 1
set "ROOT=%~dp0.."

if "%~1"=="" (
  echo Usage: tools\compile.bat ^<source.cpp^> [args...]
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
rem Windows resolves DLLs by "exe's own directory before PATH", so the exe loads the
rem correct copies next to it, bypassing old Git/Qt mingw DLLs in the system PATH.
copy /y "%MINGW_BIN%\libstdc++-6.dll" "%ROOT%\build\" >nul 2>nul
copy /y "%MINGW_BIN%\libgcc_s_seh-1.dll" "%ROOT%\build\" >nul 2>nul
copy /y "%MINGW_BIN%\libwinpthread-1.dll" "%ROOT%\build\" >nul 2>nul

set "OUT=%ROOT%\build\%~n1.exe"

echo ==^> Compiling: %SRC%
"%GXX%" -std=c++17 -Wall -Wextra -g -o "%OUT%" "%SRC%"
if errorlevel 1 (
  echo x Compile failed.
  exit /b 1
)

rem Collect arguments after the source file (shift does not affect %*)
set "ARGS="
:collect
shift
if "%~1"=="" goto run
set "ARGS=%ARGS% "%~1""
goto collect

:run
echo ==^> Running in a separate window: %OUT% %ARGS%
rem Run in a popup window; cmd /c + pause closes on keypress (/v:on gets the real exit code).
rem NOTE: leave the path unquoted -- cmd /c double-quote prefix mis-parses on this machine (flashes away).
start "Result - %~n1" cmd /v:on /c "%OUT% %ARGS% & echo. & echo ==^> Exit code: !errorlevel! & echo. & echo [Press any key to close this window] & pause >nul"
exit /b 0
