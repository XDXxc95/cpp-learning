# 学习进度快照 Learning Status

> **本文件是「会话恢复点」**：Claude 每次会话**第一步读这里**，结束前**回写这里**。
> 配套：`ROADMAP.md`（全局路线）/ `progress/PROGRESS.md`（历史日志）。
> 三处保持同步，本文件是「现在进行到哪」的单一答案。

## 当前状态 Current Status（截至 2026-08-10）

**正在做 In progress：**

- **M3 · STL 容器与算法** —— **M3-1 string + vector 内容已生成 ✅，练习 1-4 待用户完成**；M3-2 迭代器+algorithm / M3-3 map+set+复杂度 待续。
- **M6-1 · gdb 调试入门** —— 文档/示例/练习已生成，用户已在 VS Code 可视化调试走通断点/单步；`01_debug_me.cpp` 越界 bug 待独立定位（可随时并行练）。

**下一步 Next：**

1. **用户完成 M3-1 练习 1-4**（`01_string_reverse` / `02_vector_stats` / `03_pass_by` + 思考题）→ 回来 review + 填自评表 → 全 ✅ 进 M3-2。
2. M6-1 越界 bug 定位可随时并行做。

**已完成 Done：**

- **M3-1 string + vector 内容生成 ✅（2026-08-10）**：`docs/03-1-string-and-vector.md`、`examples/03-1/` 3 示例、`practice/03-1/exercises.md` + 3 骨架 + `solutions/` 3 答案。全部编译 0 警告 + 运行验证（string 操作 / vector 操作 / 手动 new[] vs vector 对比 + const& 传参）。内容自包含，M3 按 03-1/03-2/03-3 拆分子模块。
- **M2 引用/指针/内存模型 —— 收官 ✅（2026-08-10）**：练习 1-4 全过 review，自评表 4 项全 ✅。补课「判断引用 vs 指针」判断树（存在性 → 改绑 → 引用），5 道判断题选择全对；第 4 题（改绑必须指针）理由跑偏，修正后掌握「引用不能改绑」。
- **M2 练习 3 通过 review ✅（2026-08-10）**：动态数组求平均，new[]/delete[] 配对 + 防御 n<=0。首轮两处问题：① `for (size_t i…)` 与 int n 比较触发 `-Wsign-compare` 警告 ② 裸 `throw;`（无异常在飞）→ `std::terminate` abort、退出码 3；改后 0 警告，n=5/0/-3 三路径验证通过（`avg = 4.50` / stderr 报错 + 退出码 1）。
- **M2 练习 1-2 通过 review ✅（2026-08-07）**：练习 1 预测输出 4 题全对（措辞精确化：引用即同一对象、指针改绑表述）；练习 2 找 3 个内存 bug 全修好（泄漏/双删/悬垂，输出 `1 42 7` 正确），注释已清理。
- **M2 引用/指针/内存模型 —— 内容生成 ✅（2026-08-06）**：`docs/02-pointers-and-memory.md`、`examples/02/` 4 示例（编译 0 警告 + 运行验证）、`practice/02/exercises.md` + 4 个骨架 + `solutions/`（3 个 cpp 已编译验证，预测题答案核对一致）。
- **M1 语法查漏补缺 ✅（2026-08-06 完成）** —— 6/6 练习全过 review、自评全熟练；顺带完成 M7 预习（sieve）。
- M0 环境与工作流 ✅（工具链自适应：`tools/toolchain.config` + `tools/setup.*`，部署到新位置跑一次 setup）
- **本机部署 ✅（2026-08-06）**：工具链 `D:\Dev_soft\mingw64\bin`（g++ 14.2.0 / gdb 14.2 / make 4.4.1，MinGW-Builds 独立发行版）→ setup 已生成 config + `.vscode` 配置，hello 编译运行验证通过；CLAUDE.md 工具链段已改为机制化描述（以 config 为准）
- 环境修复（2026-08-06）：DLL 污染段错误、运行弹窗、自适应部署 —— 细节见 PROGRESS 日志
- M6-1 gdb 入门内容生成 ✅（待练习）

## 悬挂事项 Open Items

- （无）

---

### 回写规范（Claude 每次会话结束做）

1. 更新本文件的「当前状态 / 下一步 / 已完成」；
2. `progress/PROGRESS.md` 顶部追加一条会话日志（日期、做了什么、结论、下一步）；
3. 同步 `ROADMAP.md` 模块状态与「当前焦点」。
