# 学习进度日志 Learning Progress Log

> 每次 Claude 学习会话结束后，在此追加一条记录。最新在最上面。

## 会话记录 Sessions

### 2026-08-12 · M3 练习 5-6 review 通过（B 核心收尾）

- **需求**：用户「继续」，已写完练习 5、6。
- **练习5 set 去重+binary_search ✅**：set 去重升序输出 `1 2 3 4`、`binary_search` 判存在 `3 in`，用例全对。可改进点（已提示，未强制返工）：① `std::sort(out)` **冗余**——set 本就有序，拷到 vector 已升序，白做 O(n log n)，直接遍历 set 打印即可（sort 留给练习 8 专项）；② 查找用 set 自带 `count/find` 更直接，binary_search 用于「有序随机访问区间」，此题练前提合法但不最贴；③ 注释答「为什么必须先排序」只复述结论，原因是**折半查找靠与中点比较决定方向，仅有序时方向才成立，无序为未定义行为**；④ 变量名 `bool find` 与 `std::find` 同名易混、尾随空格小瑕疵。
- **练习6 string 单词统计 ✅**：getline+istringstream 分词、count=5、最长单词并列取第一个（`>` 严格大于做对）、反向迭代器反转 `gnidoc dna ++C evol I`，全对。唯一可选项：空输入（直接回车）防御 `if (s.empty())`。
- **结论**：B 区 4 题（3-6）全部通过；编译 0 警告，用例全对。
- **下一步建议**：C 区 ⑦ 迭代器专项、⑧ `<algorithm>` 专项 → D 区 ⑨ 词频 Top-K、⑩ 容器选型 → 自评表 → 全 ✅ 收尾 M3-1 高频容器 → 进 M4-1。

### 2026-08-11 · M3 练习 1-4 review 通过（A 热身 + B 核心）+ 文档同步 + 入库

- **需求**：用户「继续」→ 做 M3 练习；另反馈「学习文档感觉没更新」。
- **M3 练习 review（4 题全过）**：
  - **练习1 vector 热身 ✅**：capacity **0→1→2→4→4→8→8** 翻倍演示正确；size/`[]` 读、range-for 全做到。多塞 3 个数（2,42,52）顺带演示 4→8 是加分，但头部注释「塞入 3 个数」与代码 6 个不符，已提示（未改，可留）。
  - **练习2 string 热身 ✅**：拼接 HelloWorld / substr→Wor / find("lo")→3 + npos / getline 含空格整行，全对。
  - **练习3 vector 重写求平均 ✅**：防御 n<=0（cerr+return 1，实测退出码 1）、`vector<double> a(n)`、fixed+setprecision(2)、avg 4.50 全对；无 -Wsign-compare。首轮**缺「对比 new[]/delete[]」注释**（必写）→ 补「初始化和置空」→ 达标；升华：核心是 RAII——析构自动释放，泄漏/双删/悬垂风险一并消失。
  - **练习4 map 频率 ✅**：计数、升序遍历结果 `1 2 / 2 1 / 3 3` 正确；首轮**输出格式偏题**（`key : 1 value : 2`）→ 改 `数 次数`；注释① 红黑树有序、② `[]` 自动插默认值理解正确（① 措辞「自动更新节点顺序」→ 更精确是「插入时按键比较维持有序」，已提示）；尾部多余空行已删。
  - **格式**：04 原 Allman 括号 → format.sh 对齐项目 LLVM/K&R；4 文件 `--check` 全过，编译 0 警告。
- **文档同步（5 处过期引用）**：`docs/03` 练习段「4 道练习」→ **10 道 A-D 四层**（与 2026-08-11 重构一致）；`docs/06` 标题 M6-1→M6（模块已合并整块）；`practice/06/exercises.md` 标题 M6-1→M6 + 两处 `examples/00-getting-started`→`examples/00`；`examples/00/hello.cpp` 注释编译路径。复查 grep 无残留。
- **入库**：docs 同步 + M3 练习 1-4 分两笔 commit。
- **下一步建议**：M3 练习 5-6（B 区 set 去重+binary_search / string 单词统计）→ C 区 7-8（迭代器专项 / algorithm 专项）→ D 区 9-10（词频 Top-K / 容器选型）→ 自评表 → 全 ✅ 收尾 M3-1 高频容器 → 进 M4-1。

### 2026-08-11 · 项目设计检视：对照双目标补齐路线缺口

- **需求**：用户「检视整个项目设计，能否实现既定目标（通用开发/求职 + 算法/刷题）」。
- **检视结论**：学习机制（循环/自适应/进度三处同步/0 警告纪律）经得起推敲；但内容图有 6 个实质缺口 + 2 个结构风险。
- **缺口（对求职）**：CMake 0 覆盖（M6 只有 make）、文件 I/O（fstream）0 覆盖、异常处理未当主题、模板仅顺带。
- **缺口（对刷题）**：unordered_map/set、priority_queue、stack/queue 0 覆盖（LeetCode 高频容器；09 词频题本就是堆场景，现用 sort 硬解）；递归未作主题；双指针/滑动窗口/前缀和 0 覆盖。
- **结构风险**：M4（继承+多态+虚函数+拷贝控制）、M7（复杂度+竞赛 STL+数据结构+题型）各一模块超载。
- **路线改动（已落 ROADMAP）**：新增 M3-1 高频容器（M3 收尾扩展）、M5-2 I/O 与异常；M4 拆 M4-1 核心 + M4-2 拷贝控制；M5 拆 M5-1 现代 C++ + M5-2 I/O 异常；M6 增补 CMake；M7 拆 M7-1 算法基础（复杂度/递归/竞赛 STL）+ M7-2 题型专项；CLAUDE.md 命名规则重新启用 NN-N。
- **下一步建议**：M3 当前 10 题先做；M3-1 高频容器内容待生成（做 priority_queue 时把 09 题的 sort 改法留作对照）。

### 2026-08-11 · M3 练习按「由浅入深 + 全面覆盖」分层重构（4 → 10 题）

- **需求**：用户定练习设计原则——数量不设限，按学习深入分层（先基础热身、再核心应用、后综合/学后练习），全面覆盖该节知识。已写入 CLAUDE.md 文档生成规范 + 记忆。
- **改动**：`practice/03/` 重构为 **A 热身（2）→ B 核心（4）→ C 迭代器/算法（2）→ D 综合/学后（2）** 四层共 10 题：
  - A：01_vector_warmup（含 capacity 翻倍观察）、02_string_warmup；
  - B：原 4 题平移重编号（03_vector_avg / 04_frequency / 05_dedup / 06_string_ops），04 补问「`map[key]++` 键不存在时会发生什么」；
  - C：07_iterators（`[begin,end)` 左闭右开 / 反向 / distance）、08_algorithms（sort/accumulate/minmax/count/reverse）；
  - D：09_word_freq_top（string+map+vector+sort 综合，LeetCode 前 K 高频词同款）、10_container_choice（选型设计题，补复杂度/选型零覆盖）。
- **验证**：10 骨架 + 10 答案全部编译 0 警告；运行验证 capacity 1→2→4、distance=5、词频 `a 3 / cat 2 / dog 1` 等正确。
- **结论**：M3 知识覆盖闭环（vector/string/map/set/迭代器/algorithm/复杂度选型全有对应练习）。
- **下一步建议**：用户从 A 区热身做起 → 逐层推进 → 完成 10 题回来 review + 自评 → 全 ✅ 进 M4。

### 2026-08-11 · 双端同步：合并本机与远端的并行会话

- **需求**：用户「同步远端的代码」。发现本机 main 与 origin/main 各领先 5 个提交——本机为当天下午（13:19–14:36）会话，远端为当晚（22:58–23:50）另一台机器上的会话，两者并行做了同一批里程碑。
- **结构决策（以远端为准）**：M3 改为**整块交付 `03/`**（STL 容器与算法），M6 改为 `06/`（不再拆 06-1）。本机 M3-1（string+vector）内容与 `03-1`/`06-1` 目录被远端结构取代，**全部保留在本机 git 历史里**：用户 M3-1 练习1 完整解法在 commit `d5184f8`，可 `git show d5184f8:practice/03-1/01_string_reverse.cpp` 取回。
- **保留的本机独有内容**：CLAUDE.md 工具链段（本机 MSYS2 g++ 16.1 / gdb 17.2；远端的 14.2 / Dev_soft 是本机错误信息，未采纳）。
- **日志说明**：下面同时保留本机（下午）与远端（当晚）的会话条目——M2 练习3/4、M3 内容各有两条记录，属并行会话实况，不改写。
- **git 基础**：GitHub SSH 22 端口被拒 → `~/.ssh/config` 增加 `Host github.com` → `HostName ssh.github.com` / `Port 443`。
- **下一步建议**：M3 练习 1-4 待用户完成 → review + 自评 → 全 ✅ 进 M4。

### 2026-08-10 · M3 STL 容器与算法 —— 内容生成（待练习）【远端当晚会话】

- **需求**：M2 全 ✅ 后按规则进入 M3，用户确认「继续」。
- **产出**：
  - `docs/03-stl-containers-and-algorithms.md`：STL 三大件（容器/迭代器/算法）→ vector（对比 M2 new[]/delete[]，遍历三件套，capacity 翻倍）→ string（拼接/子串/find/getline/c_str）→ map/set（有序 O(log n)，`map[key]` 自动插默认值坑）→ 迭代器（`[begin,end)` 区间、失效）→ `<algorithm>` 常用算法（sort/binary_search/find/count/accumulate/min_max/reverse）→ 复杂度速查与选型口诀 → 8 条易错点 → 自测。
  - `examples/03/` 4 示例：01_vector_basics（含 capacity 增长实测）/ 02_string_ops / 03_map_set / 04_algorithms；全部编译 0 警告 + 运行验证。
  - `practice/03/exercises.md`：4 练习（vector 重写求平均——直接呼应 M2 思考题答案 / map 频率统计 / set 去重+binary_search / string 单词统计反转）+ 自评表（5 行）；4 个骨架文件；`solutions/` 4 份参考答案（编译 0 警告，用例全对：avg 4.50、频率 1 2 / 2 1 / 3 3、dedup 1 2 3 4 + 3 in、words=5 longest=coding 反转正确）。
- **结论**：M3 内容闭环就绪（生成→编译验证→骨架→答案）。ROADMAP M3 → 🔄。
- **下一步建议**：用户完成练习 1-4 后回来 review + 自评 → 全 ✅ 进 M4。

### 2026-08-10 · M2 练习 4 review ✅ + M2 全部完成（全 ✅ 进 M3）【远端当晚会话】

- **需求**：继续 M2，做完练习 4。
- **做了什么**：
  - **练习 4 review ✅**：用户独立完成 `04_ref_or_ptr.cpp`。`find` 遍历返回 `&arr[i]` / 落空 `nullptr`，main 里两条路径都测（`3` / `not found`）；`setMin` `if(a<b) b=a; else a=b;` 两数取小；用 `sizeof(a)/sizeof(int)` 没硬编码长度。编译 0 警告，输出 `3 / not found / 5,3 -> 3,3` 全对。
  - **思考题确认**：①「需要判断是否存在」→ 本质是引用没有空引用，nullptr 表达「找不到」；②「函数内使用简单 + 形参约束一定存在」→ 补调用方也简单（不用 `&`）；③ 口诀「是否需要判断是否存在」→ 凝练为「可能没有结果→指针，必然存在→引用」。口诀无标准答案，用户自拟达标。
  - **收尾**：删残留 `// 占位` 注释 + `format.sh` 对齐（`--check` 通过）；用户自评全 ✅（填入 `exercises.md` 自评表）。
- **结论**：**M2 全部完成 ✅**（练习 1-4 全过 + 自评全熟练）。M2 的心智模型——引用即别名、堆生命周期、new/delete 配对、指针表达「可能不存在」——是 M3 容器与 M4 拷贝控制的地基。
- **下一步建议**：进入 **M3 STL 容器与算法**（vector/string/map/set/迭代器/algorithm/复杂度），与算法刷题直接相关；M6-1 gdb 越界 bug 可并行。

### 2026-08-10 · 格式化工具链（LLVM 风格）+ M2 练习 3 review ✅【远端当晚会话】

- **需求**：继续 M2 学习（做练习 3-4）；顺带「把 llvm 规范设置好」。
- **做了什么**：
  - **LLVM 风格配置（commit `b7f1abe`）**：项目已有 `.clang-format`（`BasedOnStyle: LLVM`）但 clang-format 不在 PATH → 新增 `tools/format.sh` / `format.bat`（定位顺序：环境变量 `CLANG_FORMAT` > VS Code C/C++ 扩展内置 clang-format 22.1.3 > PATH；路径自适应；`--check` 只检查不改写）。实测**纯 LLVM 有破坏性**：把全库 `int*`→`int *`、并把中文长注释重排成不连贯断行（`找不到返回 / nullptr 造一个数组…`）→ `.clang-format` 改为**项目适配版**：`PointerAlignment/ReferenceAlignment: Left`（保持 `int* p`/`int& r`）、`ReflowComments: false`（防拆中文注释）、`ColumnLimit: 100`（80 对中文注释按 2 列宽计太紧）。`.vscode/settings.json` 固定 `editor.defaultFormatter: ms-vscode.cpptools`（同时装了 xaver.clang-format 会弹「选择格式化器」，默认键 Shift+Alt+F，Shift+Ctrl+F 是查找）。CLAUDE.md 常用命令补 format 用法。验证：中文注释零改动、指针风格保持、`for` 排版乱码被规范化、`--check` 每文件残留仅 1-5 条美观性对齐。
  - **练习 3 review ✅**：用户独立完成 `03_dynamic_avg.cpp`。编译 0 警告；边界测试 n=5→`avg: 4.50` / n=1→`1.50` / n=0,-3→`n <= 0` 退出码 1 全过。做对点：new[]/delete[] 配对、`sum/n` 是 double 除法（sum 为 double 没踩整数除法坑）、`n` 初始化 0 兜底 cin 读取失败、cerr 报错 + return 1、delete 后置 nullptr。用户自查 `format.sh` 对齐风格（大括号/指针/include 排序），Claude 删残留 `// TODO` 注释，`format --check` 通过。
- **结论**：M2 练习 3 达标 ✅；格式化工具链就绪（VS Code Shift+Alt+F 与 `tools/format.*` 双通道，项目适配版不破坏中文注释与现有风格）。
- **下一步建议**：练习 4（`04_ref_or_ptr.cpp`：find 指针返回 + setMin 引用 + 注释答 3 思考题）→ 填自评表 → review 全 ✅ 进 M3。

### 2026-08-10 · 目录层级统一（结构清理）【本机下午会话；已被远端 M3/M6 整块结构取代，保留作历史】

- **需求**：用户反馈「序号文件夹的层次有点混乱」。
- **问题盘点**：① `examples/` / `practice/` 下残留一批**空壳目录**（`03`/`04`/`05`/`07`/`08`，git 不追踪空目录、只在磁盘上）；② M3 子模块用 `03-1`，但 M6-1 却放 `06` —— 子模块命名不统一；③ `00-getting-started` 是「NN-主题」风格，与其他 `NN` 不一致。
- **约定（当时固化进 CLAUDE.md）**：目录/文档名 = **交付块号** —— 整块交付的模块用 `NN`（M1→`01`、M2→`02`），拆分模块用 `NN-N`（M3→`03-1`、M6→`06-1`）；**不建空壳目录**。⚠️ 2026-08-11 双端合并后 M3/M6 改为整块 `03`/`06`（见顶部条目）。
- **改动**：`git mv` `docs/06-gdb-debugging.md`→`06-1-gdb-debugging.md`、`examples/06/`→`06-1/`、`practice/06/`→`06-1/`、`examples/00-getting-started/`→`00/`；删除空壳 `examples/{03,04,05,07,08}`、`practice/{03,04,05,08}`（`practice/07/sieve.cpp` 保留）；同步更新引用。
- **结论**：PROGRESS 历史日志不改写（记录当时路径实况）。
- **下一步建议**：学习状态不变——M3-1 练习 1-4 待用户完成。

### 2026-08-10 · M3-1 string + vector 内容生成（待练习）【本机下午会话；已被远端 M3 STL 取代，保留作历史】

- **需求**：M2 收官后按 AskUserQuestion 确认「现在就生成 M3-1」。
- **产出**：
  - `docs/03-1-string-and-vector.md`：容器=内存管理的答案（回答 M2 练习3 的 sieve 悬案）→ string 常用成员 + find/npos → vector 常用成员 + 遍历 → 手动 new[]/delete[] vs vector 对比表 → 传参铁则（const& 首选）→ 易错点 5 条 → 自测 5 问；
  - `examples/03-1/` 3 示例：01_string_basics（创建/拼接/find+npos/substr/遍历）、02_vector_basics（创建/push_back/[] vs at/front-back/pop_back）、03_vector_vs_manual（M2 练习3 同款动态求平均，手动 vs vector 并排 + const& 传参 + 空容器防御）；
  - `practice/03-1/exercises.md` + 3 骨架 + `solutions/` 3 答案：练习1 string 反转（长度/空格数/反转）、练习2 vector 统计（max/min/avg，禁手动 new/delete，n<=0 防御）、练习3 const& 传参（sum vs sumByValue）、练习4 思考题。
- **验证**：示例 3/3、答案 3/3 编译 0 警告；运行验证输出正确（反转 `oof dlrow olleh`、max 9/min -1/avg 3.60、n=0 报错退出码 1、sum 双版本 15/15）。
- **结论**：M3-1 内容闭环就绪。ROADMAP M3 → 🔄。
- **下一步建议**：用户完成 M3-1 练习 1-4 → 回来 review + 自评 → 全 ✅ 进 M3-2（迭代器 + algorithm）。

### 2026-08-10 · M2 练习 4 完成 + 补课「引用 vs 指针」→ M2 收官 ✅【本机下午会话】

- **需求**：接上轮，review 练习 4 → 用户补 missing 测试与思考题 → 自评表「判断何时引用/指针」一栏主动要求补课。
- **练习 4 review（三轮）**：首轮 `s.length` 编译错误（C 数组无 `.length`，Java 语法）+ 缺 not-found 测试 + setMin 未打印 + 三元表达式当语句 + 思考题②空白。第二轮用户修 `sizeof`、补 not-found 分支、setMin 改 if-else。第三轮补 setMin 打印 + 思考题②（「内部简洁、形参清晰、避免忘判 nullptr」——自述，达标）。最终编译 0 警告，输出 `find : 4` / `not find` / `3 3`。
- **补课「判断引用 vs 指针」**：讲判断树三问（①会不存在吗→指针 ②要改绑/指针运算吗→指针 ③否则引用，只读用 `const T&`）。5 道当堂判断题选择全对，但第 4 题（先指 A 再指 B）理由跑偏（写成「可能指向 nullptr」）；纠正为「引用不能改绑」——铁律②。用户复述确认：「需要改变指向对象、绑定关系改变，只能用指针」✅。
- **自评表**：4 项全 ✅（2026-08-10），已填进 `practice/02/exercises.md`。
- **结论**：M2 引用/指针/内存模型收官 ✅（练习 1-4 + 自评全过）。
- **下一步建议**：生成并进入 M3 STL 容器与算法（薄而精，一次一小节；M6-1 gdb 越界 bug 可并行）。

### 2026-08-10 · M2 练习 3 完成 ✅【本机下午会话】

- **需求**：用户「继续」→ 按协议读 STATUS，发现 git status 里 `practice/02/03_dynamic_avg.cpp` 已改，直接进入练习 3 review。
- **review（两轮）**：第一轮核心逻辑达标（new[]/delete[] 配对 + 删后置空、填值 `(i+1)*1.5`、fixed+setprecision(2)、防御检查放在 new 之前），但两处未过：① `for (size_t i = 0; i < n; i++)` 与 int n 比较 → `-Wsign-compare` 警告（违反 0 警告规则）；② 防御分支裸 `throw;` —— 实测 n=0/-3 输出 `terminate called without an active exception`（std::terminate → abort，退出码 3），不是「报错退出」。第二轮用户改为 `int i` + `std::cerr << "n must be positive\n"; return 1;`。
- **验证**：0 警告 0 错误；n=5 → `avg = 4.50` 退出码 0；n=0 / n=-3 → stderr 报错 + 退出码 1，全部通过。
- **教学点**：裸 `throw;` 无异常在飞时 = terminate（看似崩溃）；报错退出标准式是 `std::cerr` + `return 非0`。
- **结论**：M2 练习 1-3 全部通过 review ✅。
- **下一步建议**：练习 4（`04_ref_or_ptr.cpp`：find 返回指针 / setMin 引用 / 3 思考题）→ 自评表 → 全 ✅ 进 M3。

### 2026-08-07 · 本机部署 + M2 练习 1-2 完成 ✅

- **需求**：部署项目 → 看 M2 文档 → 开始练习。
- **做了什么**：
  - **部署**：工具链实为 `D:\Dev_soft\mingw64\bin`（g++ 14.2.0 / gdb 14.2 / make 4.4.1，MinGW-Builds 独立发行版，非 MSYS2）→ `MINGW_BIN=... tools/setup.sh` 生成 `toolchain.config` + `.vscode` 配置，hello 编译运行验证通过；CLAUDE.md 工具链段去掉死路径改为机制化描述（commit `0e1a077`）。
  - **文档导读**：带用户完整过 M2 六节（指针心智模型 / 引用三铁律 / 栈 vs 堆 / new-delete 三条规矩 / 5 种内存 bug / 易错点），并给出「文档→练习」映射。
  - **练习 1 review ✅**：4 题预测全对（30 30 30 / 1 12 / 9 / 200 100）；两轮措辞精确化——①「r 同步 x」→「r 与 x 是同一对象」②「p2 的地址值」→「p2 里存的值从 &a 换成 &b」。
  - **练习 2 review ✅（两轮）**：第一轮 Bug B（泄漏）/ C（双删）修复正确，但 Bug A 修复引入 3 个新问题：`memcpy(s, t, n)` 字节数错（第三参数是字节数，运行输出垃圾值 `1.08646e-311`）、调用方 `a` 未 delete（泄漏转移）、VLA `double t[n]` 非标准（-Wall 不含 -Wvla）。第二轮全修好：`new[]` + for 填值 + 调用方 `delete[] a`，输出 `1 42 7`；顺手清理过时注释。
- **结论**：M2 练习 1-2 达标 ✅；练习 2 的迭代过程本身就是「三条规矩」的最佳教学现场。
- **下一步建议**：练习 3（动态数组求平均）→ 练习 4（find/setMin + 3 思考题）→ 自评表 → review 全 ✅ 进 M3。

### 2026-08-06 · 部署到新机器（工具链自适应实战验证）

- **需求**：用户「帮我将这个项目部署好」。
- **做了什么**：检查依赖（Git 2.49 ✅；CLAUDE.md 里写的 `D:\XC_workspace\msys64\mingw64\bin` 等常见路径均不存在）→ 定位真实工具链 `D:\Dev_soft\mingw64\bin`（g++ **14.2.0** MinGW-Builds 独立发行版、gdb 14.2、make 4.4.1，3 个运行库 DLL 齐全）→ 用 `MINGW_BIN=D:/Dev_soft/mingw64/bin tools/setup.sh` 生成 `tools/toolchain.config` + 从模板生成 `.vscode/launch.json` / `c_cpp_properties.json` → `tools/compile.sh examples/00-getting-started/hello.cpp` 编译 0 警告，直接运行 `build/hello.exe` 输出 `Hello, World!`（退出码 0），3 个 DLL 自动同步进 `build/`。
- **顺手修正**：CLAUDE.md 工具链段原写死 `D:\XC_workspace\msys64\mingw64\bin`（g++ 16.1.0 / gdb 17.2，本机不存在）→ 改为机制化描述（工具链以 `toolchain.config` 为准，附本机当前值）；DLL 污染段去掉过时的 PATH 组成断言；「GCC 16」→「GCC 14+」。符合项目「仓库不含本机绝对路径」原则。
- **验证**：git 工作区仅 CLAUDE.md 与 progress 变更；`toolchain.config` / `.vscode` 生成物 / `build/` 均在 .gitignore 内，无本机路径泄漏进仓库。
- **结论**：M0 自适应部署机制在真实新环境复测通过（含非 MSYS2 的独立 MinGW 发行版；普通自动探测候选不含 `D:\Dev_soft`，靠 config/环境变量机制解决）。
- **下一步建议**：学习状态不变——继续 M2 练习 1-4，完成后回来 review。

### 2026-08-06 · M2 引用/指针/内存模型 —— 内容生成（待练习）

- **需求**：M1 全 ✅ 后按规则进入 M2。用户确认「继续」。
- **产出**：
  - `docs/02-pointers-and-memory.md`：指针心智模型（&/*、步长、nullptr）→ 引用三铁律 + 引用/指针对比表（正式回答 M1 练习 6 思考题）→ 栈 vs 堆（含平台布局差异实测）→ new/delete 三条规矩 → 5 种内存 bug 对照表 → 易错点 7 条；
  - `examples/02/` 4 示例：①引用/指针行为差异（改绑、别名）②栈堆地址与递归栈下降 ③new/delete 配对 + 构造/析构自动调用 ④5 种内存 bug 注释讲解 + 安全对照（危险代码全部注释掉，运行稳定）；
  - `practice/02/exercises.md`：预测输出 / 找 3 个内存 bug / 动态数组求平均 / 引用 vs 指针思考题（find + setMin 实操）+ 自评表；4 个用户骨架文件（01-04，直接填代码）；`solutions/` 4 份答案。
- **验证**：示例 4/4、参考答案 3 cpp、练习 1 骨架全部编译 0 警告运行正确；练习 2 骨架故意保留 `-Wreturn-local-addr` 警告作为教学点（编译器抓悬垂）；03 防御分支（n=0）退出码验证 ✅。
- **环境发现**：Windows PE 布局下静态区在高地址、堆最低——与教科书 Linux 图相反，示例 02 注释与文档已按实测修正（「规律别背数字」）。
- **结论**：M2 内容闭环就绪（生成→编译验证→骨架→答案）。ROADMAP M2 → 🔄。
- **下一步建议**：用户完成练习 1-4 后回来 review + 自评 → 全 ✅ 进 M3。

### 2026-08-06 · M1 语法查漏补缺 —— 完成 ✅

- **做了什么**：用户完成全部 6 道自测练习并逐个 review：① 预测输出（全对）② isPrime（达标+复杂度 O(√n)）③ 找最大值（下标/range-for）④ BankAccount 封装（补全角/编码坑）⑤ 找 bug（off-by-one + 换行，改计数器方案）⑥ 指针 swap（正确解引用）。另现场学 **M7 预习：埃拉托色尼筛法**（O(N log log N)，理解 i*i 原理）。
- **自评**：6/6 全 ✅ 熟练 → 按规则直接进 M2。
- **顺带工程项**：项目 git 托管 + 进度依托 git（CLAUDE.md 已加规则，每次里程碑提交）；LLVM 代码风格配置；任务终端静音化。
- **结论**：M1 收官。基础扎实（类型/函数/容器/类封装/边界/指针初步）。
- **下一步建议**：生成并进入 **M2 引用/指针/内存模型**。

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
