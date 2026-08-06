// practice/01/05_find_bugs.cpp — M1 练习5：找 Bug（off-by-one + 换行位置）
// 目标：打印 1 到 10 的平方，每行 5 个。
// 期望输出：
//   1 4 9 16 25
//   36 49 64 81 100
// ⚠️ 下面这段代码有 2 个 bug，找到并修复（用 gdb 单步也行）。
#include <iostream>

int main() {
  for (int i = 1; i <= 10; ++i) { 
    std::cout << i * i << " ";
    if (i % 5 == 0)
      std::cout << "\n";
  }
  return 0;
}
