// practice/03/08_algorithms.cpp — M3 练习8：<algorithm> 常用算法专项
// 输入：第一行 n，第二行 n 个整数
// 要求（对同一份数据依次操作，逐步打印结果）：
//   1. std::sort 升序后打印
//   2. std::accumulate 求和，打印（注意它在 <numeric> 里，不是 <algorithm>）
//   3. min_element / max_element 求最小最大，打印（返回的是迭代器，要 *it 解引用）
//   4. std::count 数某个数出现几次（再输入一个 target），打印
//   5. std::reverse 反转后打印
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  // TODO: 你的实现（要求 1-5）
  int n = 0;
  std::cin >> n;

  std::vector<int> v;
  v.reserve(n);

  for (int i = 0; i < n; i++) {
    int input = 0;
    std::cin >> input;
    v.push_back(input);
  }

  std::sort(v.begin(), v.end());
  for (auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";

  std::cout << std::accumulate(v.begin(), v.end(), 0) << "\n";

  std::cout << *std::min_element(v.begin(), v.end()) << "\n";
  std::cout << *std::max_element(v.begin(), v.end()) << "\n";

  int target = 0;
  std::cin >> target;
  std::cout << std::count(v.begin(), v.end(), target) << "\n";

  std::reverse(v.begin(), v.end());
  for (auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << " ";
  }

  return 0;
}
