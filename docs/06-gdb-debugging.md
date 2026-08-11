# M6-1 · gdb 调试入门 | GDB Debugging Basics

> 目标 Goals：会用 gdb 设断点、单步、看变量、查调用栈，独立揪出一个隐蔽 bug ｜
> 预计时间 Est. time：45–60 分钟 ｜ 难度 Difficulty：⭐⭐

## 本节要点 Key Points

- gdb 是 GNU 调试器，用来**运行时观察程序**：停在哪里、变量是什么、调用链如何。
- 三大能力：**断点 break**（想停在哪）· **单步 step/next**（怎么走）· **查看 print/bt**（停下来看什么）。
- 关键心智模型：断点/单步停在**「将要执行的那一行」**，这一行还没跑。
- 程序跑完后 gdb 进程**仍然活着**——窗口不关，可继续看、重跑、quit。

## 正文 Body

### 1. 为什么学 gdb（Why gdb）

程序有 bug 时通常只有两种症状：

| 症状 | 直觉做法 | 缺陷 |
| --- | --- | --- |
| 崩溃/段错误 | 猜哪行崩 | 猜不准，崩溃点常远离真正原因 |
| **输出不对但不崩** | 加 `cout` 打印 | 打满代码、要重编译，改完还得删 |

gdb 不用改代码：在**任意行**停住，看那一刻的**所有变量**，一次看清。这是工程能力的基本功，面试和刷题排错都用得上。

### 2. 启动（Launch）

脚本**自适应**：项目放哪都能跑（脚本从自身位置定位项目根），工具链位置由 `tools\toolchain.config` 解析（详见 CLAUDE.md）。只需两个前提：

1. **在独立终端跑**——gdb 是交互式的，会占住整个终端，别在 Claude Code 所在的终端里跑；
2. **PowerShell / cmd 里没有 `bash` 命令**——用 Windows 原生版 `.bat`；Git Bash 里才有 `bash`，用 `.sh`。

**Git Bash：**

```bash
bash tools/gdb.sh examples/06/01_debug_me.cpp
```

**PowerShell / cmd（本机日常用这个）：**

```powershell
tools\gdb.bat examples\06\01_debug_me.cpp
```

**VS Code 任务（最省事）：** 打开目标 `.cpp` → 终端菜单 → 运行任务 → **「Debug current C++ file (gdb)」**，自动以项目目录跑 `gdb.bat`。

`.sh` 和 `.bat` 效果一样：自动带 `-g` 编译 → 进 gdb。也可以自己编译后直接进 gdb（PowerShell/cmd 用 `build.bat`，Git Bash 用 `build.sh`）：

```powershell
tools\build.bat examples\06\01_debug_me.cpp   # 只编译到 build\
gdb build\01_debug_me.exe
```

> `-g` 生成调试信息是前提——没有它 gdb 看不到变量名和行号。

### 3. 核心命令 Core Commands

| 命令 | 缩写 | 作用 | 类比 |
| --- | --- | --- | --- |
| `run` | `r` | 启动/重启程序（`r 参数` 可带参） | 播放 |
| `break 行号` / `break 函数名` | `b` | 设断点 | 书签 |
| `next` | `n` | 单步，**不进入**函数 | 一步跨过函数调用 |
| `step` | `s` | 单步，**进入**函数内部 | 跟进函数里 |
| `continue` | `c` | 跑到下一个断点 | 快进 |
| `print 变量` | `p` | 打印变量/表达式 | 偷看 |
| `list` | `l` | 显示当前源码 | 翻页 |
| `backtrace` | `bt` | 打印调用栈（谁调了我） | 回放 |
| `info locals` | `i l` | 看当前函数所有局部变量 | 一览 |
| `quit` | `q` | 退出 | 关机 |

输入 `help` 随时查帮助；敲命令后按**回车**重复上一条（比如连按回车连 `next`）。

### 4. 三步调试法（The 3-step recipe）

```text
① b 18           → 在可疑行设断点
② run            → 跑起来，停在 18 行
③ p i; n; p ...  → 打印、单步、再看
```

配合 `c` 在多次循环命中之间跳转。多数 bug 都是「在某一行，某个变量不符合预期」——三步法就是在那个点停下来盯着看。

### 5. 调用栈 Backtrace

程序崩了、或停在了深层函数里，`bt` 打印整条调用链（最上面是当前行）：

```text
(gdb) bt
#0  adjacent_sums(...) at 01_debug_me.cpp:18
#1  main() at 01_debug_me.cpp:25
```

看到 `#1 main` 就知道是 main 第 25 行调进来的。`frame 1` 切到 main 那层看它的变量。

### 6. 程序退出后，窗口不关（The key payoff）

```text
[Inferior 1 (process 12345) exited normally]   ← 程序结束了
(gdb) print year
No symbol "year" in current context.            ← 局部变量随 main 销毁
(gdb)                                           ← 但 gdb 还活着！
```

程序结束后 gdb 不退出：你可以 `b` 设新断点、`r` 重跑、看够了 `q`。**这正好解决「return 0 弹窗就关」的问题——gdb 自己就是那个不会关的容器。**

## 代码示例 Examples → `examples/06/`

- **`01_debug_me.cpp`** — 一个输出错误但**不崩不报警告**的程序。你的第一个 gdb 实战靶子。先别改它，用 gdb 找出病因（练习见下）。

## 易错点 Common Pitfalls

1. **断点停在「将要执行」的那行**。`next` 停在 `year = 2026` 那行时，`year` 还是未初始化的 0。想看某行的结果，`next` 到**下一行**。
2. **程序退出后局部变量全没了**（上例的 `No symbol`）。要查就在退出前设断点或 `b return` 附近。
3. **越界读不一定会崩**。`p[n]` 读 vector 缓冲区后一个元素通常是**垃圾值**而不是崩溃——所以「运行正常」≠「没 bug」。这正是 gdb 有存在感的地方。
4. **无符号类型 `size_t` 不会负**。`i < n` 里 `i` 到 `n-1` 仍满足，若有 `i+1` 就越界。
5. 忘记 `-g` 编译 → gdb 说 `No symbol table`。用 `tools/gdb.sh` 不会踩。
6. **单步走出 `main` 会跳到 `crtexe.c`**（MinGW CRT 启动文件，如 `...\mingw-w64-crt\crt\crtexe.c`）。因为 `main` 是被 `mainCRTStartup` 调用的——程序真正入口在 CRT 里，`main` 返回后控制权交回它，`ExitProcess` 收尾。**这不是 bug**。想看 main 结尾就停住（`Shift+F5` 停 / 在 `return 0` 前一行检查），不要用 `F10` 一步跨出 main。

## 练习 Exercises → `practice/06/exercises.md`

去练 `practice/06/exercises.md`。规则不变：**先自己动手**，卡住了再看 `solutions/`。

## 自测 Self-Check

完成练习后自查：

- [ ] 不用 `cout`，用 gdb 找出 `01_debug_me.cpp` 的病根（哪一行、哪个变量、为什么）
- [ ] 能解释为什么输出是 4 个数而不是 3 个
- [ ] 在修复后的版本上，用 gdb 验证输出正确
- [ ] 会用 `bt` 说出「当前停在哪一层、谁调进来的」

对照答案：`practice/06/solutions/01_debug_me.md`
