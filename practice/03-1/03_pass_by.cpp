// practice/03-1/03_pass_by.cpp — M3-1 练习3+4：const& 传参 + 思考题
// 要求：
//   1. 实现 sum(const vector<int>&) 和 sumByValue(vector<int>) 两个版本
//   2. main 里各调一次，验证结果相同
//   3. 注释里回答：为什么只读传参用 const& 而不是按值？
#include <iostream>
#include <vector>

// TODO: sum —— const 引用版
// TODO: sumByValue —— 按值版

int main() {
  // TODO: 造 vector，分别调两个函数，打印结果

  // 注释回答：
  //   ① 为什么只读传参用 const& 而不是按值？
  //   ② M2 练习3 为什么要 delete[]，换 vector 就不用写了？
  //   ③ size() 返回 size_t 意味着什么？为什么和 int i 比会警告？
  //   ④ 什么场景刻意用 at() 而不是 []？

  return 0;
}
