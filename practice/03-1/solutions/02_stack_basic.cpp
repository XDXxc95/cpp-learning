// practice/03-1/solutions/02_stack_basic.cpp — 参考答案：stack 最小操作
#include <iostream>
#include <stack>

int main() {
  std::stack<int> st;
  for (int x : {1, 2, 3})
    st.push(x);
  std::cout << "top=" << st.top() << "\n"; // 3：栈顶是最后进去的
  while (!st.empty()) {
    std::cout << st.top() << " ";
    st.pop();
  }
  std::cout << "\n";
  return 0;
}
// 注释回答：LIFO = Last In First Out（后进先出）。最后 push 的 3 在栈顶，
// 每次 pop 都先取栈顶，所以输出 3 2 1——和进去的顺序正好反过来。
