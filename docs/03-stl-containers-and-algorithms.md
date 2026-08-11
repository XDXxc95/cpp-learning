# M03 · STL 容器与算法 | STL Containers & Algorithms

> 目标 Goals：掌握刷题和通用开发最常用的 STL——`vector` / `string` / `map` / `set`、迭代器、常用算法，并建立复杂度直觉 ｜ 预计 Est.：2~3 小时 ｜ 难度：★★☆
>
> 这是你 M2 之后最重要的模块：**大部分内存管理的痛苦，STL 容器替你包了**。M2 里你手动 `new[]`/`delete[]`，这里换 `std::vector` 一行声明。刷题（LeetCode 类）几乎全程在用容器和算法，本模块是 M7 算法专项的弹药库。

## 本节要点 Key Points

- STL = **容器**（Containers）+ **迭代器**（Iterators）+ **算法**（Algorithms）三大件
- `std::vector`：动态数组，自动扩容自动释放（RAII），**刷题主力**
- `std::string`：字符串，自带长度、拼接、查找、子串
- `std::map` / `std::set`：有序关联容器，查找 O(log n)
- 迭代器是容器与算法的「通用接口」；区间约定 `[begin, end)`
- `<algorithm>`：`sort` / `find` / `binary_search` / `count` / `accumulate` / `min_element` 等
- 复杂度直觉：选对容器 > 写出优雅代码

## 正文 Body

### 1. STL 是什么 What is STL

STL（Standard Template Library，标准模板库）是 C++ 标准库的核心，三大件分工：

| 件 | 作用 | 例子 |
| --- | --- | --- |
| 容器 Containers | 存数据（管理内存） | `vector` `string` `map` `set` |
| 迭代器 Iterators | 通用「指针」，连接容器与算法 | `v.begin()` `v.end()` |
| 算法 Algorithms | 对区间做操作 | `sort` `find` `count` |

关键心智：算法**不知道**容器是什么，只认迭代器区间 `[first, last)`。所以同样的 `std::sort` 能排序 `vector`、也能排序 `array`、甚至部分 `list`。

### 2. `std::vector` —— 动态数组（重点）

与 M2 手动 `new[]/delete[]` 的对比（`examples/03/01_vector_basics.cpp`）：

```cpp
// M2 手动版：new、赋值、delete[] 都要自己管
double* arr = new double[n];
...
delete[] arr;

// M3 vector 版：自动在堆上分配、自动释放
std::vector<double> a(n);   // n 个 0.0
```

几个必会操作：

| 操作 | 写法 | 说明 |
| --- | --- | --- |
| 尾插 | `v.push_back(x)` | 空间不够自动扩容 |
| 大小 | `v.size()` | 元素个数（`size_t`） |
| 容量 | `v.capacity()` | 已分配空间，扩容通常翻倍 |
| 随机访问 | `v[i]` / `v.at(i)` | `[]` 快无检查；`at` 越界抛异常 |
| 首尾 | `v.front()` / `v.back()` | |
| 尾删 | `v.pop_back()` | |
| 清空/判空 | `v.clear()` / `v.empty()` | |

**遍历三件套**（都要会）：

```cpp
for (size_t i = 0; i < v.size(); i++) { ... }   // 下标遍历
for (int x : v) { ... }                          // range-for：x 是副本
for (int& x : v) { x += 1; }                     // range-for + 引用：改原数组
for (auto it = v.begin(); it != v.end(); ++it) { ... }  // 迭代器
```

⚠️ 想要「修改原数组」必须加引用 `&`；直接 `for (int x : v)` 改的是副本。

### 3. `std::string` —— 字符串（examples/03/02_string_ops.cpp）

| 操作 | 写法 | 注意 |
| --- | --- | --- |
| 拼接 | `s += "x"` / `s1 + s2` | |
| 长度 | `s.length()` 或 `s.size()` | |
| 子串 | `s.substr(pos, len)` | 取 `[pos, pos+len)` |
| 查找 | `s.find(sub)` | 找不到返回 `std::string::npos` |
| 字符访问 | `s[i]` | 可改 |
| 读整行 | `std::getline(std::cin, line)` | 含空格；和 `>>` 混用要先吃残留换行 |
| 转 C 串 | `s.c_str()` | 返回 `const char*`，`s` 改动后可能失效 |

### 4. `std::map` / `std::set` —— 有序关联容器（examples/03/03_map_set.cpp）

- **`map<Key, Value>`**：键 → 值，按键**升序**存储，查找/插入 O(log n)。
- **`set<T>`**：只有键，**自动去重** + 升序。

```cpp
std::map<std::string, int> score;
score["Alice"] = 90;                 // 插入或覆盖
score.count("Tom");                  // 存在性：1 / 0
score.find("Tom") == score.end();    // 判断不存在
for (auto& kv : score) { kv.first; kv.second; }   // 遍历，按键升序
```

**最大的坑**：`score["Tom"]` 在键不存在时会**自动插入一个默认值**（int → 0）。所以「只想查、不想改」时必须用 `count`/`find`，不能用 `[]`。

### 5. 迭代器 Iterators

迭代器就是「容器里的指针」：`*it` 取值、`++it` 前进、`it != v.end()` 判止。

- **区间是左闭右开 `[begin, end)`**：`end()` 指向最后一个元素的下一个，是「哨兵」，不能解引用。
- 反向：`rbegin()` / `rend()` 从尾往头。
- **迭代器失效**：`vector` 在插入/删除后，之前的迭代器可能失效（内存搬了家）。刷题时「边遍历边删」的循环要特别小心，常见做法是倒着删或先收集再删。

### 6. `<algorithm>` 常用算法（examples/03/04_algorithms.cpp）

| 算法 | 复杂度 | 前提 | 返回 |
| --- | --- | --- | --- |
| `std::sort(begin, end)` | O(n log n) | 随机访问迭代器 | — |
| `std::binary_search(begin, end, x)` | O(log n) | **已排序** | bool |
| `std::find(begin, end, x)` | O(n) | 无序即可 | 迭代器 |
| `std::count(begin, end, x)` | O(n) | | 个数 |
| `std::accumulate(begin, end, init)` | O(n) | | 和 |
| `std::min_element` / `max_element` | O(n) | | 迭代器 |
| `std::reverse(begin, end)` | O(n) | | — |

降序排序传比较器：`std::sort(v.begin(), v.end(), [](int a, int b) { return a > b; })`（lambda 是 M5 的内容，这里先用）。

### 7. 复杂度速查 & 选型 Complexities & Choosing

| 容器 | 随机访问 | 查找 | 尾插/尾删 | 特点 |
| --- | --- | --- | --- | --- |
| `vector` | O(1) | O(n) | O(1) 均摊 | 动态数组，**默认首选** |
| `map` / `set` | 无 | **O(log n)** | O(log n) | 有序、去重（set） |
| `string` | O(1) | O(n) | O(1) | 字符序列 |

**选型口诀**：默认 `vector`；要按键查值用 `map`；要快速判断「在不在 / 去重」用 `set`；只有字符用 `string`。

## 代码示例 Examples → `examples/03/`

| 文件 | 演示 |
| --- | --- |
| `01_vector_basics.cpp` | vector 增删查改、capacity 翻倍、三种遍历、range-for 引用 |
| `02_string_ops.cpp` | string 拼接/子串/查找/getline/c_str |
| `03_map_set.cpp` | map 频率计数、count/find 存在性、set 去重排序 |
| `04_algorithms.cpp` | sort/binary_search/find/count/accumulate/min_max/reverse |

## 易错点 Common Pitfalls

1. **`map[key]` 自动插入默认值**——只想查存在性，用 `count`/`find`。
2. **range-for 不带 `&` 改不了原数组**——`for (int x : v) x += 1;` 改的是副本。
3. **`binary_search` 前必须先排序**——对未排序区间调用结果未定义。
4. **`v[i]` 越界是 UB**——拿不准就用 `.at(i)`（会抛异常，好排查）。
5. **`npos` 不是 -1**——它是 `size_t` 最大值；判断找不到要用 `== std::string::npos`。
6. **vector 迭代器在插入/删除后可能失效**——边遍历边删要小心。
7. **下标遍历用 `size_t`**——`int i` 和 `v.size()` 比会触发 `-Wsign-compare` 警告。
8. **`getline` 和 `>>` 混用**——`>>` 后留的换行符会被 `getline` 读到，要先 `std::cin.ignore()`。

## 练习 Exercises → `practice/03/exercises.md`

**10 道练习**，按「由浅入深」分四层推进（先自己写，再对照 `practice/03/solutions/`）：

- **A 热身 Basic**：① vector 最小操作（观察容量翻倍）② string 最小操作
- **B 核心 Core**：③ vector 重写 M2 求平均 ④ map 频率统计 ⑤ set 去重 + binary_search ⑥ string 单词统计
- **C 迭代器/算法 Iterator & Algorithm**：⑦ 迭代器专项（`[begin,end)` / 反向 / distance）⑧ `<algorithm>` 常用算法
- **D 综合 Capstone**：⑨ 词频 Top-K（LeetCode「前 K 高频词」同款）⑩ 容器选型设计题

做完填文末自评表，回来 review。

## 自测 Self-Check

- 为什么 `for (int x : v) x += 1` 改不动原数组？怎么改？
- `score["Tom"]` 在 Tom 不存在时会做什么？判断存在应该用什么？
- `binary_search` 和 `find` 各需要什么前提？各自复杂度？
- 一个数出现次数最多、要去重、要按键查值——分别该用什么容器？
