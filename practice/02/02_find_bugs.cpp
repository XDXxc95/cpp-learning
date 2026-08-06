// practice/02/02_find_bugs.cpp — M2 练习2：找内存 bug
// 这段代码有 3 个内存错误：内存泄漏 / 双重释放 / 返回栈数组悬垂。
// 找到并修复。可用 gdb（tools/gdb.sh）观察地址与生命周期。
#include <iostream>

// Bug A：返回了栈数组的地址 —— 函数返回后 s 就销毁了
double* makeScores(int n) {
  double s[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
  return s;
}

int main() {
  double* a = makeScores(5);   // 悬垂指针
  std::cout << a[0] << "\n";   // 读已销毁的栈内存（可能不崩——这才是最危险的）

  int* b = new int(42);
  std::cout << *b << "\n";
  // Bug B：b 泄漏了

  int* c = new int(7);
  std::cout << *c << "\n";
  delete c;
  delete c;   // Bug C：双重释放

  return 0;
}
