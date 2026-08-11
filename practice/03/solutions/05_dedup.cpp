// practice/03/solutions/05_dedup.cpp — 参考答案：set 去重 + binary_search 查找
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
  int n = 0;
  std::cin >> n;

  std::set<int> s;
  for (int i = 0; i < n; i++) {
    int x = 0;
    std::cin >> x;
    s.insert(x);   // 重复插入无效 → 自动去重，且升序
  }

  std::cout << "dedup: ";
  for (int x : s) std::cout << x << " ";
  std::cout << "\n";

  int target = 0;
  std::cin >> target;

  // binary_search 要求「随机访问 + 已排序」：set 已升序，但迭代器不是随机访问，
  // 所以拷进 vector（同时证明 binary_search 前必须有序）
  std::vector<int> v(s.begin(), s.end());
  bool found = std::binary_search(v.begin(), v.end(), target);
  std::cout << target << (found ? " in\n" : " not in\n");
  return 0;
}
