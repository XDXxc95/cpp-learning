#!/usr/bin/env bash
# 一键编译并运行 C++ 单文件 | One-shot compile & run for a single C++ file
# 用法 Usage: tools/compile.sh <source.cpp> [运行参数 args...]
# 输出 Output: build/<同名>.exe
# 自适应 Adaptive：项目放哪都能跑（从脚本位置定位项目根），工具链位置自动解析（见 common.sh）

# 共享环境解析：PROJECT_ROOT / MINGW_BIN / GXX / GDB
source "$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)/common.sh"

SRC="$1"
if [ -z "$SRC" ]; then
  echo "用法 Usage: $0 <source.cpp> [运行参数 args...]" >&2
  exit 2
fi
# 相对路径优先按项目根解析，兼容任意调用目录
if [ ! -f "$SRC" ] && [ -f "$PROJECT_ROOT/$SRC" ]; then
  SRC="$PROJECT_ROOT/$SRC"
fi
if [ ! -f "$SRC" ]; then
  echo "错误 Error: 找不到源文件 $SRC" >&2
  exit 1
fi
shift

mkdir -p "$PROJECT_ROOT/build"
# 项目级运行时 Project-local runtime：把运行库同步进 build/。
# Windows 按「exe 所在目录优先于 PATH」解析 DLL，绕开系统 PATH 里 Git/Qt 的旧 mingw DLL。
for lib in libstdc++-6.dll libgcc_s_seh-1.dll libwinpthread-1.dll; do
  cp -f "$MINGW_BIN_MSYS/$lib" "$PROJECT_ROOT/build/$lib" 2>/dev/null
done
OUT="$PROJECT_ROOT/build/$(basename "${SRC%.*}").exe"

echo "==> 编译 Compiling: $SRC"
"$GXX" -std=c++17 -Wall -Wextra -g -o "$OUT" "$SRC" || {
  echo "✗ 编译失败 compile failed"
  exit 1
}

echo "==> 运行 Running (new window): $OUT $*"
# 独立弹窗运行：cmd /c 跑完输出后 pause 等一键自动关闭，/v:on 取真实退出码
# 注意：路径不带引号——cmd /c 的双引号前缀形式在本机解析异常（一闪而过）
OUT_WIN="$(cygpath -w "$OUT" 2>/dev/null || echo "$OUT")"
cmd //c start "Result - $(basename "$OUT" .exe)" cmd //v:on //c "$OUT_WIN $* & echo. & echo ==^> Exit code: !errorlevel! & echo. & echo [Press any key to close this window] & pause >nul"
exit 0
