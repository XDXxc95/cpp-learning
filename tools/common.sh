#!/usr/bin/env bash
# tools/common.sh — 共享环境解析 Shared environment resolver
# 供 tools/*.sh source 使用，让脚本自适应「项目位置」与「工具链位置」。
#
# 用法：在脚本开头 source "$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)/common.sh"
# 解析顺序 Priority：环境变量 MINGW_BIN > tools/toolchain.config > 自动探测
# 输出变量：PROJECT_ROOT  MINGW_BIN  MINGW_BIN_MSYS  GXX  GDB
#   - PROJECT_ROOT      项目根目录（本文件的上一级，与调用者 CWD 无关）
#   - MINGW_BIN         工具链 bin（Windows 形式，如 D:/... 或 /c/...）
#   - MINGW_BIN_MSYS    MSYS 路径形式（/d/...），Git Bash 里 Windows DLL 搜索只认这种
#   - GXX / GDB         g++ / gdb 全路径（可用环境变量覆盖）

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"

# 自动探测候选路径（g++.exe 与 gdb.exe 都在才算命中）
_candidates=(
  "D:/XC_workspace/msys64/mingw64/bin"
  "/c/msys64/mingw64/bin"
  "/d/msys64/mingw64/bin"
  "/c/tools/msys64/mingw64/bin"
)
if [ -n "$MSYS2_ROOT" ]; then
  _candidates+=("$MSYS2_ROOT/mingw64/bin")
fi

_detect_mingw() {
  local c
  for c in "${_candidates[@]}"; do
    if [ -x "$c/g++.exe" ] && [ -x "$c/gdb.exe" ]; then
      echo "$c"
      return 0
    fi
  done
  return 1
}

if [ -z "$MINGW_BIN" ] && [ -f "$SCRIPT_DIR/toolchain.config" ]; then
  MINGW_BIN="$(grep -E '^MINGW_BIN=' "$SCRIPT_DIR/toolchain.config" | head -1 | sed 's/^MINGW_BIN=//')"
fi

if [ -z "$MINGW_BIN" ]; then
  MINGW_BIN="$(_detect_mingw)" || {
    echo "✗ 未找到 MinGW 工具链（g++.exe / gdb.exe）。" >&2
    echo "  请运行 tools/setup.sh 生成配置，或设置环境变量 MINGW_BIN。" >&2
    exit 1
  }
fi

if command -v cygpath >/dev/null 2>&1; then
  MINGW_BIN_MSYS="$(cygpath -u "$MINGW_BIN")"
else
  MINGW_BIN_MSYS="$MINGW_BIN"
fi

GXX="${GXX:-$MINGW_BIN/g++.exe}"
GDB="${GDB:-$MINGW_BIN/gdb.exe}"

export PROJECT_ROOT MINGW_BIN MINGW_BIN_MSYS GXX GDB
export PATH="$MINGW_BIN_MSYS:$PATH"
