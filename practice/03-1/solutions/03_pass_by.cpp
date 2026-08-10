// practice/03-1/solutions/03_pass_by.cpp — M3-1 练习3+4 参考答案
#include <iostream>
#include <vector>

// const 引用版：不拷贝（别名），加 const 保证不改
int sum(const std::vector<int>& v) {
  int total = 0;
  for (int x : v) {
    total += x;
  }
  return total;
}

// 按值版：整体拷贝一份 v（大容器时很贵，演示用）
int sumByValue(std::vector<int> v) {
  int total = 0;
  for (int x : v) {
    total += x;
  }
  return total;
}

int main() {
  std::vector<int> data = {1, 2, 3, 4, 5};
  std::cout << "sum(const&)      = " << sum(data) << "\n";        // 15
  std::cout << "sumByValue(copy) = " << sumByValue(data) << "\n"; // 15

  // 注释回答：
  //   ① 为什么只读传参用 const& 而不是按值？
  //      按值会把整个 vector 拷贝一份（n 个元素复制到栈上），
  //      const& 只是给原 vector 起个别名，零拷贝。
  //      加 const 是「承诺不改」，编译器替你把关。
  //   ② M2 练习3 为什么要 delete[]，换 vector 就不用写了？
  //      vector 的析构函数会自动释放自己的内存，离开作用域自动执行，
  //      「谁 new 谁 delete」的配对被容器接管，想漏都漏不了。
  //   ③ size() 返回 size_t（无符号）意味着什么？
  //      和 int 比较会触发 -Wsign-compare（无符号/有符号混比），
  //      且 size_t 做减法可能下溢（size()==0 时 -1 变成巨大正数）。
  //      循环下标就用 size_t，或用 range-for。
  //   ④ 什么场景刻意用 at() 而不是 []？
  //      下标来自外部输入 / 计算得出、不确定会不会越界 → at()（越界抛异常，好排查）；
  //      确认不越界的常规遍历 → []（更快）。

  return 0;
}
