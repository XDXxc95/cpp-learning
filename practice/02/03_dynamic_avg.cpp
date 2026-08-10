// practice/02/03_dynamic_avg.cpp — M2 练习3：动态数组求平均
// 要求：
//   1. 输入 n，用 new[] 分配 double 数组（运行时才知道大小 → 只能堆）
//   2. 填值：第 i 个元素 = (i + 1) * 1.5
//   3. 求平均输出，保留 2 位小数（<iomanip>: std::fixed + std::setprecision(2)）
//   4. delete[] 完整收尾（一个 new 恰好一个 delete）
//   5. 防御：n <= 0 时报错退出
#include <iomanip>
#include <iostream>

int main() {
  int n = 0;
  std::cout << "n = ";
  std::cin >> n;

  if (n <= 0) {
    std::cerr << "n <= 0 \n";
    return 1;
  }

  double* arr = new double[n];
  double sum = 0;
  for (int i = 0; i < n; i++) {
    arr[i] = (i + 1) * 1.5;
    sum += arr[i];
  }

  std::cout << std::fixed << std::setprecision(2);
  std::cout << "avg: " << sum / n;

  delete[] arr;
  arr = nullptr;

  return 0;
}
