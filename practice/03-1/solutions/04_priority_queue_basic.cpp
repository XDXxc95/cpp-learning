// practice/03-1/solutions/04_priority_queue_basic.cpp — 参考答案：最大堆 / 最小堆
#include <functional> // std::greater
#include <iostream>
#include <queue>
#include <vector>

void drain(std::priority_queue<int>& pq) {
  while (!pq.empty()) {
    std::cout << pq.top() << " ";
    pq.pop();
  }
  std::cout << "\n";
}

void drain(std::priority_queue<int, std::vector<int>, std::greater<int>>& pq) {
  while (!pq.empty()) {
    std::cout << pq.top() << " ";
    pq.pop();
  }
  std::cout << "\n";
}

int main() {
  // 1. 默认最大堆：top() 是最大元素 → 逐个出队是从大到小
  std::priority_queue<int> max_heap;
  for (int x : {3, 1, 4, 1, 5, 9, 2, 6})
    max_heap.push(x);
  drain(max_heap); // 9 6 5 4 3 2 1 1

  // 2. 最小堆：写全三个模板参数，第三个用 greater<int>
  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
  for (int x : {3, 1, 4, 1, 5, 9, 2, 6})
    min_heap.push(x);
  drain(min_heap); // 1 1 2 3 4 5 6 9

  return 0;
}
// 注释回答：默认 priority_queue 的 top() 返回【最大】元素（最大堆）。
// 变成最小堆：priority_queue<int, vector<int>, greater<int>>——第二个参数是底层容器，
// 第三个是比较器 greater<int>（大于号排序 → 最小先出队）。
