// examples/03-1/02_priority_queue.cpp — priority_queue：堆，每次取最大/最小
// priority_queue: heap, push/pop O(log n), top O(1)
#include <functional> // std::greater
#include <iostream>
#include <queue>
#include <vector>

// 逐个 top + pop 按优先级出队（priority_queue 没有迭代器，只能这样按序取）
void drain(std::priority_queue<int>& pq, const char* name) {
  std::cout << name << ": ";
  while (!pq.empty()) {
    std::cout << pq.top() << " ";
    pq.pop();
  }
  std::cout << "\n";
}

int main() {
  // 1. 默认最大堆：top() 是最大元素
  std::priority_queue<int> max_heap;
  for (int x : {3, 1, 4, 1, 5, 9, 2, 6})
    max_heap.push(x);
  drain(max_heap, "max-heap"); // 9 6 5 4 3 2 1 1

  // 2. 最小堆：写全三个模板参数，第三个用 greater<int>
  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
  for (int x : {3, 1, 4, 1, 5, 9, 2, 6})
    min_heap.push(x);
  std::cout << "min-heap top=" << min_heap.top() << "\n"; // 1
  min_heap.pop();
  std::cout << "min-heap top after pop=" << min_heap.top() << "\n"; // 1

  // 3. Top-K 模式：求最大的 k 个 → 维护大小为 k 的【最小堆】
  //    新数比堆顶（当前第 k 大）大，就替换掉它。复杂度 O(n log k)。
  std::priority_queue<int, std::vector<int>, std::greater<int>> topk;
  std::size_t k = 3;
  for (int x : {3, 1, 4, 1, 5, 9, 2, 6}) {
    if (topk.size() < k) {
      topk.push(x);
    } else if (x > topk.top()) {
      topk.pop();
      topk.push(x);
    }
  }
  std::cout << "top " << k << " largest: ";
  while (!topk.empty()) { // 最小堆按升序吐出的正好是最大的 k 个
    std::cout << topk.top() << " ";
    topk.pop();
  }
  std::cout << "\n"; // 5 6 9

  return 0;
}
