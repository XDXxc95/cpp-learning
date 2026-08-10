# M3-1 练习 · 字符串与动态数组 | String & Vector

> 规则：**先自己写，再对照** `practice/03-1/solutions/`。全部完成后填文末自评表。
> 所有练习文件在 `practice/03-1/` 下，命名 `NN_主题.cpp`，用 `tools/compile.sh` 编译运行。

## 练习 1 · string 反转 | Reverse a string

文件：`practice/03-1/01_string_reverse.cpp`

用 `std::getline(std::cin, s)` 读入一行英文（可能含空格），然后：

1. 打印这行字符串的**长度**（注意 `size()` 返回 `size_t`）
2. 数出其中**空格**的个数
3. 打印**反转**后的字符串（新串倒序，不要求原地）

提示：`getline` 需要 `#include <string>`；反转可以循环从后往前拼，或从前往后往一个新 `std::string` 里加。

## 练习 2 · vector 统计 | Vector stats

文件：`practice/03-1/02_vector_stats.cpp`

1. 先读 `n`，再读 `n` 个整数，`push_back` 进 `std::vector<int>`
2. 输出：**最大值 / 最小值 / 平均值**（平均值用 `double`，保留 2 位小数）

对比 M2 练习 3：这次**不要手动 new[]/delete[]**，全部交给 vector。防御 `n <= 0` 时报错退出（用 `std::cerr` + `return 1`）。

## 练习 3 · const& 传参 | Pass by const reference

文件：`practice/03-1/03_pass_by.cpp`

实现两个计算 vector 整数和的函数：

```cpp
int sum(const std::vector<int>& v);   // const 引用版
int sumByValue(std::vector<int> v);   // 按值版
```

在 `main` 里造一个 vector 分别调两个函数，验证结果相同。然后在注释里用自己的话回答：

- 为什么只读传参应该用 `const&` 而不是按值？（提示：想想按值会发生什么）

## 练习 4 · 思考题 | Think (注释回答即可)

文件：`practice/03-1/03_pass_by.cpp` 或单独 `practice/03-1/04_think.cpp`，在注释里回答：

1. M2 练习 3 的「动态求平均」为什么要 `delete[]`，换成 vector 就不用写了？（提示：析构）
2. `size()` 返回 `size_t` 意味着什么？为什么 `for (int i = 0; i < v.size(); i++)` 会触发 `-Wsign-compare` 警告？
3. 什么场景下你会刻意用 `at()` 而不是 `[]`？

## 自评表 Self-Assessment

| 项目 | ✅ 熟练 | 🔶 基本掌握 | ❌ 薄弱 |
| --- | --- | --- | --- |
| string 创建/查找/截取/遍历 | | | |
| vector 创建/push_back/遍历 | | | |
| 容器传参 const& / size_t 陷阱 | | | |
| 容器 vs 手动 new[]/delete[] | | | |

填完把结果发给 Claude，全 ✅ → 进入 **M3-2 迭代器与 algorithm**。
