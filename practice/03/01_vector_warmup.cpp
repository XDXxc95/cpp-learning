// practice/03/01_vector_warmup.cpp — M3 练习1：vector 最小操作（热身）
// 目标：跑通 vector 最常用的 4 个点，每题都很小，不求算法只求手感
//   1. 创建：std::vector<int> v（空），用 push_back 依次塞入 3 个数
//   2. 大小与下标：打印 v.size()，再用 [] 读出第 1 个元素打印
//   3. 遍历：用「范围 for」把 v 全部打印（空格分隔）
//   4. 观察 capacity：每 push_back 一次就打印当前 size 和 capacity，
//      体会容量自动翻倍（1,2,4,8...）——这是 vector 自动扩容的真相
#include <iostream>
#include <vector>

int main() {
  // TODO: 你的实现（要求 1-4）

  std::vector<int> v;
  std::cout << "before , capacity = " << v.capacity() << ", size = " << v.size() << "\n";
  v.push_back(2);
  std::cout << "after  , capacity = " << v.capacity() << ", size = " << v.size() << "\n"
            << "\n";
  std::cout << "before , capacity = " << v.capacity() << ", size = " << v.size() << "\n";
  v.push_back(3);
  std::cout << "after  , capacity = " << v.capacity() << ", size = " << v.size() << "\n"
            << "\n";
  std::cout << "before , capacity = " << v.capacity() << ", size = " << v.size() << "\n";
  v.push_back(5);
  std::cout << "after  , capacity = " << v.capacity() << ", size = " << v.size() << "\n"
            << "\n";

  std::cout << "size : " << v.size() << "\n";
  std::cout << "v[0] : " << v[0] << "\n";

  for (auto vi : v) {
    std::cout << vi << " ";
  }
  std::cout << "\n";

  std::cout << "before , capacity = " << v.capacity() << ", size = " << v.size() << "\n";
  v.push_back(2);
  std::cout << "after  , capacity = " << v.capacity() << ", size = " << v.size() << "\n"
            << "\n";

  std::cout << "before , capacity = " << v.capacity() << ", size = " << v.size() << "\n";
  v.push_back(42);
  std::cout << "after  , capacity = " << v.capacity() << ", size = " << v.size() << "\n"
            << "\n";

  std::cout << "before , capacity = " << v.capacity() << ", size = " << v.size() << "\n";
  v.push_back(52);
  std::cout << "after  , capacity = " << v.capacity() << ", size = " << v.size() << "\n"
            << "\n";

  return 0;
}
