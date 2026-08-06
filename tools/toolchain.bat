@echo off
rem tools\toolchain.bat -- Shared toolchain resolver.
rem Called via `call "%~dp0toolchain.bat"` from other .bat files; do not run directly.
rem Priority: env MINGW_BIN > tools\toolchain.config > auto-detect.
rem Sets: MINGW_BIN  GXX  GDB  (and prepends MINGW_BIN to PATH).
rem NOTE: ASCII-only on purpose (cmd parses batch in ANSI codepage).

if defined MINGW_BIN goto :have

if exist "%~dp0toolchain.config" (
  for /f "usebackq tokens=1,* delims==" %%A in ("%~dp0toolchain.config") do (
    if "%%A"=="MINGW_BIN" set "MINGW_BIN=%%B"
  )
)

if defined MINGW_BIN goto :have

for %%D in ("D:\XC_workspace\msys64\mingw64\bin" "C:\msys64\mingw64\bin" "C:\tools\msys64\mingw64\bin") do (
  if exist "%%~D\g++.exe" if exist "%%~D\gdb.exe" set "MINGW_BIN=%%~D"
)

if not defined MINGW_BIN (
  echo [ERROR] MinGW toolchain not found ^(g++.exe / gdb.exe^).
  echo         Edit MINGW_BIN= in %~dp0toolchain.config, or set env var MINGW_BIN.
  exit /b 1
)

:have
set "GXX=%MINGW_BIN%\g++.exe"
set "GDB=%MINGW_BIN%\gdb.exe"
set "PATH=%MINGW_BIN%;%PATH%"
exit /b 0
