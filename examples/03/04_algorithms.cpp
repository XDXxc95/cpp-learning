// examples/03/04_algorithms.cpp — <algorithm> 常用算法
// Common algorithms from <algorithm>
#include <algorithm>
#include <iostream>
#include <numeric>   // std::accumulate
#include <vector>

int main() {
  std::vector<int> v = {5, 3, 8, 1, 9, 2, 7};

  // sort：默认升序
  std::sort(v.begin(), v.end());
  std::cout << "sorted: ";
  for (int x : v) std::cout << x << " ";
  std::cout << "\n";

  // 降序：传比较器（这里先用简单 lambda，M5 细讲）
  std::sort(v.begin(), v.end(), [](int x, int y) { return x > y; });
  std::cout << "desc  : ";
  for (int x : v) std::cout << x << " ";
  std::cout << "\n";

  // binary_search：要求区间已有序，O(log n)
  std::sort(v.begin(), v.end());
  std::cout << "binary_search 5 ? " << std::binary_search(v.begin(), v.end(), 5) << "\n";
  std::cout << "binary_search 6 ? " << std::binary_search(v.begin(), v.end(), 6) << "\n";

  // find：顺序查找（不要求有序），O(n)，找到返回迭代器
  auto it = std::find(v.begin(), v.end(), 8);
  if (it != v.end()) std::cout << "find 8 at index " << (it - v.begin()) << "\n";

  // count / accumulate / min_element / max_element
  std::cout << "count of 3 : " << std::count(v.begin(), v.end(), 3) << "\n";
  std::cout << "sum        : " << std::accumulate(v.begin(), v.end(), 0) << "\n";
  std::cout << "min / max  : " << *std::min_element(v.begin(), v.end()) << " / "
            << *std::max_element(v.begin(), v.end()) << "\n";

  // reverse：原地反转
  std::reverse(v.begin(), v.end());
  std::cout << "reversed front: " << v.front() << "\n";

  return 0;
}
