// practice/02/solutions/02_find_bugs_fixed.cpp — M2 练习2 修复版
// 三个 bug 的修法：
//   A 返回栈数组 → 改成 new[]，堆上活到 delete；调用方负责 delete[]
//   B 泄漏       → delete b
//   C 双重释放   → 只删一次 + 删完置空
#include <iostream>

// 修复 A：堆上分配，调用方负责释放（谁 new 谁 delete）
double* makeScores(int n) {
  double* s = new double[n];
  for (int i = 0; i < n; ++i) {
    s[i] = (i + 1) * 1.0;
  }
  return s;
}

int main() {
  // A 的配套修复：收尾时 delete[] a（new[] 配 delete[]）
  double* a = makeScores(5);
  std::cout << a[0] << "\n";
  delete[] a;
  a = nullptr;

  // 修复 B：new 配 delete
  int* b = new int(42);
  std::cout << *b << "\n";
  delete b;
  b = nullptr;

  // 修复 C：只删一次，删完置空
  int* c = new int(7);
  std::cout << *c << "\n";
  delete c;
  c = nullptr;

  return 0;
}
