// practice/04-1/09_vptr_size.cpp — 练习 9：虚函数的代价（对象大小）
//
// 题目：
//   1. 定义 Plain：两个 int 成员，无虚函数
//   2. 定义 Poly：两个 int 成员 + 一个 virtual void f() const
//   3. 用 sizeof 打印两者的字节数，以及一个 int* 的大小作为参照
//
//   注释里回答：
//     - 两者的 sizeof 差多少？这个差值是什么？
//     - 为什么加了 virtual 对象会变大？（提示：虚函数表 / vptr）
//     - 由此推论：什么时候【不该】给函数加 virtual？
//
// 完整题目见 practice/04-1/exercises.md；先自己写，再对照 solutions/09_vptr_size.cpp
#include <iostream>

// TODO: 定义 Plain

// TODO: 定义 Poly

int main() {
  // TODO: 你的实现
  return 0;
}
