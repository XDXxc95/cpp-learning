// practice/02/solutions/03_dynamic_avg.cpp — M2 练习3 参考答案
// 动态数组求平均：new[] 填值 → 求平均 → delete[] 收尾
#include <iomanip>
#include <iostream>

int main() {
  int n = 0;
  std::cout << "n = ";
  std::cin >> n;

  // 防御：n <= 0 时 new 长度非法，直接报错退出
  if (n <= 0) {
    std::cerr << "n must be positive\n";
    return 1;
  }

  // new[] 分配（运行时大小，栈数组做不到）
  double* arr = new double[n];
  for (int i = 0; i < n; ++i) {
    arr[i] = (i + 1) * 1.5;
  }

  double sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += arr[i];
  }

  std::cout << std::fixed << std::setprecision(2);
  std::cout << "avg = " << sum / n << "\n";

  // new[] 配 delete[]，删完置空
  delete[] arr;
  arr = nullptr;

  return 0;
}
