// practice/04-1/06_virtual_dtor.cpp — 练习 6：虚析构与内存泄漏
//
// 题目：
//   1. 写 BadBase（【非虚】析构）和 BadDerived：
//      BadDerived 构造里 new int[100]，析构里 delete[] 并打印 "~BadDerived"
//      （BadBase 析构也打印 "~BadBase"）。
//   2. main 里 BadBase* p = new BadDerived; delete p; 观察哪些析构跑了。
//   3. 复制一份改成 GoodBase（【虚】析构）/ GoodDerived，同样操作，再观察。
//
//   注释里回答：
//     - 第 2 步输出了哪些析构？哪个没跑？泄漏了什么？
//     - 编译器对第 2 步的 delete 有没有告警？告警名字里的关键字是什么？
//     - 修复办法是什么（一个字）？
//
// 完整题目见 practice/04-1/exercises.md；先自己写，再对照 solutions/06_virtual_dtor.cpp
#include <iostream>

// TODO: 定义 BadBase / BadDerived

// TODO: 定义 GoodBase / GoodDerived

int main() {
  // TODO: 你的实现
  return 0;
}
