// practice/03/05_dedup.cpp — M3 练习5：set 去重 + 查找
// 输入：第一行 n，第二行 n 个整数（可能重复）；再输入一个 target
// 输出：set 去重后升序打印；判断 target 在不在
// 示例：6 / 3 1 3 2 1 4 / 3 → "1 2 3 4" 和 "3 in"
// 注释里回答：binary_search 前为什么必须先排序？ binary_search 必须是已排序的。

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
  // TODO: 你的实现
  int n = 0;
  std::cin >> n;

  std::set<int> s;
  for (int i = 0; i < n; i++) {
    int input = 0;
    std::cin >> input;
    s.insert(input);
  }

  int target = 0;
  std::cin >> target;

  std::vector<int> out(s.begin(), s.end());
  std::sort(out.begin(), out.end());
  for (size_t i = 0; i < out.size(); i++) {
    std::cout << out[i] << " ";
  }
  std::cout << "\n";

  bool find = std::binary_search(out.begin(), out.end(), target);
  if (find) {
    std::cout << target << " in\n";
  } else {
    std::cout << target << " not in\n";
  }

  return 0;
}
