# M03-1 · 高频容器 | High-Frequency Containers

> 目标 Goals：补齐刷题最常用的四个高频容器——`unordered_map`/`unordered_set`（哈希，平均 O(1)）、`priority_queue`（堆）、`stack`/`queue`（LIFO/FIFO）、`deque`（双端队列），并升级选型直觉 ｜ 预计 Est.：2~3 小时 ｜ 难度：★★☆
>
> M3 讲的 `map`/`set` 是**有序**的（红黑树，O(log n)）。刷题时很多场景根本不 care 顺序、只求快——那就是哈希容器的天下；要「每次取最大/最小」「先进先出」「两端都快」，则各有专属容器。本模块是 M7 算法专项（滑动窗口、Top-K、单调队列）的预备弹药。

## 本节要点 Key Points

- `unordered_map` / `unordered_set`：**哈希表**，查找/插入**平均 O(1)**，但**无序**
- `priority_queue`：**堆**，`push`/`pop` O(log n)，`top()` O(1)，默认最大堆
- `stack` / `queue`：**LIFO / FIFO**，容器适配器（底层默认 deque）
- `deque`：双端队列，**两端插入删除 O(1)**，可随机访问
- 选型升级版口诀：**要顺序 → `map`/`set`；只要快 → `unordered_*`；取最值/前 K → `priority_queue`；FIFO → `queue`；两端操作 → `deque`**

## 正文 Body

### 1. `unordered_map` / `unordered_set` —— 哈希表 Hash Table（examples/03-1/01_*）

M3 的 `map`/`set` 内部是**红黑树**（有序，查找 O(log n)）；`unordered_map`/`unordered_set` 内部是**哈希表**，靠 `std::hash` 把键散列到桶里：

| 容器 | 底层 | 查找/插入 | 顺序 | 头文件 |
| --- | --- | --- | --- | --- |
| `map` / `set` | 红黑树 | O(log n) | **按键升序** | `<map>` / `<set>` |
| `unordered_map` / `unordered_set` | 哈希表 | **平均 O(1)** | **无顺序**（由哈希决定） | `<unordered_map>` / `<unordered_set>` |

用法和 `map`/`set` **几乎一样**，只是换头文件、名字加 `unordered_` 前缀：

```cpp
std::unordered_map<std::string, int> freq;
freq["apple"]++;                        // 计数，首次自动插默认值 0 再自增
freq.count("mango");                    // 存在性：1 / 0（和 map 一样，别用 [] 查存在）
for (auto& kv : freq) { ... }           // 遍历 OK，但【顺序不定】

std::unordered_set<int> s;
s.insert(x);                            // 去重
s.count(x);                             // O(1) 平均判断存在
```

**核心差异**：`unordered` 快但乱。想要输出升序/稳定顺序，必须用 `map`/`set`。

⚠️ 几个注意：
- 平均 O(1) 是「平均」，哈希冲突严重时**最坏 O(n)**——刷题一般够用，别迷信常数。
- 自定义类型（如 `struct`）做键要自己提供 `std::hash` 特化 + `operator==`，本模块先用 `int`/`string`（标准库已自带 hash）。
- `unordered_map[key]` 同样会在键不存在时**自动插入默认值**——判断存在照样用 `count`/`find`。

### 2. `priority_queue` —— 优先队列（堆）Heap（examples/03-1/02_*）

`priority_queue` 是**堆**：内部是二叉堆，`top()` 永远返回「优先级最高」的元素，插入/删除都是 O(log n)。

```cpp
#include <queue>
#include <functional>   // std::greater

std::priority_queue<int> pq;                       // 默认：最大堆，top() 是最大元素
pq.push(3); pq.push(1); pq.push(5);                // 入堆 O(log n)
pq.top();                                          // 5（O(1)）
pq.pop();                                          // 移除 top（O(log n)）

// 最小堆：第二个参数是底层容器，第三个是比较器
std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
```

- 没有迭代器，**不能按顺序遍历**——想按序打印就得逐个 `pop`（`top` + `pop` 循环）。
- `push` / `pop` O(log n)，`top` / `empty` / `size` O(1)。
- 自定义比较器时方向最容易搞反：`comp(a, b)` 返回 `true` 表示 **a 的优先级比 b 低**（a 更晚出队）。也就是「top 是按 comp 排序后排在最后那个」。

**Top-K 模式（重要，刷题高频）**：求最大的 k 个数，维护一个**大小为 k 的最小堆**——新数比堆顶（当前第 k 大）大就替换它：

```cpp
for (int x : data) {
  if (topk.size() < k) topk.push(x);
  else if (x > topk.top()) { topk.pop(); topk.push(x); }
}
```

复杂度 **O(n log k)**，比全排序 O(n log n) 省；数据量大时优势明显。

### 3. `stack` / `queue` —— 栈与队列（examples/03-1/03_*）

| 容器 | 原则 | 访问 | 入 | 出 | 头文件 |
| --- | --- | --- | --- | --- | --- |
| `stack` | 后进先出 LIFO | 只看 `top()` | `push` | `pop` | `<stack>` |
| `queue` | 先进先出 FIFO | `front()` 队头 / `back()` 队尾 | `push` | `pop` | `<queue>` |

```cpp
std::stack<int> st;
st.push(1); st.push(2); st.push(3);
st.top();                          // 3，只看不删
st.pop();                          // 移除 3（后进先出）

std::queue<int> q;
q.push(1); q.push(2); q.push(3);
q.front();                         // 1
q.back();                          // 3
q.pop();                           // 移除 1（先进先出）
```

- 两者是**容器适配器**：包装了底层容器（默认 `deque`），只暴露受限接口。
- **没有迭代器、没有 `clear()`**（C++17；C++23 才给适配器加 `clear`）——想清空就重新构造一个。
- 空容器上 `top()` / `front()` / `pop()` 是**未定义行为**——操作前先 `empty()` 判断。

刷题里 `stack` 的典型用途：括号匹配、表达式求值、单调栈；`queue` 的典型用途：BFS、约瑟夫环/报数、缓冲。

### 4. `deque` —— 双端队列 Double-ended Queue（examples/03-1/04_*）

`deque`（double-ended queue，读作 "deck"）头尾都能 O(1) 插入删除，还能随机访问：

```cpp
#include <deque>
std::deque<int> d;
d.push_back(1); d.push_front(0);   // 两端插入都 O(1)
d.back(); d.front();               // 1 / 0
d.pop_back(); d.pop_front();       // 两端删除都 O(1)
d[2];                              // 随机访问 O(1)
```

与 `vector` 对比：

| 操作 | `vector` | `deque` |
| --- | --- | --- |
| 尾插/尾删 | O(1) 均摊 | O(1) |
| **头插/头删** | **O(n)**（整体后移） | **O(1)** |
| 中间插入/删除 | O(n) | **O(n)** |
| 随机访问 | O(1) | O(1)（略慢一点） |

内部是**分段连续数组**（一段段拼起来），所以头尾都快。用途：需要**两端**操作（回文检查、滑动窗口、双端队列 BFS）；但「中间插入 + 随机访问」不如 `vector`。

### 5. 复杂度速查 & 选型 Complexities & Choosing

| 容器 | 底层 | 查找/访问 | 插入/删除 | 顺序 | 头文件 |
| --- | --- | --- | --- | --- | --- |
| `unordered_map` / `unordered_set` | 哈希表 | 平均 O(1) | 平均 O(1) | 无序 | `<unordered_map>` / `<unordered_set>` |
| `map` / `set` | 红黑树 | O(log n) | O(log n) | 升序 | `<map>` / `<set>` |
| `priority_queue` | 堆 | top O(1) | push/pop O(log n) | 按优先级出队 | `<queue>` |
| `stack` / `queue` | 适配器（deque） | top/front/back O(1) | push/pop O(1) | LIFO / FIFO | `<stack>` / `<queue>` |
| `deque` | 分段数组 | 随机访问 O(1) | 两端 O(1)、中间 O(n) | 保持插入序 | `<deque>` |

**选型口诀（M3 版本升级）**：
- 默认 `vector`；
- 按键查值 / 判断存在 / 去重：**只要快、不在乎顺序 → `unordered_map`/`unordered_set`；要求有序 → `map`/`set`**；
- 每次取最大/最小、求前 K → `priority_queue`；
- 后进先出 → `stack`；先进先出 → `queue`；
- 两端都要频繁增删 → `deque`。

## 代码示例 Examples → `examples/03-1/`

| 文件 | 演示 |
| --- | --- |
| `01_unordered_map_set.cpp` | unordered_map 频率统计、unordered_set 存在性、与 map 对比 |
| `02_priority_queue.cpp` | 默认最大堆、`greater<int>` 最小堆、Top-K 最小堆模式 |
| `03_stack_queue.cpp` | stack LIFO、queue FIFO、front/back/top 的区别 |
| `04_deque.cpp` | 双端 push/pop、随机访问、与 vector 头插复杂度对比 |

## 易错点 Common Pitfalls

1. **`unordered_*` 迭代顺序不定**——想要升序或稳定顺序，用 `map`/`set`。
2. **`unordered_map[key]` 照样自动插入默认值**——判断存在用 `count`/`find`，别用 `[]`（同 M3 坑）。
3. **`priority_queue` 默认是最大堆**——`top()` 返回的是**最大**元素。要最小堆必须写全三个模板参数：`priority_queue<T, vector<T>, greater<T>>`，漏掉会退回默认最大堆。
4. **`priority_queue` 没有迭代器、遍历无意义**——按序输出要 `top()` + `pop()` 循环。
5. **`stack`/`queue`/`priority_queue` 没有 `clear()`（C++17）**——想清空重新构造一个。
6. **空容器调 `top()`/`front()`/`pop()` 是 UB**——先 `empty()` 判断。
7. **`deque` 中间插入/删除是 O(n)**——只有两端才是 O(1)。
8. **自定义比较器方向易反**——`priority_queue` 里 `comp(a,b)` 返回 true 表示 a 优先级**更低**（更晚出队）。想「次数多的先出」，比较器要写「`a.second < b.second` 时返回 true」。
9. **平均 O(1) ≠ 最坏 O(1)**——哈希冲突可能退化到 O(n)，刷题一般够用，别在常数上过度纠结。

## 练习 Exercises → `practice/03-1/exercises.md`

**10 道练习**，按「由浅入深」分三层推进（先自己写，再对照 `practice/03-1/solutions/`）：

- **A 热身 Basic**：① unordered_map 频率统计 ② stack 最小操作 ③ queue 最小操作 ④ priority_queue 最大/最小堆
- **B 核心 Core**：⑤ unordered_set 去重+存在性 ⑥ 括号匹配（stack，LeetCode 20）⑦ 报数出列（queue，约瑟夫环）⑧ 前 K 大（priority_queue）⑨ deque 回文检查
- **C 综合 Capstone**：⑩ 前 K 高频词（unordered_map + priority_queue，LeetCode 347 思路）

做完填文末自评表，回来 review。

## 自测 Self-Check

- `unordered_map` 和 `map` 的区别？什么场景必须用 `map`？
- 怎么把 `priority_queue` 变成最小堆？`top()` 默认返回最大还是最小？
- `stack` / `queue` / `deque` 各适合什么场景？举一个刷题例子。
- 想按顺序打印 `priority_queue` 里的元素，应该怎么做？能直接遍历吗？
- 统计词频、再按次数取前 3——用哪些容器串起来？各自复杂度？
- `vector` 头插 O(n)、`deque` 头插 O(1)——为什么？
