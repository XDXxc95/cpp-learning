@echo off
rem Format C++ files with clang-format (LLVM style).
rem Usage: tools\format.bat [--check] file.cpp [more files...]
rem   --check   report only; exit code non-zero if any file is misformatted.
rem clang-format priority: env CLANG_FORMAT > VS Code C/C++ extension bundled > PATH.
rem Style: reads the nearest .clang-format up from each file (project root has LLVM).
rem NOTE: ASCII-only on purpose (cmd parses batch in ANSI codepage).
setlocal enabledelayedexpansion
set "ROOT=%~dp0.."

rem ---- locate clang-format ----
set "CF="
if defined CLANG_FORMAT if exist "%CLANG_FORMAT%" set "CF=%CLANG_FORMAT%"
if not defined CF (
  rem cmd's `for /d` only expands a wildcard in the LAST path segment, so first
  rem match the extension dir itself, then probe the inner LLVM\bin path.
  if defined USERPROFILE (
    for /d %%d in ("%USERPROFILE%\.vscode\extensions\ms-vscode.cpptools-*") do (
      if exist "%%d\LLVM\bin\clang-format.exe" if not defined CF set "CF=%%d\LLVM\bin\clang-format.exe"
    )
  )
)
if not defined CF (
  where clang-format >nul 2>nul && set "CF=clang-format"
)
if not defined CF (
  echo [format] clang-format not found. Install VS Code C/C++ extension or LLVM, or set env CLANG_FORMAT.
  exit /b 1
)

set "CHECK=0"
if /i "%~1"=="--check" (
  set "CHECK=1"
  shift
)

if "%~1"=="" (
  echo Usage: tools\format.bat [--check] ^<file.cpp^> [more...]
  exit /b 2
)

rem collect remaining args, resolving relative paths against project root
set "ARGS="
:collect
set "F=%~1"
if not exist "%F%" if exist "%ROOT%\%F%" set "F=%ROOT%\%F%"
if not exist "%F%" (
  echo [format] file not found: %~1
  exit /b 2
)
set "ARGS=%ARGS% "%F%""
shift
if not "%~1"=="" goto collect

echo ==^> clang-format: %CF%
if "%CHECK%"=="1" (
  "%CF%" -style=file --fallback-style=LLVM --dry-run -Werror %ARGS%
) else (
  "%CF%" -style=file --fallback-style=LLVM -i %ARGS%
)
exit /b %errorlevel%
