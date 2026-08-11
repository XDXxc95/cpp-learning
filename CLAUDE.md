# CLAUDE.md — C++ 学习推进协议

> 本文件是**本项目的学习引擎**，每次在此目录启动 `claude` 时自动加载。
> 它是约束你（Claude）在每次学习会话中如何行动的规则。先读它，再行动。

## ⚡ 会话启动协议（每次会话第一步，必须执行）

1. **先读 `progress/STATUS.md`** —— 当前进度快照：进行到哪个模块、下一步做什么。
2. 需要全局路线时再读 `ROADMAP.md`；需要历史细节时读 `progress/PROGRESS.md`。
3. **向用户复述当前进度**，确认从哪继续（除非用户已明确指定任务）。
4. 会话结束前**必须回写**：更新 `progress/STATUS.md` + 在 `progress/PROGRESS.md` 追加一条日志 + 同步 `ROADMAP.md` 状态。三处一致才算回写完成。

## 项目定位

这是一个由 **Claude Code 驱动的 C++ 学习项目**。学习内容（文档 / 示例 / 练习题目）不是一次性写完的，而是**在每次用户发起的 Claude 会话中，按本协议逐步生成**，进度实时回写。用户通过「发起对话 → 生成内容 → 自己练习 → 回来 review → 推进下一模块」的循环学习。

## 用户画像（勿偏离）

- **水平**：学过 C++ 基础——懂变量/循环/函数/基本类语法，但**未系统深入** STL、内存管理、现代 C++ 特性。不要从 Hello World 逐字讲起，但也不要假设对方懂移动语义。
- **目标**：① 通用软件开发 / 求职 ② 算法 / 刷题（LeetCode 类）。
- **节奏**：不固定、随缘。模块必须**自包含**，可随时暂停续接；每次会话先按顶部「会话启动协议」读 `progress/STATUS.md` 恢复上下文。
- **文档语言**：**中英对照**（关键概念中英都写，代码/术语保留英文）。

## 学习推进循环（每次会话的骨架）

用户会以下面任一方式开启会话：
- 「继续学习，下一个模块」/「开始模块 X」
- 「我写完练习了，帮我 review」
- 「我卡在练习 X 了，帮我看看」
- 「根据我的情况调整一下路线」

你的行动序列：

1. **读上下文**：读 `ROADMAP.md`（路线+状态）与 `progress/PROGRESS.md`（日志），确认当前进度与用户画像。
2. **生成模块内容**（生成新模块时）：写入 `docs/NN-*.md`、`examples/NN/` 示例、`practice/NN/exercises.md`（练习题目）+ `practice/NN/solutions/`（参考答案）。
3. **编译验证**：所有 `examples/` 示例必须先用 `tools/compile.sh <file>` 或 `tools/compile.bat <file>` 编译并运行成功，**确认无警告无错误后才交付给用户**。若示例里有依赖具体输入才能展示的代码，确保默认路径可直接运行。
4. **给用户本次学习指引**：简述本节目标、核心概念、示例清单、练习清单，说明「先自己写，再看参考答案」。
5. **等用户完成练习**。当用户回来 review 时：读用户的练习代码 → 编译运行 → 给出针对性的反馈（正确的地方、可改进处、是否达标）→ 更新进度。
6. **回写进度并提交**：更新 `ROADMAP.md` 模块状态 + `progress/STATUS.md` + 在 `progress/PROGRESS.md` 追加会话日志（日期、做了什么、结论、下一步建议），然后 `git add` + `git commit`。

## 绝对原则

- **练习答案由用户自己写**。Claude 只提供练习题目和参考答案（放在 `solutions/`）。**不要**替用户写 `practice/NN/` 下的练习文件；用户明确要求「直接给我答案」除外，但先提醒练习的意义。
- **示例必须先能编译运行**。交付前用 `tools/compile.*` 验证过；运行失败或带警告的示例不允许交付。
- **进度必须回写且依托 git**。完成一次学习 review 后，不更新 `ROADMAP.md` + `progress/PROGRESS.md` + `progress/STATUS.md` 就结束会话 = 违规；回写后**必须 `git add` + `git commit`**（项目 2026-08 起 git 托管），让每次学习里程碑都落在 git 历史里（练习完成、review 通过、模块推进各一次提交，信息清晰的 commit message）。
- **路线可实时调整**。用户要求改路线时，直接修改 `ROADMAP.md`（增删模块、调顺序、加重点、拆细/精简），不要口头建议完就完事。

## 文档生成规范

- 路径：`docs/NN[-N]-短横线主题.md`，与 `examples/NN[-N]/`、`practice/NN[-N]/` 编号一致。**命名规则（2026-08-10 定）**：目录/文档 = 交付块号——整块交付的模块用 `NN`（如 M1→`01`、M2→`02`），拆分模块用 `NN-N`（如 M3→`03-1`、M6→`06-1`）；不建空壳目录。
- **中英对照**：核心概念用「中文 / English」或「概念（English）」形式；代码、关键字、类型名保留英文。
- 结构模板（可用 markdown）：

  ```markdown
  # MNN · 主题 | English Title
  > 目标 Goals ｜ 预计时间 Est. time ｜ 难度 Difficulty

  ## 本节要点 Key Points
  ## 正文 Body
  ## 代码示例 Examples → 指向 examples/NN/
  ## 易错点 Common Pitfalls
  ## 练习 Exercises → 指向 practice/NN/exercises.md
  ## 自测 Self-Check（答案给出或指向 solutions）
  ```

- 每节控制体量：一次会话一模块，宁可薄而精，不要一次铺完。
- **markdownlint 约定（规则固化在 `.markdownlint.jsonc`）**：仅两条——表格分隔行用 padded 风格 `| --- | --- |`（**不是** `|---|---|`）；表格内管道两侧有空格（全角字符如 `）` 也要隔开）；所有 fenced 代码块必须带语言标签（`cpp` / `bash` / `text`）。写文档直接照此，不要等 lint 报错再改。
- **文档不强制行长等其它规则**（用户 2026-08-10 确认）：MD013 line-length 等告警对中文项目无意义（CJK 每字按 2 列宽，存量文档最长 300+ 视觉列），**文档以可读为准，忽略**；格式化规范只约束代码（`.clang-format` + `tools/format.*`）。

## 编译环境与约束（必须遵守）

- 编译器：`tools/toolchain.config` 的 `MINGW_BIN` 指向（本机当前为 `D:/XC_workspace/msys64/mingw64/bin`，g++ **16.1.0**，MSYS2 MINGW64 发行版；其他机器以 config / 自动探测结果为准）。⚠️ 若用 MSYS2 发行版：选 MINGW64 而非 UCRT64（部分精简系统缺 UCRT 的 `api-ms-win-crt-*.dll`，UCRT64 版 cc1plus 无法运行）。旧 Qt 自带 g++ 7.3 **不要再用**。MSYS2 libstdc++ 默认开 `_GLIBCXX_ASSERTIONS`：`operator[]` 越界直接 abort 报断言——能帮抓越界 bug，但要记住「断言拦截 ≠ 代码正确」。
- 调试器：`tools/toolchain.config` 的 `MINGW_BIN` 定位 `gdb.exe`（本机当前 GDB **17.2**）。另有 `mingw32-make.exe`（GNU Make 4.4.1）。
- **路径自适应（关键，2026-08）**：所有 `tools/*.sh` / `*.bat` 从**脚本自身位置**定位项目根（`BASH_SOURCE` / `%~dp0`），不依赖调用时的当前目录；工具链解析顺序为「环境变量 `MINGW_BIN` → `tools/toolchain.config` → 自动探测常见路径」。部署到新位置/新机器后跑一次 `tools/setup.bat`（或 `setup.sh`）：探测工具链 → 重写 `toolchain.config` → 从 `.vscode/*.template` 重新生成 `launch.json` / `c_cpp_properties.json`。**约定**：`.bat` 文件必须保持**纯 ASCII**（cmd 按 ANSI 代码页解析，UTF-8 中文会破坏命令解析）；`.sh` 是 UTF-8 原生不受限。需要改路径一律改 `toolchain.config`，不要手改散落的硬编码。
- ⚠️ **DLL 污染与项目级运行时（关键，2026-08 修复）**：系统 PATH 里可能混有 Git / Qt 的旧 mingw 目录（如 `C:\Program Files\Git\mingw64\bin`、`C:\Qt\Qt5.12.12\Tools\mingw730_64\bin`），也可能直接指向新工具链（本机即 `D:\Dev_soft\mingw64\bin` 在 PATH 中）。若 exe 解析到**旧版 `libstdc++-6.dll`**，用新 g++ 编译的程序在**调试器下首次 `std::cout` 会段错误**（独立运行可能正常）。因此 `tools/compile.*` / `build.*` / `gdb.*` 每次编译都会把 MSYS2 的 3 个运行库（`libstdc++-6.dll`、`libgcc_s_seh-1.dll`、`libwinpthread-1.dll`）同步进 `build/`——Windows 按「exe 所在目录优先于 PATH」解析 DLL，exe 身边的正确版本绕开一切 PATH 污染。**不要删除 `build/` 里的这 3 个 DLL**；脚本会在下次编译时自动补回。另：Git Bash 里给 Windows 进程加 PATH 必须用 MSYS 路径 `/d/...`，`D:/...` 正斜杠形式在 Windows DLL 搜索里不生效。
- 标准：项目默认 `-std=c++17 -Wall -Wextra -g`（已封装进 `tools/compile.*`，直接用脚本，不要手敲原始命令）。GCC 14+ 完整支持 C++20/23，需要时经用户确认可升级默认标准。
- ✅ `<filesystem>`（`std::filesystem`）**可用**（GCC 8+ 才有，现在已满足）。之前的禁用限制已解除。
- 可用特性：C++11/14/17 全部；C++20 的概念 / ranges / coroutines 也可用，但**默认示例仍按 C++17 风格写**（与路线图一致），除非用户要求示范新特性。
- 库注意：MinGW 下 `-lstdc++` 默认链接，不需要显式。第三方库一律不引入（避免路径地狱）。
- 编码：源码文件统一 UTF-8；Windows 控制台中文可能乱码，示例输出优先用英文或 ASCII，确需中文时用 `std::setlocale` 并在注释里说明。

## 目录职责速查

| 路径 | 谁写 | 作用 |
| --- | --- | --- |
| `docs/` | Claude | 学习文档（每模块一篇） |
| `examples/` | Claude | 可编译运行的示例代码 |
| `practice/NN/` | **用户** | 用户练习代码（Claude 不代写） |
| `practice/NN/exercises.md` | Claude | 练习题目 |
| `practice/NN/solutions/` | Claude | 参考答案（对照用） |
| `tools/` | Claude | 编译/调试脚本 |
| `progress/PROGRESS.md` | Claude | 会话日志 |
| `ROADMAP.md` | Claude | 路线图 + 状态总表 |
| `README.md` | Claude | 项目入口 |

## 常用命令

- 编译并运行：`tools/compile.sh <文件.cpp>`（Git Bash）或 `tools\compile.bat <文件.cpp>`（cmd）。**程序在独立弹窗里运行**（`start ... cmd /c ... & pause`，显示输出与退出码，按任意键后窗口自动关闭），不占用当前终端——这是为了让终端里的 Claude Code CLI 不被运行输出顶走。
- 编译后进 gdb：`tools/gdb.sh <文件.cpp>`
- 格式化（LLVM 风格，项目适配版）：`tools/format.sh <文件.cpp>`（Git Bash）或 `tools\format.bat <文件.cpp>`（cmd），原地格式化；加 `--check` 只检查不改写（有不规范时退出码非 0）。风格配置在根目录 `.clang-format`：`BasedOnStyle: LLVM` + 指针/引用左对齐（保持项目 `int* p` 习惯）+ 中文注释不重排（防拆行损坏）。clang-format 定位：环境变量 `CLANG_FORMAT` > VS Code C/C++ 扩展内置（本机 22.1.3）> PATH。
- 调试：VS Code F5 → cppdbg，`launch.json` 已设 `externalConsole: true`，程序 I/O 走独立控制台窗口；预编译任务 `reveal: never` 不抢焦点。调试器仍会弹出「调试控制台」面板（gdb 消息），属 VS Code 固有行为。VS Code 已开 `editor.formatOnType`，自动补全后按 `.clang-format` 即时套用 LLVM 风格。
- 编译产物在 `build/`，随时可删（运行库 DLL 会被脚本自动补回）。
