// practice/03-1/04_priority_queue_basic.cpp — 练习 4：priority_queue 最大堆/最小堆
//
// 题目：
//   把 {3, 1, 4, 1, 5, 9, 2, 6} 全部入堆，然后：
//     1. 用默认 priority_queue<int>，逐个 top + pop 打印（应是从大到小）
//     2. 再造一个最小堆（第三个模板参数用 std::greater<int>），同样逐个打印（应是从小到大）
//
// 注释里回答：
//   默认 priority_queue 的 top() 返回最大还是最小？怎么把它变成最小堆？（写全三个模板参数）
//  最大。 写全三个模板参数。最后一个使用 std::greater  比较器。 std::priority_queue<int, std::vector<int>, std::greater<int>>
// 完整题目见 practice/03-1/exercises.md；先自己写，再对照 solutions/04_priority_queue_basic.cpp
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int main() {
  std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6};

  std::priority_queue<int> pq;
  for (const auto& x : v) {
    pq.push(x);
  }

  while (!pq.empty()) {
    std::cout << pq.top() << " ";
    pq.pop();
  }
  std::cout << "\n";

  std::priority_queue<int, std::vector<int>, std::greater<int>> gq;
  for (const auto& x : v) {
    gq.push(x);
  }

  while (!gq.empty()) {
    std::cout << gq.top() << " ";
    gq.pop();
  }
  std::cout << "\n";

  return 0;
}
