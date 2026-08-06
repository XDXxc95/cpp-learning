// practice/02/02_find_bugs.cpp — M2 练习2：找内存 bug
// 练习：找 3 个内存错误（内存泄漏 / 双重释放 / 返回栈数组悬垂）并修复 —— 已全部修复 ✅
#include <iostream>

// Bug A 已修复：改为堆分配 new[]，避免返回栈数组悬垂
double* makeScores(int n) {
  double* s = new double[n];
  for (int i = 0; i < n; ++i) {
    s[i] = (i + 1) * 1.0;
  }
  return s;
}

int main() {
  double* a = makeScores(5);   // 堆指针（原为悬垂，已修复）
  std::cout << a[0] << "\n";   // 正常读取堆内存
  delete[] a;
  a = nullptr;

  int* b = new int(42);
  std::cout << *b << "\n";
  // Bug B 已修复：delete b 并置空
  if (b)
  {
    delete b;
    b = nullptr;
  }


  int* c = new int(7);
  std::cout << *c << "\n";
  delete c;
  c = nullptr;   // Bug C 已修复：只 delete 一次

  return 0;
}
