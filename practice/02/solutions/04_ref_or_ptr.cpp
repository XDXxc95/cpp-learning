// practice/02/solutions/04_ref_or_ptr.cpp — M2 练习4 参考答案
// 场景 A：find 用指针（表达"找不到"）；场景 B：setMin 用引用（借用且保证有效）
#include <iostream>

// 找到返回指向元素的指针；找不到返回 nullptr
int* find(int* arr, int n, int target) {
  for (int i = 0; i < n; ++i) {
    if (arr[i] == target) {
      return &arr[i];
    }
  }
  return nullptr;
}

// 把较小的值赋给较大的（结果两数相等）
void setMin(int& a, int& b) {
  if (a < b) {
    b = a;
  } else {
    a = b;
  }
}

int main() {
  int arr[] = {3, 7, 1, 9, 4};

  int* hit = find(arr, 5, 9);
  if (hit != nullptr) {
    std::cout << "found 9: " << *hit << "\n";
  }

  int* miss = find(arr, 5, 42);
  if (miss == nullptr) {
    std::cout << "42: not found\n";
  }

  int x = 5, y = 3;
  setMin(x, y);
  std::cout << "after setMin: x=" << x << " y=" << y << "\n";

  // ① find 为什么必须用指针返回？
  //    因为可能"找不到"。指针能用 nullptr 表达"没有"，引用没有空值——
  //    引用必须绑定一个真实存在的对象，无法表示"无"。
  //    这也是 C 语言时代的惯用法：返回值本身兼作"结果/失败"信号。

  // ② setMin 为什么用引用？
  //    调用干净（setMin(x, y) 不用取地址），且编译器保证参数一定
  //    绑定了真实变量——不用像指针那样判空。只读借用时还要加 const。

  // ③ 口诀：能用引用用引用（语法干净、天然非空）；
  //         需要表达"可能没有"（nullptr）或需要换人改绑时，用指针。
  return 0;
}
