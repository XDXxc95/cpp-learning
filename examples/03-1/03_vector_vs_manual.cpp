// examples/03-1/03_vector_vs_manual.cpp — 动态求平均：手动 new[] vs vector
// M2 练习 3 的同款题目：vector 版不用写 delete[]，内存自动管。
#include <iostream>
#include <vector>

// 传参用 const 引用：不拷贝 + 保证只读（接 M2 的「判断树」）
double average(const std::vector<double>& v) {
  double sum = 0.0;
  for (double x : v) {
    sum += x;
  }
  return v.empty() ? 0.0 : sum / v.size();
}

int main() {
  // --- 方式一：手动 new[]/delete[]（M2 练习 3 的做法）---
  const int n = 5;
  double* raw = new double[n];
  for (int i = 0; i < n; ++i) {
    raw[i] = (i + 1) * 1.5;
  }
  double raw_sum = 0.0;
  for (int i = 0; i < n; ++i) {
    raw_sum += raw[i];
  }
  std::cout << "manual: avg = " << raw_sum / n << "\n";  // 4.5
  delete[] raw;  // 忘了它 = 内存泄漏（M2 练习 2 的 Bug A）

  // --- 方式二：vector（析构自动释放，无需 delete[]）---
  std::vector<double> v = {1.5, 3.0, 4.5, 6.0, 7.5};
  std::cout << "vector: avg = " << average(v) << "\n";   // 4.5

  // 空 vector 防御：average 里有 empty() 检查
  std::vector<double> empty;
  std::cout << "empty:  avg = " << average(empty) << "\n";  // 0

  return 0;
}
