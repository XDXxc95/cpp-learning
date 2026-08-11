#!/usr/bin/env bash
# tools/format.sh — 用 clang-format 按 LLVM 风格格式化 C++ 源码
# 用法 Usage:
#   tools/format.sh <文件.cpp> [更多文件...]     # 原地格式化（-i）
#   tools/format.sh --check <文件.cpp> [更多...] # 只检查不改写；存在不规范时退出码非 0
# clang-format 定位 Priority：环境变量 CLANG_FORMAT > VS Code C/C++ 扩展内置 > PATH
# 风格 Style：读取「被格式化文件向上最近」的 .clang-format（项目根已配 BasedOnStyle: LLVM）
set -uo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"

usage() {
  echo "用法 Usage: $0 [--check] <文件.cpp> [更多文件...]" >&2
  echo "  --check   只检查是否符合格式（不改写），有不规范时退出码非 0" >&2
}

find_clang_format() {
  # 1) 显式环境变量 CLANG_FORMAT
  if [ -n "${CLANG_FORMAT:-}" ]; then
    if command -v "$CLANG_FORMAT" >/dev/null 2>&1 || [ -x "$CLANG_FORMAT" ]; then
      printf '%s\n' "$CLANG_FORMAT"
      return 0
    fi
    echo "✗ CLANG_FORMAT=$CLANG_FORMAT 不可执行" >&2
    return 1
  fi
  # 2) VS Code C/C++ 扩展内置 clang-format（目录名随扩展版本变化，用通配匹配）
  local base="${HOME:-$USERPROFILE}"
  if [ -n "$base" ]; then
    for d in "$base"/.vscode/extensions/ms-vscode.cpptools-*/LLVM/bin; do
      if [ -x "$d/clang-format.exe" ]; then
        printf '%s\n' "$d/clang-format.exe"
        return 0
      fi
    done
  fi
  # 3) PATH
  if command -v clang-format >/dev/null 2>&1; then
    command -v clang-format
    return 0
  fi
  return 1
}

CHECK=0
FILES=()
while [ $# -gt 0 ]; do
  case "$1" in
    --check) CHECK=1 ;;
    -h|--help) usage; exit 0 ;;
    -*) echo "未知选项 Unknown option: $1" >&2; usage; exit 2 ;;
    *) FILES+=("$1") ;;
  esac
  shift
done
[ "${#FILES[@]}" -gt 0 ] || { usage; exit 2; }

CF="$(find_clang_format)" || {
  echo "✗ 未找到 clang-format。" >&2
  echo "  安装 VS Code C/C++ 扩展（内置 clang-format 22.x），或安装 LLVM 后设置环境变量 CLANG_FORMAT。" >&2
  exit 1
}
echo "==> clang-format: $CF"

# 解析文件（相对路径按项目根兜底，兼容任意调用目录）
resolved=()
for f in "${FILES[@]}"; do
  if [ ! -f "$f" ] && [ -f "$PROJECT_ROOT/$f" ]; then f="$PROJECT_ROOT/$f"; fi
  if [ ! -f "$f" ]; then
    echo "错误 Error: 找不到文件 $f" >&2
    exit 1
  fi
  resolved+=("$f")
done

style_opts=(-style=file --fallback-style=LLVM)
if [ "$CHECK" -eq 1 ]; then
  "$CF" "${style_opts[@]}" --dry-run -Werror "${resolved[@]}"
  rc=$?
  if [ $rc -eq 0 ]; then
    echo "OK：全部符合格式 All files are formatted."
  else
    echo "有文件不符合格式（见上方 warning 行）。" >&2
  fi
  exit $rc
else
  "$CF" "${style_opts[@]}" -i "${resolved[@]}"
  rc=$?
  if [ $rc -eq 0 ]; then
    echo "OK：已格式化 Format done."
  else
    echo "✗ 格式化失败 Format failed." >&2
  fi
  exit $rc
fi
