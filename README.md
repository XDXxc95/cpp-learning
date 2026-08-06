# C++ Learning · Claude Code 推进式学习项目

> 用 **Claude Code** 驱动的 C++ 学习系统：文档、示例、练习由 Claude 在每次对话中逐步生成，你真实编译、亲手练习，进度实时调整。

## 这是什么 | What is this

- 📚 **文档** `docs/` — 每模块一篇学习文档（中英对照）
- 💡 **示例** `examples/` — 可直接编译运行的讲解代码
- ✍️ **练习** `practice/` — 你的实操区（你自己写代码）
- 🧭 **路线图** `ROADMAP.md` — 学习计划本体，随进度实时调整
- 📊 **进度** `progress/PROGRESS.md` — 每次会话的日志
- 🛠 **工具** `tools/` — 一键编译 / gdb 调试脚本

## 快速开始 | Quick Start

### 1. 准备环境 | Prepare environment

本项目使用**独立安装的 MSYS2 工具链**（不再依赖 Qt 自带的旧编译器）：

- 编译器：`D:\XC_workspace\msys64\mingw64\bin\g++.exe`（g++ **16.1.0**）
- 调试器：`D:\XC_workspace\msys64\mingw64\bin\gdb.exe`（GDB 17.2）
- 编译标准：C++17（GCC 16 完整支持 C++20/23，需要时可在脚本里升级）

> 如果你的 g++ 路径不同，改 `tools/compile.bat` / `tools/compile.sh` 顶部的 `GXX` 变量即可。

### 2. 跑通第一个程序 | Run your first program

```bash
# Git Bash / 命令行（在本项目根目录）
tools/compile.sh examples/00-getting-started/hello.cpp
# Windows cmd:
tools\compile.bat examples\00-getting-started\hello.cpp
```

看到 `Hello, World!` 即环境正常。

### 3. 开始学习 | Start learning

在项目根目录启动 Claude，然后说：

```
继续学习，下一个模块
```

或者指定模块：`开始模块 M2 引用与指针`。Claude 会按 `CLAUDE.md` 协议生成文档、示例和练习，并引导你动手。

## 学习循环 | The Learning Loop

```
你: 发起对话 → Claude: 生成文档+示例+练习(编译验证通过)
    → 你: 在 practice/ 亲手写练习
    → 你: 回来说「写完了/卡住了」
    → Claude: review、反馈、更新进度
    → 下一模块
```

## 目录结构 | Directory Layout

```
cpp-learning/
├── README.md              # 本文件
├── CLAUDE.md              # Claude 学习协议（自动加载，别删）
├── GUIDE.md               # 学习方法论详解
├── ROADMAP.md             # 路线图 + 进度总表
├── docs/                  # 学习文档
├── examples/              # 示例代码（可编译运行）
├── practice/              # 你的练习区
│   └── NN/solutions/      # 参考答案（对照用，先自己写）
├── tools/                 # 编译/调试脚本
├── progress/              # 进度日志
└── build/                 # 编译产物（可随时删除）
```

## 常用命令 | Useful Commands

| 目的 | 命令 |
|---|---|
| 编译+运行 | `tools/compile.sh 文件.cpp` / `tools\compile.bat 文件.cpp` |
| 调试 | `tools/gdb.sh 文件.cpp`（先编译含调试信息再进 gdb） |
| 清编译产物 | 删除 `build/` 目录 |
| 换个编译器 | 改脚本里 `GXX` 变量 |

## VS Code 快捷键 Shortcuts

在 VS Code 中**打开一个 `.cpp` 文件**后（焦点在编辑器里）：

| 快捷键 | 作用 |
|---|---|
| **F5** | **调试**当前文件（launch.json，编辑器断点 + 变量/监视/调用栈面板） |
| **Shift+F5** | **编译并运行**当前文件（输出在下方终端） |
| Ctrl+F5 | 无调试运行当前文件（VS Code 默认，同样走 launch.json 编译） |
| Ctrl+Shift+B | 编译并运行（与 Shift+F5 相同，任务默认快捷键） |

> 快捷键只对 C++ 文件生效，不会干扰其他文件。配置在 `.vscode/keybindings.json`（工作区级）、调试配置在 `.vscode/launch.json`，删掉即恢复默认。
> 想练**原始 gdb 命令**（学习调试原理）时，终端用 `tools/gdb.sh 文件.cpp`，或在命令面板 Tasks: Run Task 里选 "Debug current C++ file (gdb)"。
