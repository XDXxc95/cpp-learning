// practice/01/03_max_element.cpp — M1 练习3：找最大值及下标
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v{4, 9, 2, 7, 5};
  // 期望：最大值 9，下标 1

  // === 版本①：下标 for 循环 ===
  // 需要记录 max_val 和 max_idx。初始化 max_val = v[0], max_idx = 0，从 i = 1
  // 起比。
  // TODO: 你的代码（最后用 std::cout 打印 max_val 和 max_idx）
  int max_val = v[0];
  int max_idx = 0;
  size_t length = v.size();

  for (size_t i = 1; i < length; ++i) {
    if (v[i] > max_val) {
      max_val = v[i];
      max_idx = i;
    }
  }
  std::cout << "max_val: " << max_val << " max_idx: " << max_idx << std::endl;

  // === 版本②：range-for ===
  // for (int x : v) —— x 是"值"，拿不到下标，所以这版只求最大值。
  // 注意：初始化别用 0（最大值若是负数会错），用第一个元素。
  // TODO: 你的代码（打印 max_val）
  max_val = v[0];
  for (auto x : v) {
    if (x > max_val) {
      max_val = x;
    }
  }
  std::cout << "max_val: " << max_val << std::endl;

  return 0;
}
