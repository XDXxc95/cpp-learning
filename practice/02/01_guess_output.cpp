// practice/02/01_guess_output.cpp — M2 练习1：预测输出
// 规则：先读代码，在每段下面的注释里写预测输出 + 一句话理由，再编译运行对照。
// 关注：谁在改谁？
#include <iostream>
#include <utility>  // std::swap

int main() {
  // ① 三个名字指同一个位置
  int x = 5;
  int& r = x;
  int* p = &x;
  x = 10;
  r = 20;
  *p = 30;
  std::cout << x << " " << r << " " << *p << "\n";
  // 预测：______30 30 30
  // 理由：______x是int，r是引用，p是指向x的指针， *p = 30 ，x也会修改，r就是x。

  // ② 指针改绑
  int a = 1, b = 2;
  int* p2 = &a;
  p2 = &b;
  *p2 += 10;
  std::cout << a << " " << b << "\n";
  // 预测：______1 12
  // 理由：______p2初始化 是 a的地址，后面将 p2 改为b的地址，之后对p2指向的值进行 +10

  // ③ 引用与指针混用
  int c = 7;
  int& ref = c;
  int* pc = &c;
  *pc = 8;
  ref = 9;
  std::cout << c << "\n";
  // 预测：______9
  // 理由：______最后是c的引用 ref修改了数值，就是最终结果

  // ④ std::swap(px, py) 交换的是两个指针变量本身，不是它们指向的值
  int x2 = 3, y2 = 4;
  int* px = &x2;
  int* py = &y2;
  std::swap(px, py);
  *px = 100;
  *py = 200;
  std::cout << x2 << " " << y2 << "\n";
  // 预测：______200 100
  // 理由：______交换了两个指针的指向，px指向y2 , py 指向 x2

  return 0;
}
