// practice/03-1/02_stack_basic.cpp — 练习 2：stack 最小操作
//
// 题目：
//   依次 push 1、2、3，然后：
//     1. 打印 top()（应看到 3）
//     2. while (!empty()) 循环里：打印 top() 再 pop()，直到空
//
// 注释里回答：
//   为什么输出顺序是 3 2 1？（提示：LIFO 是什么意思）
//   stack 先进后出。 Last in first out
//
// 完整题目见 practice/03-1/exercises.md；先自己写，再对照 solutions/02_stack_basic.cpp
#include <iostream>
#include <stack>

int main() {
  std::stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);

  std::cout << s.top() << "\n";

  while (!s.empty()) {
    std::cout << s.top() << " ";
    s.pop();
  }

  return 0;
}
