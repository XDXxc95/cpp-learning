# 参考答案 · 练习 2 — `01_debug_me.cpp` 的 bug

> 参考答案 Reference solution —— 先自己练完再看。

## 症状 Symptom

直接运行 `build/01_debug_me.exe`：

```text
3 5 7 4
```

期望：相邻两两求和，`data = {1,2,3,4}` 应输出 **`3 5 7`**（三个数）。
实际多了一个第 4 项 `4`，而且末尾多了个尾巴——**哪里来的？**

## gdb 定位步骤（用 `tools/gdb.sh`）

```text
(gdb) break 18                     ← 断点在 result.push_back(p[i] + p[i + 1]) 这一行
(gdb) run
Breakpoint 1, adjacent_sums(...) at 01_debug_me.cpp:18
(gdb) print i                      → $1 = 0        ← 第一次进循环
(gdb) print n                      → $2 = 4        ← 共 4 个元素
(gdb) print p[i+1]                 → $3 = 2        ← 0+2=2，正常
(gdb) continue                     ← 第 2 次
(gdb) print i                      → $4 = 1
(gdb) continue                     ← 第 3 次
(gdb) print i                      → $5 = 2
(gdb) continue                     ← 第 4 次（最后一次！）
(gdb) print i                      → $6 = 3        ← i 到了 n-1
(gdb) print p[i+1]                 → $7 = -1414812757   ← 垃圾值！
```

## 病因 Cause

循环条件是 `i < n`，所以 `i` 会跑到 `n-1`。可循环体读的是 **`p[i + 1]`**：

- `i = n-1` 时，`p[i+1]` 就是 **`p[n]`**；
- `p` 指向的缓冲区只有 `n` 个元素，合法下标是 `0..n-1`；
- `p[n]` 读到了缓冲区**末尾之外**——**越界读 out-of-bounds read**，返回的是内存里的随机垃圾值（本次碰巧是 0，所以 `4+0=4`）。

越界读不会崩溃、`-Wall` 也不会报——因为 `vector::data()` 返回的裸指针不做任何检查。**「运行正常」≠「没有 bug」。**

## 修复 Fix

把 `practice/06/01_debug_me_fixed.cpp` 里的循环条件改成 `i + 1 < n`（或 `i < n - 1`）：

```cpp
// 修复前 Before
for (size_t i = 0; i < n; ++i) {
    result.push_back(p[i] + p[i + 1]);
}

// 修复后 After —— 最后一次 i 满足 i+1 < n，p[i+1] 永远合法
for (size_t i = 0; i < n - 1; ++i) {
    result.push_back(p[i] + p[i + 1]);
}
```

修复后输出：`3 5 7`（三个数，正确）。

## 验证 Verify（gdb）

在修复版上：

```text
(gdb) break 18
(gdb) run
(gdb) print n          → 4
(gdb) print i          → 0, 1, 2   （continue 三次）
(gdb) continue         → 程序正常跑完，输出 3 5 7
```

循环只进 3 次，`i` 最大到 2，`p[i+1]` 最大到 `p[3]`，不再越界。

## 一句话总结

**当访问 `i+1`、`i-1` 这类「邻居下标」时，循环边界必须给越界留出余地。** 这种 bug 藏得深，gdb 的价值就在「在越界前一刻把 `i` 和 `p[i+1]` 亮出来」。
