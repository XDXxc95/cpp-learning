// examples/03-1/02_vector_basics.cpp — std::vector 基础操作
#include <cstddef>
#include <iostream>
#include <vector>

int main() {
  // --- 创建 ---
  std::vector<int> v1;              // 空
  std::vector<int> v2(5);           // 5 个 0
  std::vector<int> v3(3, 7);        // 3 个 7
  std::vector<int> v4 = {1, 2, 3, 4, 5};  // 初始化列表
  std::cout << "v1.size() = " << v1.size() << "\n";  // 0
  std::cout << "v2:";
  for (int x : v2) {
    std::cout << ' ' << x;          // 0 0 0 0 0
  }
  std::cout << "\n";

  // --- push_back 尾部追加（自动扩容，摊还 O(1)）---
  v1.push_back(10);
  v1.push_back(20);
  v1.push_back(30);
  std::cout << "v1.size() = " << v1.size() << "\n";  // 3

  // --- [] vs at()：[] 越界不检查；at() 越界抛 std::out_of_range ---
  std::cout << "v4[2] = " << v4[2] << "\n";          // 3
  // 想试 at() 越界抛异常？把下面注释打开：
  // try {
  //   std::cout << v4.at(99) << "\n";
  // } catch (const std::out_of_range& e) {
  //   std::cout << "caught: " << e.what() << "\n";
  // }

  // --- front / back ---
  std::cout << "v4.front() = " << v4.front()
            << ", v4.back() = " << v4.back() << "\n";  // 1, 5

  // --- 下标遍历（i 用 size_t，避免与 int 混比触发警告）---
  for (std::size_t i = 0; i < v4.size(); ++i) {
    std::cout << v4[i] << ' ';
  }
  std::cout << "\n";

  // --- pop_back 删尾 ---
  v4.pop_back();
  std::cout << "after pop_back, v4.size() = " << v4.size() << "\n";  // 4

  return 0;
}
