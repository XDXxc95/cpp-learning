// practice/03-1/solutions/02_vector_stats.cpp — M3-1 练习2 参考答案
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
  int n = 0;
  std::cout << "n = ";
  std::cin >> n;
  if (n <= 0) {
    std::cerr << "n must be positive\n";  // 防御：报错 + 非 0 退出
    return 1;
  }

  std::vector<int> v;
  v.reserve(n);   // 预留容量：已知要放 n 个，避免反复扩容（性能优化）
  for (int i = 0; i < n; ++i) {
    int x = 0;
    std::cin >> x;
    v.push_back(x);
  }

  // 统计：v 至少有 1 个元素（n>0 已保证）
  int max_val = v[0];
  int min_val = v[0];
  long long sum = 0;   // long long：防 n 个 int 相加溢出
  for (int x : v) {
    if (x > max_val) {
      max_val = x;
    }
    if (x < min_val) {
      min_val = x;
    }
    sum += x;
  }

  std::cout << std::fixed << std::setprecision(2);
  std::cout << "max = " << max_val << "\n";
  std::cout << "min = " << min_val << "\n";
  std::cout << "avg = " << static_cast<double>(sum) / v.size() << "\n";

  return 0;
}
