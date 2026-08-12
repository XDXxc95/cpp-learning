// practice/03/07_iterators.cpp — M3 练习7：迭代器专项
// 目标：搞懂迭代器三件事——[begin,end) 左闭右开、正向/反向、distance
// 输入：第一行 n，第二行 n 个整数
// 要求：
//   1. 正向迭代器遍历打印（不用范围 for：用 it = v.begin(); it != v.end(); ++it）
//   2. std::distance(v.begin(), v.end()) 求长度，打印（应等于 n）
//   3. 体会左闭右开：打印 *(v.end() - 1)（最后一个元素）——注意 end() 本身不指向元素
//   4. 反向迭代器 rbegin/rend 打印倒序
// 注释里回答：为什么循环条件写成 it != v.end() 而不是 it <= v.end()？ 这是迭代器，是指针，直接比较是比较地址值，不一定连续或者end比之前的都大。另外end是哨兵，不是实际的最后一个位置，也不能使用=
#include <iostream>
#include <vector>

int main() {
  int n = 0;
  std::cin >> n;

  std::vector<int> v;
  v.reserve(n);
  //这样写和直接 std::vector<int> v(n); 那个更好？为什么？

  for (int i = 0; i < n; i++) {
    int input = 0;
    std::cin >> input;
    v.push_back(input);
  }

  for (auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";

  std::cout << std::distance(v.begin(), v.end()) << "\n";

  std::cout << *(v.end() - 1) << "\n";

  for (auto it = v.rbegin(); it != v.rend(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";

  return 0;
}
