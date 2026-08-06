# M01 练习 · 语法查漏补缺 | Syntax Gap Check

> 用法 How to use：
> 1. 在 `practice/01/` 下**自己建文件写代码**（文件名随意，如 `my_01.cpp`）
> 2. 用 `tools/compile.sh <你的文件>` 编译运行，确认没警告没错误
> 3. **写完再看** `solutions/` 对照
> 4. 做完全部后，按文末自评表判断哪些概念要补课

本模块的练习 = **自测**。目的不是难倒你，而是快速找出基础里的薄弱点，交给 Claude 针对性补。

---

## 练习 1 · 预测输出（易 · 类型与转换）| Predict the output

不编译，先心算下面这段会输出什么：

```cpp
int a = 7, b = 2;
double r1 = a / b;        // ？
double r2 = (double)a / b; // ？
bool   r3 = 3 > 2;        // ？
char   r4 = 'A' + 1;      // ？
int    r5 = r4;           // ？
```

然后编译运行验证。**目标**：理解整数除法截断、显式/隐式转换。

## 练习 2 · 素数判断（中 · 函数）| isPrime

写一个函数 `bool isPrime(int n)`，判断 n 是否为素数（质数）。主函数里打印 2~30 的所有素数。

**达标标准**：能处理 `n < 2`；有提前返回；循环到 `√n` 即可（可先写简单版再优化）。

## 练习 3 · 找最大值（中 · 容器+循环）| Max element

给定 `std::vector<int> v{4, 9, 2, 7, 5}`，写代码找最大值和它的下标（位置）。要求：
1. 用**下标 for 循环**写一版
2. 用 **range-for** 再写一版

**目标**：对比两种遍历，体会下标与「值」的区别。

## 练习 4 · 银行账户类（中 · 类与封装）| BankAccount

实现一个 `BankAccount` 类：

```cpp
class BankAccount {
    // 私有成员：string owner_; double balance_;
    // 构造：BankAccount(name, initial_balance)
    // void deposit(double amount)   —— 存钱
    // void withdraw(double amount)  —— 取钱，余额不足则打印错误并拒绝
    // double balance() const        —— 查余额
};
```

主函数演示：开个户、存一笔、取一笔、取超额看报错。

**目标**：私有成员 + 公开接口（封装 encapsulation）的完整小例子。

## 练习 5 · 找 Bug（中 · 调试眼力）| Find the bugs

下面代码有两个 Bug，找到并修复（可以编译验证，也可以用 gdb 单步）：

```cpp
// 目标：打印 1 到 10 的平方
#include <iostream>
int main() {
    for (int i = 0; i <= 10; ++i) {   // 一个 bug 在这里
        std::cout << i * i << " ";
        if (i % 5 == 0) std::cout << "\n";   // 另一个 bug 的线索
    }
    std::cout << "\n" << std::endl;
    return 0;
}
```

**目标**：off-by-one 和换行位置，都是刷题最常见的坑。

## 练习 6 · 指针版 swap（进阶 · 指针 vs 引用）| swap by pointers

示例 `03_functions.cpp` 里用了**引用**实现 swap。现在用**指针**实现 `void swapPtr(int* a, int* b)`，并在 main 里调用。

**思考题**：指针版调用时要写 `swapPtr(&x, &y)`，引用版直接 `swap(x, y)`。两者的区别和适用场景是什么？（想不出没关系，这正是下一模块 M2 的主题，记住这个问题即可）

---

## 自评表 Self-Assessment

做完对照答案后，给每项打 ✅ 熟练 / ⚠️ 犹豫 / ❌ 不会：

| 概念 Concept | 练习 | 自评 |
| --- | --- | --- |
| 类型与隐式转换 | 1 | |
| 函数定义/返回值 | 2 | |
| for / range-for / 下标 | 3 | |
| 类、私有成员、封装 | 4 | |
| 边界条件 / 调试 | 5 | |
| 引用（为 M2 铺垫） | 6 | |

**把自评结果告诉 Claude**：
- 全 ✅ → 直接进 M2
- 有 ⚠️/❌ → 让 Claude 针对那一块加练再进 M2
