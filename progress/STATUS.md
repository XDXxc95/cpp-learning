# 学习进度快照 Learning Status

> **本文件是「会话恢复点」**：Claude 每次会话**第一步读这里**，结束前**回写这里**。
> 配套：`ROADMAP.md`（全局路线）/ `progress/PROGRESS.md`（历史日志）。
> 三处保持同步，本文件是「现在进行到哪」的单一答案。

## 当前状态 Current Status（截至 2026-08-11）

**正在做 In progress：**

- **M3 · STL 容器与算法** —— 内容已生成 ✅（文档/4 示例/10 练习+答案，全部编译验证），**练习 1-10 待用户完成（A 热身 → B 核心 → C 迭代器/算法 → D 综合）**。
- **M6 · gdb 调试入门** —— 文档/示例/练习已生成，用户已在 VS Code 可视化调试走通断点/单步；`01_debug_me.cpp` 越界 bug 待独立定位（可随时并行练）。

**下一步 Next：**

1. **完成 M3 练习 1-10**（按 A 热身 → B 核心 → C 迭代器/算法 → D 综合 四层推进，题目见 `practice/03/exercises.md`）。
2. 完成后填文末自评表 → 回来 review → 全 ✅ → 收尾 M3-1 高频容器 → 进 M4-1 面向对象核心。
3. M6 gdb 的 `01_debug_me.cpp` 越界 bug 可随时并行练。

**已完成 Done：**

- **M3 STL 容器与算法 —— 内容生成 ✅（2026-08-10）**：`docs/03-stl-containers-and-algorithms.md` + `examples/03/` 4 示例（01 vector / 02 string / 03 map_set / 04 algorithms，编译 0 警告 + 运行验证）+ `practice/03/exercises.md` + 4 骨架 + `solutions/`（4/4 编译 0 警告 + 用例全对）。覆盖 vector 自动内存管理 / string / map-set 有序查找 / 迭代器区间 `[begin,end)` / algorithm 常用算法 / 复杂度选型。
- **M2 · 引用/指针/内存模型 —— 完成 ✅（2026-08-10）**：练习 1-4 全部 review 通过 + 自评全 ✅。练习 3 动态数组求平均（new[]/delete[] 配对、防御 n<=0、double 除法）；练习 4 find/setMin（指针返回 nullptr 表达「找不到」、引用就地修改 + 3 思考题，口诀「是否需要判断是否存在」）；练习 1 预测输出 / 练习 2 找 3 内存 bug 于 2026-08-07 通过。本机另有「判断引用 vs 指针」补课记录（见 PROGRESS）。
- **格式化工具链（LLVM 风格）✅（2026-08-10，commit `b7f1abe`）**：`.clang-format` 项目适配版（LLVM 基础 + 指针/引用左对齐保持 `int* p` + 中文注释不重排 + 列宽 100）+ `tools/format.sh/.bat`（自动定位 clang-format：环境变量 > VS Code 扩展内置 22.1.3 > PATH）+ VS Code `defaultFormatter` 固定 C/C++ 扩展（消掉「选择格式化器」弹窗）。
- **M2 练习 1-2 通过 review ✅（2026-08-07）**：练习 1 预测输出 4 题全对（措辞精确化：引用即同一对象、指针改绑表述）；练习 2 找 3 个内存 bug 全修好（泄漏/双删/悬垂，输出 `1 42 7` 正确），注释已清理。
- **M2 引用/指针/内存模型 —— 内容生成 ✅（2026-08-06）**：`docs/02-pointers-and-memory.md`、`examples/02/` 4 示例（编译 0 警告 + 运行验证）、`practice/02/exercises.md` + 4 个骨架 + `solutions/`（3 个 cpp 已编译验证，预测题答案核对一致）。
- **M1 语法查漏补缺 ✅（2026-08-06 完成）** —— 6/6 练习全过 review、自评全熟练；顺带完成 M7 预习（sieve）。
- M0 环境与工作流 ✅（工具链自适应：`tools/toolchain.config` + `tools/setup.*`，部署到新位置跑一次 setup）
- **本机部署 ✅（2026-08-06）**：工具链 `D:\Dev_soft\mingw64\bin`（g++ 14.2.0 / gdb 14.2 / make 4.4.1，MinGW-Builds 独立发行版）→ setup 已生成 config + `.vscode` 配置，hello 编译运行验证通过；CLAUDE.md 工具链段已改为机制化描述（以 config 为准）
- 环境修复（2026-08-06）：DLL 污染段错误、运行弹窗、自适应部署 —— 细节见 PROGRESS 日志
- M6 gdb 入门内容生成 ✅（待练习）

## 悬挂事项 Open Items

- （无）

---

### 回写规范（Claude 每次会话结束做）

1. 更新本文件的「当前状态 / 下一步 / 已完成」；
2. `progress/PROGRESS.md` 顶部追加一条会话日志（日期、做了什么、结论、下一步）；
3. 同步 `ROADMAP.md` 模块状态与「当前焦点」。
