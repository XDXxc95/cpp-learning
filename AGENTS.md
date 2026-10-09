# AGENTS.md - AI 工作区协议

本文件是通用 AI 编程助手进入本项目时的入口规则。项目已有更详细的学习协议，见
`CLAUDE.md`；两者冲突时，以用户当前请求和更具体的项目规则为准。

## 每次进入项目先做什么

1. 确认工作区根目录是 `D:\XC_workspace\cpp-learning`（不要假设其他机器使用这个绝对路径）。
2. 先读取 `progress/STATUS.md`，确认当前模块、已完成内容和下一步。
3. 读取 `CLAUDE.md`，了解本项目的学习规则、目录职责和工具链约束。
4. 按任务需要读取 `ROADMAP.md`、`progress/PROGRESS.md`、目标文件和相关题目/答案。
5. 检查 `git status --short`，保留用户已有改动，不重置、不覆盖、不清理无关文件。
6. 如果用户只说“继续”，先用一句话复述当前进度和准备处理的下一项，再开始操作。

不要因为打开了某个文件就跳过上述启动步骤。当前进度的权威来源是
`progress/STATUS.md`，不是 IDE 标签页，也不是文件编号本身。

## 当前已知进度

- 当前模块：M3-1 高频容器。
- A 区练习 1-4 已 review 通过。
- B 区练习 05 已 review 通过。
- B 区练习 06-09 待用户完成并 review；之后是 C 区练习 10 和自评。
- 当前常见焦点：`practice/03-1/06_valid_parentheses.cpp`。

进入项目时仍以 `progress/STATUS.md` 的最新内容为准；本节只是帮助 AI 快速定位。

## 学习项目的目录边界

- `docs/`、`examples/`、`practice/*/solutions/`、`tools/`：AI 可以按请求维护。
- `practice/` 下用户练习骨架和用户实现：默认由用户自己写，AI 负责解释、编译、运行和 review。
- 只有用户明确要求“直接给答案”或明确要求修改练习代码时，AI 才能代写
  `practice/` 下的练习；先说明这会减少练习效果。
- `progress/STATUS.md`、`progress/PROGRESS.md`、`ROADMAP.md`：只有本次任务确实改变了
  学习进度、review 结论或路线时才更新；三处必须保持一致。

## 代码和验证规则

- 源码统一 UTF-8。PowerShell 读取中文源码或 Markdown 时使用
  `Get-Content -Encoding UTF8`，不要把乱码输出当成文件真实内容。
- 手工编辑使用 `apply_patch`，先读取目标文件，改动保持最小。
- C++ 默认按 C++17、`-Wall -Wextra -g` 通过 `tools/build.*` 或 `tools/compile.*` 验证；
  不要绕过项目脚本手敲一套不同的编译命令。
- 修改 C++ 后按需要运行 `tools/format.* --check`；发现格式问题用项目格式化工具修复。
- 至少验证题目给出的示例，并补测明显边界：空输入、提前闭合、未闭合、类型不匹配、重复值、
  `n=0` 或 `k` 边界（以题目适用范围为准）。报告实际运行过的命令和结果。
- `.bat` 文件保持 ASCII；脚本、工具链和运行库规则以 `CLAUDE.md` 及 `tools/` 为准。

## 对话和交付规则

- 用户要求 review 时，先读用户代码并编译运行，再按严重性说明问题、证据和改进建议；不要直接
  把参考答案当作用户代码替换掉。
- 用户要求诊断时先解释原因；只有用户要求修复或请求本身包含修改时才编辑代码。
- 不做无关重构，不删除用户改动，不使用 `git reset --hard` 或 `git checkout --` 恢复文件。
- 完成会改变学习状态的会话时，遵循 `CLAUDE.md`：回写 STATUS、PROGRESS、ROADMAP，并按项目
  约定提交清晰的 git 记录。仅新增配置或普通代码修复不虚构学习进度。
- 结束回复应简要说明改了什么、验证了什么、还有什么未完成；不能声称未执行的测试已通过。

## 常用路径

```text
当前进度：progress/STATUS.md
历史日志：progress/PROGRESS.md
路线图：  ROADMAP.md
学习协议：CLAUDE.md
练习题目：practice/03-1/exercises.md
参考答案：practice/03-1/solutions/
编译工具：tools/build.* / tools/compile.*
格式工具：tools/format.*
```
