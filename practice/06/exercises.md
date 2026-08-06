# M6-1 · 练习 Exercises — gdb 调试入门

> 规则 Rules：先自己写/自己动手，卡住再看 `solutions/`。
> 环境 Env：在**独立终端**跑（别用 Claude Code 所在的终端）。先 `cd D:\XC_workspace\cpp-learning`；
> PowerShell/cmd 用 `tools\gdb.bat <文件.cpp>`，Git Bash 用 `bash tools/gdb.sh <文件.cpp>`。

## 练习 1 · 基础走读（hello.cpp）— 5 分钟

用 `examples/00-getting-started/hello.cpp` 练手感：

1. `bash tools/gdb.sh examples/00-getting-started/hello.cpp`
2. `break main` → `run` → 停在 main 第几行？
3. `next` 两次，`print year`——输出是 2026 吗？为什么？
4. 继续 `next` 到程序跑完，观察：程序结束后 gdb 还在吗？此时 `print year` 报什么？为什么？
5. `quit` 退出。

## 练习 2 · 揪出隐蔽 bug（01_debug_me.cpp）— 20–30 分钟 ⭐ 本节核心

```bash
bash tools/gdb.sh examples/06/01_debug_me.cpp
```

先**直接运行**看症状（编译后再 `./build/01_debug_me.exe`），记下输出哪里不对。然后：

1. 用 gdb 定位：这个函数按设计该算 `v[i] + v[i+1]`，`data = {1,2,3,4}` 时正确输出应该是哪几个数？
2. 在第 18 行（`result.push_back(p[i] + p[i + 1])`）设断点，`run`。
3. 每 `continue` 一次打印一次 `print i` 和 `print p[i+1]`，把 4 次循环的值记下来：
   - `i=0` 时 `p[i+1]` 该是几？（应该 2）
   - `i=3`（最后一次）时 `p[i+1]` 是多少？**这个值哪里来的？**（提示：`n=4`，`p` 指向的缓冲区只有 4 个元素，下标合法范围是 0..3）
4. 用 `print n` 确认元素个数，想清楚：当 `i` 到 `n-1` 时，`p[i+1]` 就是 `p[n]`——**读到了缓冲区末尾之外**。这就是越界读（out-of-bounds read）。
5. 修复：把 `01_debug_me.cpp` 复制到 `practice/06/` 下（命名 `01_debug_me_fixed.cpp`），改对循环边界，编译运行确认输出 `3 5 7`（3 个数）。
6. 用 gdb 在**修复后的版本**上确认循环只跑 3 次。

## 练习 3 · 挑战：条件断点 + 调用栈（optional，15 分钟）

改练 `practice/01/solutions/06_swap_ptr.cpp`（指针版 swap，用 `step` 进函数看 `*p` 怎么变）：

1. `step`（`s`）进入 `swap` 函数，用 `print p`（指针值）和 `print *p`（指向的值）对比进入前后的变化。
2. 练条件断点：`break swap if *x == 3`（只在特定值时才停）。
3. 在某个深一点的调用处用 `bt` 看调用栈，再用 `frame 0` / `frame 1` 切换层。

## 自评 Self-Check

| 能力 | 自评（✅ / 🔶 / ❌） |
| --- | --- |
| 会设断点、单步、打印变量 |  |
| 能解释「断点停在将要执行的行」 |  |
| 能用 gdb 独立找到越界读 bug |  |
| 能说出「程序退出后 gdb 还在」的意义 |  |
| 会用 `bt` 看调用栈 |  |

完成练习后回来找 Claude review，把自评表和你的诊断结论带上。
