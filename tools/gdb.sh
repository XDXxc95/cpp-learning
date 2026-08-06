#!/usr/bin/env bash
# 编译(含调试信息)并启动 gdb | Compile with debug info, then launch gdb
# 用法 Usage: tools/gdb.sh <source.cpp>
# 进入 gdb 后：run 运行 / break 文件名:行号 设断点 / quit 退出
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

mkdir -p "$PROJECT_ROOT/build"
# 项目级运行时 Project-local runtime：把运行库同步进 build/。
# Windows 按「exe 所在目录优先于 PATH」解析 DLL，绕开系统 PATH 里 Git/Qt 的旧 mingw DLL。
for lib in libstdc++-6.dll libgcc_s_seh-1.dll libwinpthread-1.dll; do
  cp -f "$MINGW_BIN_MSYS/$lib" "$PROJECT_ROOT/build/$lib" 2>/dev/null
done
OUT="$PROJECT_ROOT/build/$(basename "${SRC%.*}").exe"

echo "==> 编译 Compiling: $SRC"
"$GXX" -std=c++17 -Wall -Wextra -g -o "$OUT" "$SRC" || exit 1

echo "==> 启动 gdb (输入 run 开始运行, break main 设断点, quit 退出)"
"$GDB" -q "$OUT"
