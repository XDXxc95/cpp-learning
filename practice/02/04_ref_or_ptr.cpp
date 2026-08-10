// practice/02/04_ref_or_ptr.cpp — M2 练习4：引用还是指针？
// 场景 A find：在 int 数组里找 target，找到返回"指向该元素的指针"，找不到返回 nullptr
//             （"找不到" = nullptr —— 指针的独门本事，引用做不到）
// 场景 B setMin(int& a, int& b)：把较小的值赋给较大的（结果两数相等）
#include <iostream>

int* find(int* arr, int n, int target) {
  // TODO: 遍历 arr[0..n-1]，找到返回 &arr[i]，找不到返回 nullptr
  for (int i = 0; i < n; i++) {
    if (arr[i] == target) {
      return &arr[i];
    }
  }
  return nullptr;
}

void setMin(int& a, int& b) {
  // TODO: a 小 → b = a；否则 a = b
  if (a < b) {
    b = a;
  } else {
    a = b;
  }
}

int main() {
  // TODO: 小测试
  //   - 造一个数组调用 find：能找到的（打印 *hit）和找不到的（打印 "not found"）
  int a[] = {7, 4, 3, 6, 2};
  int* hit = find(a, sizeof(a) / sizeof(int), 3);
  if (hit) {
    std::cout << *hit << "\n";
  }
  int* miss = find(a, sizeof(a) / sizeof(int), 10);
  if (!miss) {
    std::cout << "not found\n";
  }

  //   - 调 setMin，打印结果（例如 5 和 3 → 3 3）
  int aa = 5;
  int bb = 3;
  std::cout << aa << "," << bb << " -> ";
  setMin(aa, bb);
  std::cout << aa << "," << bb << "\n";

  // 注释里回答：
  //   ① find 为什么必须用指针返回？引用行不行，差在哪？ 需要判断是否存在
  //   ② setMin 用引用比用指针好在哪？  函数内变量使用简单，形参约束入参一定存在，
  //   ③ 你判断"用引用还是指针"的口诀是什么？ 是否需要判断是否存在

  return 0;
}
