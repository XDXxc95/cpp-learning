// practice/03/03_vector_avg.cpp — M3 练习3：用 vector 重写「动态数组求平均」
// 要求：
//   1. 输入 n，std::vector<double> a(n) 造出 n 个元素
//   2. 填值 a[i] = (i + 1) * 1.5
//   3. 求平均输出，保留 2 位小数（std::fixed + std::setprecision(2)）
//   4. 防御 n <= 0：报错退出（vector 接受 0 长度，但业务上 n<=0 是错的）
// 注释里对比：比 M2 的 new[]/delete[] 版少了哪些手动操作？ 初始化和置空
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
  int n = 0;
  std::cout << "n = ";
  std::cin >> n;

  // TODO: 你的实现（要求 1-4）
  if (n <= 0) {
    std::cerr << "n must be positive!\n";
    return 1;
  }

  std::vector<double> a(n);
  double sum = 0.0;
  for (size_t i = 0; i < a.size(); i++) {
    a[i] = (i + 1) * 1.5;
    sum += a[i];
  }

  std::cout << std::fixed << std::setprecision(2);
  std::cout << "avg : " << sum / n << "\n";

  return 0;
}
