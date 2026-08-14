// practice/03-1/solutions/03_queue_basic.cpp — 参考答案：queue 最小操作
#include <iostream>
#include <queue>

int main() {
  std::queue<int> q;
  for (int x : {1, 2, 3})
    q.push(x);
  std::cout << "front=" << q.front() << " back=" << q.back() << "\n"; // 1 3
  while (!q.empty()) {
    std::cout << q.front() << " ";
    q.pop();
  }
  std::cout << "\n";
  return 0;
}
// 注释回答：front() 是队头（最先进入、下一个要出队的），back() 是队尾（最后进入的）。
// stack 只有一个 top() 因为它是「单端」的——只能从栈顶进/出；
// queue 是「双端但不对称」：从队尾 push、从队头 pop，所以要看两端。
