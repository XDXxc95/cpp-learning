# M3-1 练习 · 高频容器

> 规则：**先自己写，再对照** `practice/03-1/solutions/`。全部完成后填文末自评表。
> 所有练习文件在 `practice/03-1/` 下，命名 `NN_主题.cpp`，用 `tools/compile.sh` 编译运行。
> 练习文件是**空骨架**，你往里面填实现。
> **建议顺序**：按 A → B → C 分层推进；每层做完可先对照答案，再进下一层。

## A 区 · 基础热身 Basic Warm-up

> 目的：把每个新容器「跑通一遍」求手感，题很小，不纠结算法。

### 练习 1 · unordered_map 频率统计 | unordered_map frequency

文件：`practice/03-1/01_unordered_freq.cpp`

输入：第一行 `n`，第二行 `n` 个整数（可能重复）。
用 `std::unordered_map<int, int>` 统计每个数出现次数，**按任意顺序**输出「数 次数」，每行一个。

示例：输入 `6` / `3 1 3 1 3 2` → 输出 `1 2` / `2 1` / `3 3`（**顺序随意**）。

注释里回答：和 M3 练习 4 的 `map` 版本相比，输出顺序为什么可能不一样？把 `unordered_map` 换回 `map` 会怎样？

### 练习 2 · stack 最小操作 | stack warm-up

文件：`practice/03-1/02_stack_basic.cpp`

依次 `push` 1、2、3，然后：
1. 打印 `top()`（应看到 3）
2. `while (!empty())` 循环里：打印 `top()` 再 `pop()`，直到空

注释里回答：为什么输出顺序是 `3 2 1`？（提示：LIFO 是什么意思）

### 练习 3 · queue 最小操作 | queue warm-up

文件：`practice/03-1/03_queue_basic.cpp`

依次 `push` 1、2、3，然后：
1. 打印 `front()` 和 `back()`（应看到 1 和 3）
2. `while (!empty())` 循环里：打印 `front()` 再 `pop()`，直到空

注释里回答：`front()` / `back()` 各指哪里？和 `stack` 只有一个 `top()` 有什么区别？

### 练习 4 · priority_queue 最大堆/最小堆 | max & min heap warm-up

文件：`practice/03-1/04_priority_queue_basic.cpp`

把 `{3, 1, 4, 1, 5, 9, 2, 6}` 全部入堆，然后：
1. 用**默认** `priority_queue<int>`，逐个 `top` + `pop` 打印（应是从大到小）
2. 再造一个最小堆（第三个模板参数用 `std::greater<int>`），同样逐个打印（应是从小到大）

注释里回答：默认 `priority_queue` 的 `top()` 返回最大还是最小？怎么把它变成最小堆？（写全三个模板参数）

## B 区 · 核心应用 Core

> 目的：每个容器刷题里的典型用途来一道标准题。

### 练习 5 · unordered_set 去重 + 存在性 | dedup & membership

文件：`practice/03-1/05_unordered_set_dedup.cpp`

输入：第一行 `n`，第二行 `n` 个整数（可能重复），第三行一个 `target`。
用 `std::unordered_set` 去重，然后：
1. 打印去重后**元素个数**和所有元素（顺序随意，能看到乱序就行）
2. 判断 `target` 在不在集合里，输出 `target in` 或 `target not in`

示例：输入 `6` / `3 1 3 2 1 4` / `3` → 输出 `4` 个元素 + `3 in`。

注释里回答：对比 M3 练习 5 的 `set` 版——什么时候该用 `set`、什么时候用 `unordered_set`？

### 练习 6 · 括号匹配（stack）| Valid parentheses

文件：`practice/03-1/06_valid_parentheses.cpp`

输入一行只含 `(` `)` `[` `]` `{` `}` 的字符串（可用 `getline`）。
判断括号是否匹配：每个左括号必须被**对应类型**的右括号闭合，且嵌套顺序正确。
匹配输出 `valid`，否则 `invalid`。

算法（用 `stack`）：
- 遇到左括号 → `push`
- 遇到右括号 → 看栈顶是不是**同类型**的左括号：是就 `pop`，不是/栈空 → invalid
- 结束时栈必须为空（否则有左括号没闭合）

示例：`({[]})` → `valid`；`([)]` → `invalid`；`((()` → `invalid`；`()` → `valid`。

这是 **LeetCode 20** 原题。

### 练习 7 · 报数出列（queue）| Josephus ring

文件：`practice/03-1/07_queue_josephus.cpp`

经典约瑟夫环：`n` 个人从 1 到 `n` 编号围成一圈，从 1 开始报数，**报到 `k` 的人出列**，下一个人从 1 重新报数，直到所有人出列。
用 `queue` 模拟（每轮）：
- 队头出队，作为「报数」的这个人
- 没报到 `k` → 重新放回**队尾**（轮到后面再报）
- 报到 `k` → 打印出列，不再放回

输入：第一行 `n k`。
输出：出列顺序，空格分隔。

示例：输入 `5 3` → 输出 `3 1 5 2 4`。

### 练习 8 · 前 K 大（priority_queue）| Top K largest

文件：`practice/03-1/08_topk_largest.cpp`

输入：第一行 `n k`，第二行 `n` 个整数。
输出：最大的 `k` 个数（顺序随意即可，逐个打印空格分隔）。

**两种做法任选（都练更好）**：
- 做法 a（最大堆）：全部入默认堆，`pop` k 次。O(n log n)。
- 做法 b（最小堆，推荐）：维护大小为 k 的最小堆，比堆顶大才替换。O(n log k)。

注释里回答：两种做法复杂度各是多少？n 很大而 k 很小（如 n=10⁶, k=10）时，哪个更省？

### 练习 9 · deque 回文检查 | Palindrome with deque

文件：`practice/03-1/09_deque_palindrome.cpp`

输入一行字符串（可能含空格，用 `getline`）。
把每个字符放进 `deque<char>`，用双端比较判断是否回文：
- `while (size > 1)`：比较 `front()` 和 `back()`
- 不同 → 不是回文，结束
- 相同 → `pop_front()` + `pop_back()`，继续
回文输出 `palindrome`，否则 `not palindrome`。

示例：`racecar` → `palindrome`；`hello` → `not palindrome`；`a b a` → `palindrome`（含空格也照样判）。

## C 区 · 综合 · 学后练习 Capstone

> 目的：把本模块的知识串起来，题型贴近刷题/面试。

### 练习 10 · 前 K 高频词（堆解法）| Top K frequent words

文件：`practice/03-1/10_topk_freq_words.cpp`

这是 **M3 练习 9 的「堆解法」版**——把 unordered_map + priority_queue 串起来，LeetCode 347 思路：
1. 用 `std::unordered_map<std::string, int>` 统计一行句子里每个单词出现次数（`getline` + `istringstream` 分词，同 M3 练习 9）
2. 把 `(单词, 次数)` 倒进 `std::vector<std::pair<...>>`
3. 放进 `priority_queue`，自定义比较器，按「**次数降序，次数相同字典序升序**」取前 3 个词，格式 `word count` 每行一个

⚠️ 自定义比较器方向提示：`priority_queue` 里 `comp(a, b)` 返回 `true` 表示 **a 的优先级比 b 低**（a 更晚出队）。想要「次数多的先出」：
- `a.second != b.second` → 返回 `a.second < b.second`（次数少的 = 优先级低）
- 相同 → 返回 `a.first > b.first`（字典序大的 = 优先级低）

示例：输入 `a cat a dog a cat` → 输出 `a 3` / `cat 2` / `dog 1`。

对比 M3 练习 9（map + sort）：那题依赖 `sort` 全排序，这题依赖堆「只关心前 K」。数据量大时堆解法不排序无关元素，更省。

## 自评表 Self-Assessment

| 项目 | ✅ 熟练 | 🔶 基本掌握 | ❌ 薄弱 |
| --- | --- | --- | --- |
| unordered_map / unordered_set（哈希，平均 O(1)、无序） | | | |
| priority_queue（默认最大堆 / `greater` 最小堆 / Top-K） | | | |
| stack / queue（LIFO / FIFO、front/back/top） | | | |
| deque（双端操作、与 vector 对比） | | | |
| 自定义比较器方向（priority_queue 的 comp 语义） | | | |
| 综合应用与容器选型升级 | | | |

填完把结果发给 Claude，全 ✅ → 收官 M3-1 → 进 M4-1 面向对象核心。
