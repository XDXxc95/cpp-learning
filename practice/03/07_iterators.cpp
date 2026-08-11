// practice/03/07_iterators.cpp — M3 练习7：迭代器专项
// 目标：搞懂迭代器三件事——[begin,end) 左闭右开、正向/反向、distance
// 输入：第一行 n，第二行 n 个整数
// 要求：
//   1. 正向迭代器遍历打印（不用范围 for：用 it = v.begin(); it != v.end(); ++it）
//   2. std::distance(v.begin(), v.end()) 求长度，打印（应等于 n）
//   3. 体会左闭右开：打印 *(v.end() - 1)（最后一个元素）——注意 end() 本身不指向元素
//   4. 反向迭代器 rbegin/rend 打印倒序
// 注释里回答：为什么循环条件写成 it != v.end() 而不是 it <= v.end()？
#include <iostream>
#include <vector>

int main() {
  // TODO: 你的实现（要求 1-4）

  return 0;
}
