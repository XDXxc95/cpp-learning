# M3-1 · 字符串与动态数组 | String & Vector

> 目标 Goals：会用 `std::string` 和 `std::vector` 处理日常字符串与序列数据；理解容器替你接管了内存管理（M2 的 new/delete 在这里升级换代）。
> 预计时间 Est. time：约 40 分钟 ｜ 难度 Difficulty：入门 → 熟练

## 本节要点 Key Points

- **容器 = 内存管理的答案**：M2 的「new/delete 配对、防泄漏、防悬垂」三条规矩，交给容器自动完成，你只管「用」
- `std::string`：可变长字符串，日常写代码**别再拿 `char[]` / `char*` 硬扛**
- `std::vector<T>`：可变长动态数组，尾部 `push_back` 摊还 O(1)
- 传参铁则：只读大对象 → `const T&`（不拷贝、保证不改）——直接接 M2 的判断树
- 两个 size_t 陷阱：`size()` 返回 `size_t`；`find()` 找不到返回 `std::string::npos`

## 正文 Body

### 1. 为什么现在学容器？| Why containers now

M2 你手动 `new[]` / `delete[]` 配过对（练习 3），也修过泄漏、双删、悬垂。这些痛苦的根源是：**内存的分配与释放分开手动管，就总有配对不上的时候**。

STL 容器的思路正好反过来：**你只负责「往里放、往外取」，内存的申请和释放由容器在构造/析构时自动完成**。拿 M2 练习 3 的动态数组来说——`std::vector` 就是那个数组，但你不用写 `delete[]`，它自己的析构函数会在离开作用域时自动释放。这也是 M2 练习 3 那个「为什么 sieve 可以用运行时 n」的正式答案（当时说 M3 再揭晓）。

### 2. std::string —— 会自我管理的字符序列

字符串本质是「字符的序列」，`std::string` 就是「自动管理内存的 `char[]`」。

**创建 Creating**

```cpp
std::string s1 = "hello";          // C 风格字面量 → string
std::string s2(5, 'a');            // "aaaaa"：重复字符
std::string s3 = s1 + ", world";   // 拼接（+ 运算符）
```

**常用成员 Common members**

| 成员 | 作用 | 返回 |
| --- | --- | --- |
| `size()` / `length()` | 字符个数（两个等价） | `size_t` |
| `empty()` | 是否为空 | `bool` |
| `push_back(c)` / `pop_back()` | 尾部加/删一个字符 | void |
| `s[i]` | 按下标读写字符（越界不检查） | `char&` |
| `find(sub)` | 找子串首次出现位置 | `size_t`；找不到 = `npos` |
| `substr(pos, len)` | 截取子串（len 省略 = 到末尾） | `string` |
| `==` / `>` / `<` | 字典序比较 | `bool` |

**两个必记陷阱 Traps**

```cpp
std::string s = "hello";
std::size_t pos = s.find("world");          // 找不到……
if (pos != std::string::npos) { /* 找到了 */ }  // npos 就是「没找到」的哨兵值
```
- `find()` 找不到返回 `std::string::npos`（一个极大的 `size_t`），**不是** -1、也不是 0
- 拿 `size()` 去和 `int` 比较会触发 `-Wsign-compare` 警告——M2 练习 3 你刚踩过，这里换个形式重演

### 3. std::vector —— 会自我管理的动态数组

**创建 Creating**

```cpp
std::vector<int> v1;                // 空
std::vector<int> v2(5);             // 5 个 0
std::vector<int> v3(3, 7);          // 3 个 7
std::vector<int> v4 = {1, 2, 3, 4}; // 初始化列表
```

**常用成员 Common members**

| 成员 | 作用 | 复杂度 |
| --- | --- | --- |
| `push_back(x)` | 尾部追加 | 摊还 O(1) |
| `pop_back()` | 删尾部一个 | O(1) |
| `size()` / `empty()` | 元素个数 / 是否为空 | O(1) |
| `v[i]` | 下标访问（越界不检查） | O(1) |
| `v.at(i)` | 下标访问（越界抛 `std::out_of_range`） | O(1) |
| `front()` / `back()` | 首 / 尾元素 | O(1) |
| `clear()` | 清空（不释放容量） | O(n) |

**遍历 Traversal**

```cpp
// 下标（注意 i 用 size_t，别和 int 混）
for (std::size_t i = 0; i < v.size(); ++i) {
  std::cout << v[i] << ' ';
}
// range-for（首选：清晰、不会越界）
for (int x : v) {
  std::cout << x << ' ';
}
```

### 4. 动态数组：手动 vs vector（M2 练习 3 的回响）

同样「运行时才知道大小 → 只能堆」：

| | 手动 `new[]`/`delete[]`（M2） | `std::vector` |
| --- | --- | --- |
| 分配 | `double* a = new double[n];` | `std::vector<double> v;` |
| 释放 | 必须 `delete[] a;`（忘了 = 泄漏） | 析构自动，无需手写 |
| 越界 | 没人管 | `[]` 不管，`at()` 管 |
| 安全 | 双删/悬垂自己防 | 基本防死 |

结论：**能选 vector 就别手写裸数组**。手写裸数组的唯一理由是「极少数性能极致敏感」场合，先不展开。

### 5. 传参铁则 | How to pass containers

接 M2 的判断树，传 `string` / `vector` 这类「可能很大的对象」时：

| 意图 | 写法 | 说明 |
| --- | --- | --- |
| 只读 | `void f(const std::vector<int>& v)` | **默认首选**：不拷贝 + 保证不改 |
| 要改 | `void f(std::vector<int>& v)` | 改动反映到调用方 |
| 就是想拷一份 | `void f(std::vector<int> v)` | 会整体拷贝，贵，少用 |

按值传一个 100 万元素的 vector，等于在栈上复制 100 万个 int——这就是为什么 `const T&` 是 C++ 里出现频率最高的签名。

## 代码示例 Examples → 指向 `examples/03-1/`

1. `01_string_basics.cpp` — string 创建 / 拼接 / find+npos / substr / 遍历
2. `02_vector_basics.cpp` — vector 创建 / push_back / 遍历 / [] vs at / front-back
3. `03_vector_vs_manual.cpp` — 同一个「动态求平均」，手动 new[] 和 vector 并排对比 + `const&` 传参

## 易错点 Common Pitfalls

1. **`size()` 返回 `size_t`**：for 循环拿它跟 `int i` 比 → `-Wsign-compare` 警告。统一用 `std::size_t i`，或直接用 range-for。
2. **`find` 判空要用 `npos`**：写 `if (s.find("x"))` 是错的——`npos` 是非零值，`if` 恒真。正确：`if (s.find("x") != std::string::npos)`。
3. **`[]` 越界不检查**：越界读是未定义行为（M2 练习 2 学过的概念，容器里同样成立）。要安全检查用 `.at(i)`。
4. **range-for 里别改容器**：边遍历边 `push_back`/`erase` 会导致迭代器失效，行为未定义（M3-2 详讲，先记住「别边走边改」）。
5. **按值传容器**：`void f(std::vector<int> v)` 会整体拷贝，大容器很贵。只读就 `const&`。

## 练习 Exercises → 指向 `practice/03-1/exercises.md`

4 道：string 反转 / vector 统计 / const& 传参 / 思考题。先自己写，再对照 `solutions/`。

## 自测 Self-Check

1. `find()` 找不到返回什么？判断要用什么常量？
2. `size()` 返回什么类型？for 里和 `int i` 比较会怎样？
3. `[]` 和 `at()` 越界行为有什么不同？
4. 只读传一个 vector，该用什么签名？
5. `push_back` 的复杂度是？（摊还）
