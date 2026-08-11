// practice/03/solutions/08_algorithms.cpp — 参考答案：<algorithm> 常用算法
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> v;
  for (int i = 0; i < n; i++) {
    int x = 0;
    std::cin >> x;
    v.push_back(x);
  }

  std::sort(v.begin(), v.end());
  std::cout << "sorted: ";
  for (int x : v) std::cout << x << " ";
  std::cout << "\n";

  std::cout << "sum=" << std::accumulate(v.begin(), v.end(), 0) << "\n";

  // min/max_element 返回迭代器，必须解引用才是值
  auto mn = std::min_element(v.begin(), v.end());
  auto mx = std::max_element(v.begin(), v.end());
  std::cout << "min=" << *mn << " max=" << *mx << "\n";

  int target = 0;
  std::cin >> target;
  std::cout << "count of " << target << " = "
            << std::count(v.begin(), v.end(), target) << "\n";

  std::reverse(v.begin(), v.end());
  std::cout << "reversed: ";
  for (int x : v) std::cout << x << " ";
  std::cout << "\n";
  return 0;
}
