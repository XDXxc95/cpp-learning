# M3 练习 · STL 容器与算法

> 规则：**先自己写，再对照** `practice/03/solutions/`。全部完成后填文末自评表。
> 所有练习文件在 `practice/03/` 下，命名 `NN_主题.cpp`，用 `tools/compile.sh` 编译运行。
> 练习文件是**空骨架**，你往里面填实现。

## 练习 1 · 用 vector 重写「动态数组求平均」| Rewrite avg with vector

文件：`practice/03/01_vector_avg.cpp`

用 `std::vector<double>` 重写 M2 练习 3 的 `03_dynamic_avg.cpp`：

1. 输入 `n`，`std::vector<double> a(n)` 直接造出 n 个元素
2. 填值 `a[i] = (i + 1) * 1.5`
3. 求平均输出，保留 2 位小数（`std::fixed` + `setprecision(2)`）
4. **防御 `n <= 0` 不变**（`vector` 接受 0 长度，但业务上 n<=0 是错的，照样报错退出）

然后在注释里用你的话对比：**比起 M2 的 `new[]/delete[]` 版本，你的代码少了哪些手动操作？**（这正是 M2 练习 3 思考题「sieve 为什么能用运行时 n」的答案）

## 练习 2 · 频率统计（map）| Frequency counter with map

文件：`practice/03/02_frequency.cpp`

输入：第一行 `n`，第二行 `n` 个整数（可能重复）。
用 `std::map<int, int>` 统计每个数出现次数，**按键升序**输出「数 次数」，每行一个。

示例：输入 `6` / `3 1 3 1 3 2` → 输出 `1 2` / `2 1` / `3 3`。

注释里回答：为什么输出天然就是升序的？（提示：map 内部怎么存的）

## 练习 3 · 去重 + 查找（set / binary_search）| Dedup & search

文件：`practice/03/03_dedup.cpp`

输入：第一行 `n`，第二行 `n` 个整数（可能重复）。
输出：
1. 用 `std::set` 去重后**升序**打印（空格分隔）
2. 再输入一个 `target`，判断它在不在原数组里（`binary_search` 或 `count`）

示例：输入 `6` / `3 1 3 2 1 4` / `3` → 输出 `1 2 3 4` 和 `3 in`。

注释里回答：`binary_search` 前为什么必须先排序？（提示：它折半查找的前提是区间有序）

## 练习 4 · 字符串处理（string）| String processing

文件：`practice/03/04_string_ops.cpp`

输入一行英文句子（可能含空格，用 `getline`）。
输出：
1. 单词个数
2. 最长单词（并列取第一个）
3. 反转后的整个句子

示例：输入 `I love C++ and coding` → 输出单词数 5、最长单词 `coding`、反转 `gnidoc dna ++C evol I`。

提示：数单词可以用 `<sstream>` 的 `std::istringstream`（`>>` 自动按空白切分）；反转字符串用反向迭代器 `std::string rev(line.rbegin(), line.rend());`。

## 自评表 Self-Assessment

| 项目 | ✅ 熟练 | 🔶 基本掌握 | ❌ 薄弱 |
| --- | --- | --- | --- |
| vector 动态数组 / 自动内存管理 | | | |
| string 常用操作 | | | |
| map / set 有序容器与存在性判断 | | | |
| 迭代器 + algorithm 算法 | | | |
| 复杂度与容器选型 | | | |

填完把结果发给 Claude，全 ✅ → 进 M4 面向对象深入。
