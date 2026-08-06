// examples/02/03_new_delete.cpp — new/delete：手动管理堆内存
// Manual heap memory management
// 规矩：new 配 delete，new[] 配 delete[]，谁 new 谁 delete
#include <iostream>

struct Point {
  double x, y;
  Point(double x_, double y_) : x(x_), y(y_) {
    std::cout << "  Point(" << x << ", " << y << ") constructed\n";
  }
  ~Point() { std::cout << "  Point(" << x << ", " << y << ") destroyed\n"; }
};

int main() {
  // 1) 单个对象：new 分配 + 初始化，delete 释放
  int* p = new int(42);
  std::cout << "*p = " << *p << "\n";
  *p = 7;
  std::cout << "*p = " << *p << "\n";
  delete p;            // 一个 new 配一个 delete
  p = nullptr;         // 好习惯：删完置空，避免悬垂

  // 2) 数组：new[] 必须配 delete[]
  //    大小在运行时才知道 —— 标准 C++ 的栈数组做不到（无 VLA）
  int n = 3;
  int* arr = new int[n];
  for (int i = 0; i < n; ++i) {
    arr[i] = i * i;
  }
  for (int i = 0; i < n; ++i) {
    std::cout << "arr[" << i << "] = " << arr[i] << "\n";
  }
  delete[] arr;        // 是 delete[]，不是 delete

  // 3) 类对象：new 自动调构造函数，delete 自动调析构函数
  Point* pt = new Point(1.5, 2.5);
  std::cout << "  pt->x = " << pt->x << "\n";
  delete pt;

  return 0;
}
