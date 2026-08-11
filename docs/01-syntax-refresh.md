# M01 · 语法查漏补缺 | Syntax Refresh & Gap Check

> 目标 Goals：快速过一遍核心语法，用自测题找出你的薄弱点 ｜ 预计 Est.：1~2 小时 ｜ 难度：★☆☆~★★☆
>
> 这个模块**不是教学**，是「体检」。你已学过基础，本节用 4 个示例快速回顾，用 6 道自测题定位弱点，然后交给 Claude 针对性补课。

## 本节要点 Key Points

- 基本类型、sizeof、隐式/显式转换（整数除法陷阱）
- 控制流：if / for / range-for / while / do-while / switch
- 函数：值传递 vs 引用传递、默认参数、重载
- 类：构造、私有成员、封装、const 成员函数

## 快速回顾 Review

### 1. 类型 Types（`examples/01/01_types.cpp`）

```cpp
bool   b = true;         // 布尔（1 字节）
char   c = 'A';          // 字符（本质是整数，'A'+1 == 'B'）
int    i = 42;           // 整数（本机 4 字节）
double d = 3.14;         // 双精度浮点（8 字节）
std::string s = "hi";    // STL 字符串
```

**重点陷阱 | The trap**：整数除法截断。

```cpp
int a = 7, b = 2;
a / b        // 3    ← int/int 得 int，截断
a / 2.0      // 3.5  ← 遇到浮点就是浮点除法
(double)a / b // 3.5  ← 显式转换
```

刷题遇到「平均值、比例、中位数」时，这个坑必踩一次。**规则**：想保留小数，至少让一个操作数是 `double`。

### 2. 控制流 Control Flow（`examples/01/02_control_flow.cpp`）

| 语句 | 何时用 |
| --- | --- |
| `if / else` | 条件分支 |
| `for (int i = 0; i < n; ++i)` | 需要下标的循环 |
| `for (int x : v)` | 只要遍历容器，不要下标（C++11 range-for） |
| `while / do-while` | 次数未知；do-while 至少执行一次 |
| `switch` | 对离散值多分支（**别忘了每个 case 的 `break`**） |

**关键**：能拿下标 vs 只能拿值。练习 3 就是对比这个。

### 3. 函数 Functions（`examples/01/03_functions.cpp`）

- **值传递 pass-by-value**：复制副本，改不到原变量。
- **引用参数 pass-by-reference**：`int& a`，能改原变量、且不复制（大对象传引用省内存）。
- **默认参数 default args**：`void f(int a, int b = 10)`，默认值只能放右侧。
- **重载 overloading**：同名函数不同参数列表，编译器按实参选一个。

> 传大对象（如 `std::string`、`std::vector`）时，用 `const T&` 是标配：不复制 + 不改动 + 能读。

### 4. 类 Classes（`examples/01/04_class_basics.cpp`）

```cpp
class Counter {
public:                                      // 公开接口 public interface
    Counter(std::string name, int start)     // 构造函数（初始化列表 : name_(name)...）
        : name_(name), count_(start) {}
    void increment() { ++count_; }
    int  value() const { return count_; }    // const 成员：不修改对象
private:                                     // 私有封装 encapsulation
    std::string name_;
    int count_;
};
```

- **初始化列表** `: name_(name)` 比在函数体里赋值更高效、且是唯一能初始化 `const`/引用成员的方式。
- **`const` 成员函数**：承诺不改对象，可对 const 对象调用。
- **封装**：私有成员只能通过公开方法操作——这是「面向对象」最核心的意义，练习 4 强化这个。

## 代码示例 Examples

| 文件 | 主题 |
| --- | --- |
| `examples/01/01_types.cpp` | 类型、sizeof、整数除法 |
| `examples/01/02_control_flow.cpp` | 全部控制流语句 |
| `examples/01/03_functions.cpp` | 传参、默认参数、重载、引用 |
| `examples/01/04_class_basics.cpp` | 类、构造、const、封装 |

全部已编译运行验证过。自己再编译一次加深印象：

```bash
tools/compile.sh examples/01/01_types.cpp
```

## 易错点 Common Pitfalls

1. **整数除法**：`7/2 == 3`（不是 3.5）。见上。
2. **`switch` 漏 `break`**：会「穿透」执行下一个 case。
3. **range-for 拿不到下标**：需要下标用下标循环，或用 `for (int i = 0; i < v.size(); ++i)`。
4. **默认参数位置**：`void f(int a = 1, int b)` 是编译错误。
5. **`v.size()` 返回 `size_t`（无符号）**：`for (int i = 0; i < v.size(); ++i)` 在有 `-Wall -Wextra` 时可能出「有符号/无符号比较」警告。可写 `for (size_t i = 0; ...)` 或 `(int)v.size()`。

## 练习 Exercises

打开 **`practice/01/exercises.md`**：6 道自测题（含难度标注），先自己写，写完对照 `practice/01/solutions/`。

完成后**把你的自评表告诉 Claude**（全 ✅ → 直接进 M2；有 ⚠️/❌ → 让 Claude 补课）。

## 自测 Self-Check

1. 不用编译，说出 `'a' + 3` 的值类型和值。
2. range-for 和下标 for，什么时候必须用下标？
3. `void swap(int a, int b)` 为什么换不了外面的变量？`void swap(int& a, int& b)` 为什么可以？
4. 练习 6 的指针版 swap 里的 `*` 和 `&` 分别是什么运算？——**想不出来的话，这正说明 M2 指针模块对你是必要的。**
