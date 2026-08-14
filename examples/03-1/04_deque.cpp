// examples/03-1/04_deque.cpp — deque：双端队列，两端插入删除 O(1)
// deque: double-ended queue, O(1) push/pop at both ends, random access
#include <deque>
#include <iostream>
#include <vector>

int main() {
  // 双端操作：push/pop 头尾都是 O(1)
  std::deque<int> d;
  d.push_back(2);
  d.push_front(1);
  d.push_back(3);
  // d = {1, 2, 3}
  std::cout << "front=" << d.front() << " back=" << d.back() << "\n"; // 1 3
  d.pop_front();                                                      // 移除 1
  d.pop_back();                                                       // 移除 3
  std::cout << "after pop both ends, front=" << d.front() << "\n";    // 2

  // 随机访问 O(1)，可下标、可 range-for
  for (int i = 0; i < 5; i++)
    d.push_back(i * 10);
  std::cout << "d[2]=" << d[2] << "  all: ";
  for (int x : d)
    std::cout << x << " ";
  std::cout << "\n";

  // 对比：vector 头插要整体后移 → O(n)；deque 头插 → O(1)
  std::vector<int> v;
  for (int i = 0; i < 5; i++)
    v.push_back(i);
  v.insert(v.begin(), 99); // O(n)
  std::cout << "vector front after insert=" << v.front() << "\n";

  // 注意：deque 中间插入/删除仍是 O(n)
  d.insert(d.begin() + 2, 42); // 中间插入 O(n)
  std::cout << "deque size after middle insert=" << d.size() << "\n";

  return 0;
}
