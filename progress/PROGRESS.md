# 学习进度日志 Learning Progress Log

> 每次 Claude 学习会话结束后，在此追加一条记录。最新在最上面。

## 会话记录 Sessions

### 2026-08-06 · M1 练习 1/2 review + M7 预习 sieve

- **做了什么**：用户完成并 review：练习 1（预测输出，5 题全对：整数除法截断/显式转换/bool 显示/char 算术）、练习 2（isPrime，达标：n<2 处理 + 提前返回 + 循环到 √n）。顺带讲透复杂度（O(√n)），并应要求现场学**埃拉托色尼筛法**（`practice/07/sieve.cpp`，O(N log log N)，用户理解「从 i*i 开始」的原理正确）。
- **反馈点**：① 提醒用户删除代码里的 `#ifdef` 死脚手架（已清）；② `size()` 返回 size_t 赋给 int 的习惯；③ 项目用 K&R 括号风格。
- **验证**：两个练习 + sieve 全部编译 0 警告、输出正确（含 sieve(2)/sieve(30) 边界）。
- **结论**：M1 已过 2/6；用户基础扎实（类型转换、函数、算法思维）。
- **下一步建议**：继续 M1 练习 3（找最大值）；完成后进 4/5/6。

- **需求**：用户要求「进度写进项目，每次启动 Claude Code 了解当前进度」，选择**保留进度 + 强化机制**。
- **改动**：① 新建 `progress/STATUS.md`（会话恢复点：当前状态/下一步/已完成/回写规范）；② CLAUDE.md 顶部新增「⚡ 会话启动协议」（第一步必读 STATUS.md，结束前三处回写）；③ ROADMAP「当前焦点」改为指向 STATUS.md。
- **结论**：今后每次会话启动，Claude 先读 STATUS.md 并向用户复述进度；进度三处一致（STATUS / PROGRESS / ROADMAP）。
- **下一步建议**：用户完成 M1 练习 review，或继续 M6-1 gdb 练习。

- **需求**：让其他 agent / 其他机器部署本项目时，能根据实际位置自适应，不再依赖硬编码路径。
- **产出**：
  - `tools/toolchain.config`（工具链单一配置源）+ `tools/common.sh` / `tools/toolchain.bat`（共享解析器，解析顺序：env `MINGW_BIN` > config > 自动探测）；
  - 6 个工具脚本全部改为「从自身位置定位项目根」（`BASH_SOURCE` / `%~dp0`）+ 工具链配置化——在任意目录都能跑；
  - `tools/setup.bat` / `setup.sh`：探测工具链 → 重写 config → 从 `.vscode/*.template` 重新生成 `launch.json` / `c_cpp_properties.json`（占位符 `__MINGW_BIN__`）；
  - 模板：`launch.json.template`、`c_cpp_properties.json.template`。
- **踩坑（重要）**：.bat 文件里的 UTF-8 中文注释在 GBK 系统（zh-CN cmd）会破坏命令解析（`for /f`、`call` 崩）。**约定：所有 .bat 保持纯 ASCII**（已全部转换），中文注释只留在 .sh 和文档里。
- **验证**：从 `C:\Users\admin` / `/tmp`（项目外目录）跑 build.bat / compile.bat / gdb.bat / build.sh / compile.sh / setup.sh 全部通过 ✅；setup 正确生成 launch.json（正斜杠形式）✅；DLL 同步正常 ✅。
- **下一步建议**：部署后跑一次 `tools\setup.bat` 再开 VS Code；继续 M1/M6 学习。

- **需求**：用户说「顺带学一下 gdb」——兼解决「调试弹窗在 return 0 就关」的痛点（gdb 进程跑完不退出，窗口天然不关）。
- **产出**：`docs/06-gdb-debugging.md`（启动/核心命令/三步调试法/调用栈/易错点）、`examples/06/01_debug_me.cpp`（静默越界读靶子：输出 4 个数应为 3 个，`-Wall` 不报、运行不崩）、`practice/06/exercises.md`（基础走读 + 找 bug + 挑战题 + 自评表）、`practice/06/solutions/01_debug_me.md`（参考 gdb 会话 + 病因 + 修复）。
- **验证**：示例 0 警告编译 ✅、静默错误输出 `3 5 7 4` ✅、gdb 定位出 `i=3` 时 `p[i+1]` 越界（垃圾值）✅。
- **环境发现**：MSYS2 的 `vector::operator[]` 默认带断言（`_GLIBCXX_ASSERTIONS`），越界直接 abort；所以示例改用 `data()` 裸指针做成静默 bug（更贴近「不崩也要查」的真实场景）。
- **路线调整**：M6 标记 🔄（gdb 部分进行中），M1 练习继续并行。ROADMAP 已更新。
- **下一步建议**：用户练 gdb 后回来 review（自评表 + 诊断结论）；M6 余下（编译警告、多文件、make）待续。

- **需求**：用户在用 Claude Code CLI（集成终端里）时按 F5/运行，输出抢占终端焦点、把 CLI 顶走。
- **改动**：① `compile.bat` / `compile.sh` 运行改走独立弹窗（`start ... cmd /v:on /k`，窗口保持打开并显示真实退出码）；② `launch.json` `externalConsole: true`（F5 调试程序 I/O 进独立控制台）；③ `tasks.json` 预编译任务 `reveal: never`（编译不抢焦点，之前改的）。
- **验证**：命令链延迟展开正确（Exit code: 0）✅、`start` 引号链可解析 ✅、真实运行 compile.bat 弹出 `cmd /k` 窗口并保持 ✅。
- **已知残留**：F5 调试启动时 VS Code 仍会自动打开「调试控制台」面板（gdb 消息，非程序输出）——如需完全隔离 Claude Code，把 CLI 挪到独立终端窗口。
- **下一步建议**：用户实测运行/调试体验。

- **需求**：VS Code F5 调试 `hello.cpp` 报「Segmentation fault」，随后重编译报 `Permission denied`（exe 被卡死进程锁住）。
- **排查**：hello.cpp 独立运行正常、gdb CLI/MI 多种方式跑都正常 → 问题在 cppdbg 调试环境。gdb 加载列表显示 `libstdc++-6.dll` 等**来自 Git 的 mingw64** 而非 MSYS2；查系统 PATH 发现 **MSYS2 mingw64\bin 根本不在 PATH**，反而有 Qt 的旧 mingw73 目录。cc1plus 静默失败是 `libmpfr-6.dll` 找不到（Git Bash 里 `D:/...` 正斜杠 PATH 形式不生效，脚本用 `/d/...` 才对）。
- **根因**：exe 在调试会话里解析到**旧版/不兼容的 libstdc++-6.dll** → 首次 `std::cout` 段错误。同机器还有第三方注入 hook（`winahframe64.dll` / OCular Agent）为次要风险。
- **修复**：给全部 6 个工具脚本（compile/bulid/gdb 的 .sh+.bat）加「项目级运行时」——每次编译把 MSYS2 的 3 个运行库同步进 `build/`，利用 Windows「exe 所在目录优先于 PATH」的规则绕开系统 PATH 污染。零系统改动、零静态链接。CLAUDE.md 已补充该约束。
- **验证**：全新 build 目录自愈重建 ✅、VS Code preLaunchTask 路径（cmd /c build.bat）✅、污染环境下 gdb MI 调试加载 build/ 本地运行库并正常运行 ✅。
- **结论**：F5 调试恢复正常；`build/` 里的 3 个 DLL 是运行必需，勿删（脚本会自动补回）。
- **下一步建议**：用户重新 F5 验证一次调试体验；继续 M1 练习。

- **需求**：为项目配置独立编译器，摆脱对 Qt 自带 g++ 7.3 的依赖。
- **安装**：MSYS2（清华 TUNA 镜像 90MB 安装器 → 静默装到 `D:\XC_workspace\msys64` → pacman 换 TUNA 源）→ 安装 `mingw-w64-x86_64-gcc/gdb/make`（g++ 16.1.0、GDB 17.2、Make 4.4.1）。
- **踩坑①**：UCRT64 版 cc1plus 无法运行 —— 本机 System32 缺失 `api-ms-win-crt-*.dll`（精简系统清掉了 UCRT API-set 转发文件）。原生应用靠内核 API-set 映射正常，但 MSYS2 加载器需要真实文件。**改用 MINGW64（msvcrt 系，无 UCRT 依赖）**，已验证可编译运行。
- **踩坑②**：Git Bash 的 PATH 里写 `D:/...`（正斜杠）在 Windows DLL 搜索时不生效，cc1plus 找不到 libstdc++ 等 → 脚本必须用 `/d/...`（MSYS 形式，Git Bash 自动转 Windows 形式）或 `D:\...`（反斜杠）。
- **项目切换**：4 个脚本 + `.vscode/c_cpp_properties.json` + CLAUDE.md/README/M0 文档全部指向 `D:\XC_workspace\msys64\mingw64\bin`。旧 Qt g++ 7.3 弃用。
- **验证**：hello、M1 全部 4 示例、5 参考答案、compile.bat(cmd)、gdb.sh、VS Code 任务命令、`std::filesystem` 全部通过。UCRT64 坏包已卸载。
- **结论**：独立编译器就绪。`<filesystem>` 限制解除，CLAUDE.md 已更新。
- **下一步建议**：继续 M1 语法查漏补缺练习。

### 2026-08-06 · M1 语法查漏补缺（生成，待用户练习）

- **做了什么**：生成 M1 完整内容 —— `docs/01-syntax-refresh.md`、4 个示例（`examples/01/`）、6 道自测练习（`practice/01/exercises.md`）+ 参考答案（`practice/01/solutions/`）。
- **验证**：示例 4/4、参考答案 5/5 全部 `tools/compile.sh` 编译运行通过（0 警告 0 错误）。
- **练习 6 特别设计**：指针版 swap 作为 M2 指针模块的「钩子」，触发用户对 `*`/`&` 的疑问。
- **结论**：闭环验证成功 —— Claude 生成→编译验证→用户练习→review 的流程可跑通。
- **下一步建议**：等用户完成自测并按自评表反馈 → 全 ✅ 进 M2；有薄弱 → 先补课。

### 2026-08-06 · M0 环境与工作流搭建（初始搭建）

- **做了什么**：创建项目结构（docs/examples/practice/tools/progress）、生成学习协议（CLAUDE.md）、路线图（ROADMAP.md）、方法论文档（GUIDE.md）、编译工具链（tools/compile.*、tools/gdb.*）。
- **环境确认**：g++ 7.3.0（MinGW-W64，`C:\Qt\Qt5.12.12\Tools\mingw730_64\bin`）、gdb、mingw32-make；无 cmake；C++17（⚠️ 无 `<filesystem>`）。
- **结论**：地基已就绪，等待首次学习会话验证闭环。
- **下一步建议**：跑通 `hello.cpp` → 进入 M1 语法查漏补缺。
