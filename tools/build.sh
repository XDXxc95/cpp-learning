#!/usr/bin/env bash
# 只编译不运行 Compile only (no run)。供调试器的 preLaunchTask 使用。
# 用法 Usage: tools/build.sh <source.cpp>
# 自适应 Adaptive：见 common.sh

# 共享环境解析：PROJECT_ROOT / MINGW_BIN / GXX / GDB
source "$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)/common.sh"

SRC="$1"
if [ -z "$SRC" ]; then
  echo "用法 Usage: $0 <source.cpp>" >&2
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
# 提前拒绝非 C++ 输入：把 .md 之类喂给 g++ 会被甩到链接器，
# 报出「file format not recognized」这种完全指错方向的错（VS Code ${file} 选中了别的标签页）。
case "$SRC" in
  *.cpp | *.cc | *.cxx) ;;
  *)
    echo "错误 Error: 不是 C++ 源文件（需要 .cpp）: $SRC" >&2
    exit 1
    ;;
esac

mkdir -p "$PROJECT_ROOT/build"
# 项目级运行时 Project-local runtime：把运行库同步进 build/。
# Windows 按「exe 所在目录优先于 PATH」解析 DLL，绕开系统 PATH 里 Git/Qt 的旧 mingw DLL。
for lib in libstdc++-6.dll libgcc_s_seh-1.dll libwinpthread-1.dll; do
  cp -f "$MINGW_BIN_MSYS/$lib" "$PROJECT_ROOT/build/$lib" 2>/dev/null
done
OUT="$PROJECT_ROOT/build/$(basename "${SRC%.*}").exe"

echo "==> 编译 Compiling: $SRC"
"$GXX" -std=c++17 -Wall -Wextra -g -o "$OUT" "$SRC"
exit $?
