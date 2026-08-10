// practice/02/04_ref_or_ptr.cpp — M2 练习4：引用还是指针？
// 场景 A find：在 int 数组里找 target，找到返回"指向该元素的指针"，找不到返回
// nullptr
//             （"找不到" = nullptr —— 指针的独门本事，引用做不到）
// 场景 B setMin(int& a, int& b)：把较小的值赋给较大的（结果两数相等）
#include <iostream>

int *find(int *arr, int n, int target) {
  // TODO: 遍历 arr[0..n-1]，找到返回 &arr[i]，找不到返回 nullptr
  for (int i = 0; i < n; i++) {
    if (arr[i] == target) {
      return &arr[i];
    }
  }
  return nullptr; // 占位
}

void setMin(int &a, int &b) {
  // TODO: a 小 → b = a；否则 a = b
  // a < b ? b = a : a = b;
  if (a < b) {
    b = a;
  } else {
    a = b;
  }
}

int main() {
  // TODO: 小测试
  //   - 造一个数组调用 find：能找到的（打印 *hit）和找不到的（打印 "not
  //   found"）
  int s[] = {0, 1, 2, 5, 4, 8};

  int *hit = find(s, sizeof(s) / sizeof(int), 4);
  if (hit) {
    std::cout << "find : " << *hit << "\n";
  } else {
    std::cout << "not find\n";
  }
  int *miss = find(s, sizeof(s) / sizeof(int), 100);
  if (miss) {
    std::cout << "find : " << *miss << "\n";
  } else {
    std::cout << "not find\n";
  }
  //   - 调 setMin，打印结果（例如 5 和 3 → 3 3）
  int a = 5;
  int b = 3;
  setMin(a, b);
  std::cout << a << " " << b << "\n";   // 期望 3 3
  // 注释里回答：
  //   ① find
  //   为什么必须用指针返回？引用行不行，差在哪？指针直接返回地址，能够判断是否为空，引用无法判断是否为空。
  //   ② setMin 用引用比用指针好在哪？   函数内部使用简洁，形参形式清晰。避免未判nullptr 
  //   ③ 你判断"用引用还是指针"的口诀是什么？ 是否需要判断空。

  return 0;
}
