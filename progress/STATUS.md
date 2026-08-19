# 学习进度快照 Learning Status

> **本文件是「会话恢复点」**：Claude 每次会话**第一步读这里**，结束前**回写这里**。
> 配套：`ROADMAP.md`（全局路线）/ `progress/PROGRESS.md`（历史日志）。
> 三处保持同步，本文件是「现在进行到哪」的单一答案。

## 当前状态 Current Status（截至 2026-08-19）

**正在做 In progress：**

- **M3-1 高频容器（M3 收尾扩展）** —— 内容生成 ✅（2026-08-14）；A 区热身练习 1-4 review 通过（2026-08-17）；**B 区练习 05 review 通过（2026-08-19）**：编译 0 警告、输出与格式检查全通过；06-09 待完成。
- **M6 · gdb 调试入门** —— 文档/示例/练习已生成，用户已在 VS Code 可视化调试走通断点/单步；`01_debug_me.cpp` 越界 bug 待独立定位（可随时并行练）。

**下一步 Next：**

1. **完成 M3-1 B 区练习 06-09**（06 括号匹配 / 07 约瑟夫环 / 08 前 K 大 / 09 deque 回文），写完回来 review → C 区 10 综合 → 自评表全 ✅ 收官。
2. M6 gdb 的 `01_debug_me.cpp` 越界 bug 可随时并行练。

**已完成 Done：**

- **M3-1 高频容器 —— 内容生成 ✅（2026-08-14）**：`docs/03-1-high-frequency-containers.md`（unordered_map/set 哈希平均 O(1)、priority_queue 堆默认最大堆/greater 最小堆/Top-K 最小堆模式、stack/queue 适配器 LIFO/FIFO、deque 两端 O(1)；复杂度速查升级选型 + 9 条易错点）+ `examples/03-1/` 4 示例（编译 0 警告 + 运行验证 + format 全过）+ `practice/03-1/exercises.md` 10 练习（A 热身 ①-④ / B 核心 ⑤ unordered_set 去重存在性 ⑥ 括号匹配 LeetCode20 ⑦ 约瑟夫环 queue ⑧ Top-K 最小堆 ⑨ deque 回文 / C 综合 ⑩ 前 K 高频词堆解法）+ 10 参考答案（编译 0 警告 + 用例全对 + format 全过）。**待用户练习**。
- **M3 · STL 容器与算法 —— 完成 ✅（2026-08-14）**：练习 1-10 全部 review 通过 + 自评表全 ✅（vector/string/map-set/迭代器/algorithm/综合选型 6 项全熟练）。收官题练习 10 容器选型：一轮返工补齐——B 复杂度（map 插入 O(log n) 非 O(1)）、C 均摊 O(1) + 扩容 O(n)、D 三操作（`+=`/find+npos/getline）、E 核心坑（`std::binary_search` 要随机访问迭代器，set 迭代器不满足 → vector+sort+unique 组合）。**模块收官，下一站 M3-1 高频容器**。
- **M3 练习 9 review 通过 ✅（2026-08-14）**：D 区综合 ⑨ 词频 Top-K——getline+istringstream 分词、map 计数、vector<pair> 收集、sort+lambda 复合比较（次数降序、并列字典序），5 用例全对（含 6 词只打前 3、并列字典序、不足 3 词全打边界）。两轮返工：① 打印全部词 → 限前 3；② `std::min(output.size(), 3)` 编译失败（模板推导不做隐式转换，`size_t` vs `int` 不匹配）→ 改 `std::min<size_t>` 显式指定类型，顺带掌握 size_t/int 混用坑。编译 0 警告 + format 全过。M3 仅剩 ⑩。
- **M3 练习 7-8 review 通过 ✅（2026-08-13）**：C 区收尾——⑦ 迭代器专项（正向/反向/distance/end 哨兵，补注释答案 + 通用性要点 `!=` 全迭代器通用），⑧ algorithm 专项（sort/accumulate/min-max/count/reverse 原地操作 + target 输入返工，`<numeric>` 头文件正确）。0 警告 + format 全过；练习 7 自留问题（reserve vs `v(n)`）已解答。M3 剩 D 区 9-10。
- **M3 练习 5-6 review 通过 ✅（2026-08-12）**：B 核心收尾（⑤ set 去重+binary_search 输出 `1 2 3 4`/`3 in`，⑥ string 单词统计 5/coding/反转句，用例全对）。可改进点已提示：05 的 `std::sort` 冗余（set 本就有序，拷出已升序）、注释答「为什么」而非复述结论、`bool find` 变量名；06 空输入防御可选。05/06 未强制返工。
- **M3 练习 1-4 review 通过 ✅（2026-08-11）**：A 热身（vector 容量翻倍观察 / string 四连）+ B 核心（vector 重写求平均含「对比 new[]/delete[]」注释 / map 频率统计含两思考题）；全程编译 0 警告 + format.sh --check 全过。
- **文档同步 ✅（2026-08-11）**：修复 2026-08-11 重构后 5 处过期引用——`docs/03` 练习段 4→10 道 A-D 四层、`docs/06` 标题 M6-1→M6、`practice/06/exercises.md` 标题 + 两处 `examples/00-getting-started`→`examples/00` 路径、`examples/00/hello.cpp` 注释路径。
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
