// examples/02/01_ref_vs_ptr.cpp — 引用 vs 指针：同一件事的两种写法
// References vs pointers: two ways to write the same thing
#include <iostream>

// 引用版：a、b 是实参的别名 | a, b are aliases of the arguments
void swapByRef(int& a, int& b) {
  int tmp = a;
  a = b;
  b = tmp;
}

// 指针版：a、b 里装的是地址 | a, b store addresses
void swapByPtr(int* a, int* b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int main() {
  // 调用时差别：引用版直接传变量，指针版要取地址 &
  int x = 3, y = 7;
  swapByRef(x, y);
  std::cout << "after swapByRef : x=" << x << " y=" << y << "\n";
  swapByPtr(&x, &y);
  std::cout << "after swapByPtr : x=" << x << " y=" << y << "\n";

  // --- 引用的关键行为：绑定后不可换人，r 就是 a 的别名 ---
  int a = 1, b = 2;
  int& r = a;                        // r 绑定 a
  r = 99;                            // 改 r 就是改 a
  std::cout << "a = " << a << "  (r 赋值 = 改 a)\n";

  // 看似"改绑"，其实是把 b 的值复制进 a（引用没有 rebind）
  r = b;
  std::cout << "a = " << a << "  b = " << b
            << "  (r = b 只是复制值，r 仍是 a 的别名)\n";

  // --- 指针可以改绑 ---
  int* p = &a;
  p = &b;                            // p 现在指向 b
  *p = 42;                           // 改的是 b
  std::cout << "b = " << b << "  (p 改绑后解引用改的是 b)\n";

  return 0;
}
