// practice/02/03_dynamic_avg.cpp — M2 练习3：动态数组求平均
// 要求：
//   1. 输入 n，用 new[] 分配 double 数组（运行时才知道大小 → 只能堆）
//   2. 填值：第 i 个元素 = (i + 1) * 1.5
//   3. 求平均输出，保留 2 位小数（<iomanip>: std::fixed +
//   std::setprecision(2)）
//   4. delete[] 完整收尾（一个 new 恰好一个 delete）
//   5. 防御：n <= 0 时报错退出
#include <iomanip>
#include <iostream>
int main() {
  int n = 0;
  std::cout << "n = ";
  std::cin >> n;

  // TODO: 你的实现（要求 1-5）
  if (n <= 0) {
    std::cerr << "n must be positive\n";
    return 1;
  }

  double *s = new double[n];
  double sum = 0.0;
  for (int i = 0; i < n; i++) {
    s[i] = (i + 1) * 1.5;
    sum += s[i];
  }

  std::cout << std::fixed << std::setprecision(2);
  std::cout << "avg = " << sum / n << "\n";


  delete[] s;
  s = nullptr;
  return 0;
}
