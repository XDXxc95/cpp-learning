// examples/03-1/03_stack_queue.cpp — stack/queue：LIFO 与 FIFO
// stack/queue: LIFO and FIFO container adapters
#include <iostream>
#include <queue>
#include <stack>

int main() {
  // stack：后进先出 LIFO，只能访问 top()（栈顶）
  std::stack<int> st;
  for (int x : {1, 2, 3})
    st.push(x);
  std::cout << "stack top=" << st.top() << " size=" << st.size() << "\n"; // 3
  while (!st.empty()) {
    std::cout << st.top() << " "; // 3 2 1：后进先出
    st.pop();
  }
  std::cout << "<- LIFO\n";

  // queue：先进先出 FIFO，front() 队头、back() 队尾
  std::queue<int> q;
  for (int x : {1, 2, 3})
    q.push(x);
  std::cout << "queue front=" << q.front() << " back=" << q.back() << "\n"; // 1 3
  while (!q.empty()) {
    std::cout << q.front() << " "; // 1 2 3：先进先出
    q.pop();
  }
  std::cout << "<- FIFO\n";

  // 两者都没有迭代器、没有 clear()（C++17）——想「清空」就重新构造一个
  // std::stack<int> st2;   // 等价于把 st 清空

  return 0;
}
