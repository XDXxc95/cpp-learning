# 练习 1 参考答案 · 预测输出

```cpp
int a = 7, b = 2;
double r1 = a / b;         // 3.0   ← 整数除法先算出 int 3，再转成 double
double r2 = (double)a / b; // 3.5   ← 显式转 double 后是浮点除法
bool   r3 = 3 > 2;         // true（输出时显示 1）
char   r4 = 'A' + 1;       // 'B'   ← 字符就是整数，ASCII 'A'=65，65+1=66='B'
int    r5 = r4;            // 66    ← char → int 是安全扩宽
```

## 关键点 Key points

1. **整数除法截断**：`7/2` 是 `int` 除法，结果是 3（截断，不是四舍五入）。要浮点结果，至少一个操作数是浮点：`a/2.0` 或 `(double)a/2`。
2. **char 是整数**：`'A' + 1 == 'B'`。char 本质是 1 字节整数，可参与算术。
3. **隐式转换**：窄类型会隐式扩宽为宽类型（char→int→double）。反向（double→int）会截断且有警告风险，尽量显式写 `(int)x`。

> 刷题影响：LeetCode 上「整数溢出」「除法截断」是高频坑，先在编译器层面把它想清楚。
