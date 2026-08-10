// examples/03/01_vector_basics.cpp — vector 基本操作：动态数组，替你管内存
// Vector basics: a dynamic array that manages its own memory
// 对比 M2 的手动 new[]/delete[]：vector 自动增长、自动释放（RAII）
#include <iostream>
#include <vector>

int main() {
  // 构造：空 vector
  std::vector<int> v;
  std::cout << "empty: size=" << v.size() << " capacity=" << v.capacity() << "\n";

  // 尾部添加 push_back：空间不够时自动扩容（capacity 通常翻倍）
  for (int i = 0; i < 8; i++) {
    v.push_back(i * i);
    std::cout << "push " << v.back() << ": size=" << v.size()
              << " capacity=" << v.capacity() << "\n";
  }

  // 随机访问：operator[] 快但无越界检查；.at() 有越界检查（越界会抛异常）
  std::cout << "v[3]=" << v[3] << " v.at(3)=" << v.at(3) << "\n";

  // 三种遍历
  std::cout << "index : ";
  for (size_t i = 0; i < v.size(); i++) std::cout << v[i] << " ";
  std::cout << "\nrange : ";
  for (int x : v) std::cout << x << " ";   // range-for：读副本
  std::cout << "\niter  : ";
  for (auto it = v.begin(); it != v.end(); ++it) std::cout << *it << " ";  // 迭代器
  std::cout << "\n";

  // 修改元素：range-for 加引用 &，改的才是原数组
  for (int& x : v) x += 1;
  std::cout << "after +1 : front=" << v.front() << " back=" << v.back() << "\n";

  // 删除 / 清空 / 判空
  v.pop_back();
  std::cout << "after pop_back : size=" << v.size() << "\n";
  v.clear();
  std::cout << "after clear    : size=" << v.size() << " empty=" << v.empty() << "\n";

  // 指定大小的构造：vector<double> a(5) —— 正是 M2 练习 3 那个 new double[n] 的平替
  std::vector<double> a(5, 0.0);   // 5 个 0.0
  double sum = 0;
  for (size_t i = 0; i < a.size(); i++) {
    a[i] = (i + 1) * 1.5;
    sum += a[i];
  }
  std::cout << "a: " << a[0] << ".." << a.back() << " avg=" << sum / a.size() << "\n";
  // 不需要 delete[]：a 离开 main 时自动析构释放内存

  return 0;
}
