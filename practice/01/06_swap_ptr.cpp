// practice/01/06_swap_ptr.cpp — M1 练习6：指针版 swap（M2 的钩子）
#include <iostream>

// 用指针实现交换 | swap via pointers
// 调用时传地址：swapPtr(&x, &y)  —— 注意要取地址 &
void swapPtr(int* a, int* b) {
  // TODO: 交换 *a 和 *b 的值
  // 需要：int temp = *a;  *a = *b;  *b = temp;
  // 思考：为什么是 *a（解引用）而不是 a 本身？a 里装的是地址。
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int main() {
  int x = 3, y = 7;
  std::cout << "before: x=" << x << " y=" << y << "\n";  // 期望 3 7
  swapPtr(&x, &y);
  std::cout << "after : x=" << x << " y=" << y << "\n";  // 期望 7 3
  return 0;
}
