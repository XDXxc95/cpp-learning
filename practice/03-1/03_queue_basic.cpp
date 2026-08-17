// practice/03-1/03_queue_basic.cpp — 练习 3：queue 最小操作
//
// 题目：
//   依次 push 1、2、3，然后：
//     1. 打印 front() 和 back()（应看到 1 和 3）
//     2. while (!empty()) 循环里：打印 front() 再 pop()，直到空
//
// 注释里回答：
//   front() / back() 各指哪里？和 stack 只有一个 top() 有什么区别？
//   queue 第一个和最后一个。首尾。 队列出口入口是两个，所以有两个取值的方式，stack出口入口是一个，所以只有一个top/
//
// 完整题目见 practice/03-1/exercises.md；先自己写，再对照 solutions/03_queue_basic.cpp
#include <iostream>
#include <queue>

int main() {
  std::queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);

  std::cout << q.front() << " " << q.back() << "\n";

  while (!q.empty()) {
    std::cout << q.front() << " ";
    q.pop();
  }

  return 0;
}
