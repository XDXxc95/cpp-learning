# C++ Learning · Claude Code 推进式学习项目

> Claude Code-driven C++ learning journey: bilingual docs, compile-verified examples, exercises with solutions, and git-tracked progress. From basics to algorithms & job-ready skills.

## 这是什么 | What is this

用 **Claude Code** 驱动的 C++ 学习系统：文档、示例、练习由 Claude 在每次对话中逐步生成，你真实编译、亲手练习，进度实时调整、里程碑全部落在 git 历史里。

- 📚 **文档** `docs/` — 每模块一篇学习文档（中英对照）
- 💡 **示例** `examples/` — 可直接编译运行的讲解代码
- ✍️ **练习** `practice/` — 你的实操区（你自己写代码，Claude 只提供题目与参考答案）
- 🧭 **路线图** `ROADMAP.md` — 学习计划本体，随进度实时调整
- 📊 **进度** `progress/` — 会话恢复点（STATUS.md）+ 每次会话日志
- 🛠 **工具** `tools/` — 一键编译 / gdb 调试 / 环境自适应脚本

## 学习循环 | The Learning Loop

```text
你: 发起对话 → Claude: 生成文档+示例+练习(编译验证通过)
    → 你: 在 practice/ 亲手写练习
    → 你: 回来说「写完了/卡住了」
    → Claude: review、反馈、更新进度
    → 下一模块
```

## 在新机器上配置 | Setup on a New Machine

项目**位置/工具链自适应**：不依赖固定路径，clone 后跑一次配置即可。

### 1. 装依赖 | Dependencies

- **Git**（含 Git Bash）
- **MSYS2**（推荐清华镜像）→ 装完运行 `msys2.exe`，在 MSYS2 终端里执行：

  ```bash
  pacman -S --needed mingw-w64-x86_64-gcc mingw-w64-x86_64-gdb mingw-w64-x86_64-make
  ```

  ⚠️ 选 **MINGW64** 环境（默认终端即可），不要 UCRT64（部分精简系统缺 UCRT DLL 跑不了）。
- **VS Code + C/C++ 扩展**（可选，调试用）

### 2. Clone

```bash
git clone <你的仓库地址> cpp-learning
cd cpp-learning
```

### 3. 配置工具链 | Configure toolchain

```bash
# Git Bash（推荐）：
tools/setup.sh
# 或 Windows cmd：
tools\setup.bat
```

它会：探测 MSYS2 工具链位置 → 写入 `tools/toolchain.config`（机器相关，**已被 gitignore，不会进仓库**）→ 生成 `.vscode/launch.json` / `c_cpp_properties.json`。装好依赖后跑完这一步，重启 VS Code 即可。

### 4. 验证 | Verify

```bash
tools/compile.sh examples/00-getting-started/hello.cpp   # Git Bash
tools\compile.bat examples\00-getting-started\hello.cpp  # cmd
```

看到 `Hello, World!` 即环境正常。

### 工具链解析优先级

```text
环境变量 MINGW_BIN  >  tools/toolchain.config  >  自动探测常见路径
```

即使不跑 setup 也能编译（脚本自动探测）；跑 setup 只是把探测结果固化 + 生成 VS Code 配置。改编译器位置：改 `tools/toolchain.config` 后重跑 setup，或设环境变量 `MINGW_BIN`。

### 部署到新位置的注意事项

- `.bat` 脚本必须保持**纯 ASCII**（cmd 按 ANSI 代码页解析）；`.sh` 是 UTF-8 无限制
- `build/` 里的 3 个运行库 DLL（`libstdc++-6.dll` 等）是运行必需，勿删——脚本每次编译自动补回，避免系统 PATH 里旧 mingw DLL 污染
- 仓库不含任何本机绝对路径：`toolchain.config`、`.vscode/launch.json`、`.vscode/c_cpp_properties.json` 均为 gitignore 的生成物

## 目录结构 | Directory Layout

```text
cpp-learning/
├── README.md              # 本文件
├── CLAUDE.md              # Claude 学习协议（自动加载，别删）
├── GUIDE.md               # 学习方法论详解
├── ROADMAP.md             # 路线图 + 进度总表
├── docs/                  # 学习文档（每模块一篇，中英对照）
├── examples/              # 示例代码（可编译运行）
├── practice/              # 你的练习区（自己写代码）
│   └── NN/solutions/      # 参考答案（对照用，先自己写）
├── tools/                 # 编译/调试/setup 脚本
├── progress/              # 进度快照 + 会话日志
└── build/                 # 编译产物（可随时删除，DLL 自动补回）
```

## 常用命令 | Useful Commands

| 目的 | 命令 |
| --- | --- |
| 编译+运行 | `tools/compile.sh 文件.cpp` / `tools\compile.bat 文件.cpp` |
| 只编译不运行 | `tools/build.sh 文件.cpp` / `tools\build.bat 文件.cpp` |
| gdb 调试 | `tools/gdb.sh 文件.cpp`（先编译含调试信息再进 gdb） |
| 配置工具链 | `tools/setup.sh` / `tools\setup.bat`（新机器必跑） |
| 清编译产物 | 删除 `build/` 目录（DLL 会自动补回） |

## VS Code 快捷键 Shortcuts

在 VS Code 中**打开一个 `.cpp` 文件**后（焦点在编辑器里）：

| 快捷键 | 作用 |
| --- | --- |
| **F5** | **调试**当前文件（launch.json，编辑器断点 + 变量/监视/调用栈面板，I/O 走独立控制台） |
| Ctrl+Shift+B | 编译并运行当前文件（任务默认快捷键） |
| Ctrl+Shift+P → Tasks: Run Task | 选「Compile only」只编译 / 「Debug (gdb)」终端调试 |

> 调试配置在 `.vscode/launch.json`（setup 生成），快捷键配置在 `.vscode/keybindings.json`（个人设置，gitignore），删掉即恢复默认。
> 想练**原始 gdb 命令**（学习调试原理）时，终端用 `tools/gdb.sh 文件.cpp`。

## 开始学习 | Start learning

在项目根目录启动 Claude，然后说：

```bash
继续学习，下一个模块
```

或者指定模块：`开始模块 M2 引用与指针`。Claude 会按 `CLAUDE.md` 协议生成文档、示例和练习，并引导你动手。
