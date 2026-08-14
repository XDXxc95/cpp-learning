# M3 练习 · STL 容器与算法

> 规则：**先自己写，再对照** `practice/03/solutions/`。全部完成后填文末自评表。
> 所有练习文件在 `practice/03/` 下，命名 `NN_主题.cpp`，用 `tools/compile.sh` 编译运行。
> 练习文件是**空骨架**，你往里面填实现。
> **建议顺序**：按 A → B → C → D 分层推进；每层做完可先对照答案，再进下一层。

## A 区 · 基础热身 Basic Warm-up

> 目的：把每个语法点「跑通一遍」求手感，题很小，不纠结算法。

### 练习 1 · vector 最小操作 | vector warm-up

文件：`practice/03/01_vector_warmup.cpp`

用 `std::vector` 依次 `push_back` 三个数，做到：

1. 打印 `size()` 和第一个元素（用 `[]` 读）
2. 用**范围 for** 全部打印
3. 每 `push_back` 一次打印一次 `size()` 和 `capacity()`，**观察容量怎么翻倍**（1→2→4…）

这就是「vector 自动扩容」的真相——也是它替你管内存的底气。

### 练习 2 · string 最小操作 | string warm-up

文件：`practice/03/02_string_warmup.cpp`

把 string 最常用的 4 个点各练一遍：

1. `+` 拼接 `"Hello"` + `"World"`
2. `substr(0, 3)` 取前 3 个字符
3. `find("lo")` 找位置，找不到时用 `std::string::npos` 判断
4. `getline` 读一整行（含空格），打印长度和内容

## B 区 · 核心应用 Core

> 目的：每个容器的典型用途来一道标准题，覆盖完整场景。

### 练习 3 · 用 vector 重写「动态数组求平均」| Rewrite avg with vector

文件：`practice/03/03_vector_avg.cpp`

用 `std::vector<double>` 重写 M2 练习 3 的 `03_dynamic_avg.cpp`：

1. 输入 `n`，`std::vector<double> a(n)` 直接造出 n 个元素
2. 填值 `a[i] = (i + 1) * 1.5`
3. 求平均输出，保留 2 位小数（`std::fixed` + `setprecision(2)`）
4. **防御 `n <= 0` 不变**（`vector` 接受 0 长度，但业务上 n<=0 是错的，照样报错退出）

然后在注释里用你的话对比：**比起 M2 的 `new[]/delete[]` 版本，你的代码少了哪些手动操作？**（这正是 M2 练习 3 思考题「sieve 为什么能用运行时 n」的答案）

### 练习 4 · 频率统计（map）| Frequency counter with map

文件：`practice/03/04_frequency.cpp`

输入：第一行 `n`，第二行 `n` 个整数（可能重复）。
用 `std::map<int, int>` 统计每个数出现次数，**按键升序**输出「数 次数」，每行一个。

示例：输入 `6` / `3 1 3 1 3 2` → 输出 `1 2` / `2 1` / `3 3`。

注释里回答两个问题：

- ① 为什么输出天然就是升序的？（提示：map 内部怎么存的）
- ② 用 `freq[x]++` 时，如果 x 第一次出现（键不存在），会发生什么？（提示：`[]` 找不到会怎样）

### 练习 5 · 去重 + 查找（set / binary_search）| Dedup & search

文件：`practice/03/05_dedup.cpp`

输入：第一行 `n`，第二行 `n` 个整数（可能重复）。
输出：

1. 用 `std::set` 去重后**升序**打印（空格分隔）
2. 再输入一个 `target`，判断它在不在原数组里（`binary_search` 或 `count`）

示例：输入 `6` / `3 1 3 2 1 4` / `3` → 输出 `1 2 3 4` 和 `3 in`。

注释里回答：`binary_search` 前为什么必须先排序？（提示：它折半查找的前提是区间有序）

### 练习 6 · 字符串处理（string）| String processing

文件：`practice/03/06_string_ops.cpp`

输入一行英文句子（可能含空格，用 `getline`）。
输出：

1. 单词个数
2. 最长单词（并列取第一个）
3. 反转后的整个句子

示例：输入 `I love C++ and coding` → 输出单词数 5、最长单词 `coding`、反转 `gnidoc dna ++C evol I`。

提示：数单词可以用 `<sstream>` 的 `std::istringstream`（`>>` 自动按空白切分）；反转字符串用反向迭代器 `std::string rev(line.rbegin(), line.rend());`。

## C 区 · 迭代器 + 算法 Iterator & Algorithm

> 目的：B 区用的都是「容器的表面语法」，C 区补上容器底下的**迭代器**和**通用算法**——它们是 STL 的灵魂。

### 练习 7 · 迭代器专项 | Iterator essentials

文件：`practice/03/07_iterators.cpp`

输入：第一行 `n`，第二行 `n` 个整数。要求：

1. 用**正向迭代器**遍历打印（显式写 `it = v.begin(); it != v.end(); ++it`，别用范围 for）
2. 用 `std::distance(v.begin(), v.end())` 求长度打印（应等于 n）
3. 打印最后一个元素 `*(v.end() - 1)`——体会 `end()` 本身**不指向任何元素**
4. 用**反向迭代器** `rbegin/rend` 倒序打印

注释里回答：为什么循环条件写成 `it != v.end()` 而不是 `it <= v.end()`？

### 练习 8 · `<algorithm>` 常用算法专项 | Algorithm toolkit

文件：`practice/03/08_algorithms.cpp`

输入：第一行 `n`，第二行 `n` 个整数。对同一份数据依次操作、逐步打印：

1. `std::sort` 升序后打印
2. `std::accumulate` 求和（注意它在 `<numeric>` 里）
3. `min_element` / `max_element` 求最小最大（返回迭代器，要 `*it` 解引用）
4. `std::count` 数某个数出现几次（再输入一个 target）
5. `std::reverse` 反转后打印

## D 区 · 综合 · 学后练习 Capstone

> 目的：把这一节的知识**串起来**收口，题型贴近刷题/面试。

### 练习 9 · 词频 Top-K | Top K frequent words（综合）

文件：`practice/03/09_word_freq_top.cpp`

输入一行英文句子（可能含空格，用 `getline`）：

1. 用 `std::map<std::string, int>` 统计每个单词出现次数
2. 把 `(单词, 次数)` 倒进 `std::vector<std::pair<...>>`，按**次数降序**排序，次数相同按**字典序升序**（`std::sort` + lambda）
3. 打印次数最多的 3 个词，格式 `word count` 每行一个

示例：输入 `a cat a dog a cat` → 输出 `a 3` / `cat 2` / `dog 1`。

这题把 string（getline/istringstream 分词）、map（计数）、vector（收集）、sort（自定义比较）全串起来了——LeetCode「前 K 个高频词」就是这道题。

### 练习 10 · 容器选型设计题 | Choose the right container

文件：`practice/03/10_container_choice.cpp`

**不用写实现逻辑**。文件顶部给了 5 个场景，在注释里写出：用什么容器 + 为什么 + 大致复杂度，然后对照答案。

场景示例（完整 5 个见文件内）：

- 需要快速判断「某数在不在集合里」且自动排好序 → ?
- 统计单词出现次数、按键遍历输出 → ?
- 长度运行时才知的动态数组、末尾加、按下标访问 → ?

这是刷题和面试里最高频的考点：**看到需求 → 选对容器**。

## 自评表 Self-Assessment

| 项目 | ✅ 熟练 | 🔶 基本掌握 | ❌ 薄弱 |
| --- | --- | --- | --- |
| vector 基本操作 / 自动扩容 | ✅ | | |
| string 常用操作（拼接/子串/find/getline） | ✅ | | |
| map / set 有序容器与存在性判断 | ✅ | | |
| 迭代器（begin/end 区间、反向、distance） | ✅ | | |
| `<algorithm>` 常用算法 | ✅ | | |
| 综合应用与容器选型 | ✅ | | |

填完把结果发给 Claude，全 ✅ → 收尾 M3-1 高频容器 → 进 M4-1 面向对象核心。
