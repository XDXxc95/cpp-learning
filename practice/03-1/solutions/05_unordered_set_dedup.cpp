// practice/03-1/solutions/05_unordered_set_dedup.cpp — 参考答案：unordered_set 去重 + 存在性
#include <iostream>
#include <unordered_set>

int main() {
  int n;
  std::cin >> n;
  std::unordered_set<int> s;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    s.insert(x);
  }
  std::cout << "dedup count=" << s.size() << ": ";
  for (int x : s)
    std::cout << x << " "; // 顺序不定
  std::cout << "\n";

  int target;
  std::cin >> target;
  if (s.count(target)) {
    std::cout << target << " in\n";
  } else {
    std::cout << target << " not in\n";
  }
  return 0;
}
// 注释回答：需要【有序】（去重后升序遍历、找前驱后继）用 set；只求存在性判断、
// 不在乎顺序、想要平均 O(1) 时用 unordered_set。刷题默认 unordered_*，
// 题目明确要求有序或需要有序遍历时再用 map/set。
