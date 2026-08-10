// practice/03/solutions/01_vector_avg.cpp — 参考答案：vector 重写动态数组求平均
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
  int n = 0;
  std::cout << "n = ";
  std::cin >> n;
  if (n <= 0) {
    std::cerr << "n <= 0\n";
    return 1;
  }

  std::vector<double> a(n);   // 自动在堆上分配 n 个 double，默认 0.0
  double sum = 0;
  for (int i = 0; i < n; i++) {
    a[i] = (i + 1) * 1.5;
    sum += a[i];
  }

  std::cout << std::fixed << std::setprecision(2);
  std::cout << "avg: " << sum / n << "\n";
  // 对比 M2 new[] 版，少了：new、delete[]、手动管长度——a 析构时自动释放
  return 0;
}
