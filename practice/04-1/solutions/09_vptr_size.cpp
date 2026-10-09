// practice/04-1/solutions/09_vptr_size.cpp — 参考答案：虚函数的代价（对象大小）
#include <cstddef>
#include <iostream>

// 两个 int，没有虚函数
struct Plain {
  int a;
  int b;
};

// 同样两个 int，但多了一个虚函数
struct Poly {
  int a;
  int b;
  virtual void f() const {}
  virtual ~Poly() = default;
};

int main() {
  std::cout << "=== sizeof 对比（64 位） ===\n";
  std::cout << "  sizeof(Plain)  = " << sizeof(Plain) << "\n";
  std::cout << "  sizeof(Poly)   = " << sizeof(Poly) << "\n";
  std::cout << "  sizeof(int*)   = " << sizeof(int*) << "\n";
  std::cout << "  差值           = " << sizeof(Poly) - sizeof(Plain) << "\n";

  std::cout << "\n=== 答案 ===\n";
  std::cout << "  1) 差一个指针大小（64 位上 8 字节）。\n";
  std::cout << "     8 字节（2 个 int）+ 8 字节（vptr）= 16 字节。\n";
  std::cout << "  2) 那个差值就是 vptr（virtual table pointer，虚表指针）。\n";
  std::cout << "     只要类里有【至少一个】虚函数，编译器就给它配一张虚函数表\n";
  std::cout << "     （每个类一张，所有对象共享），并在【每个对象】里塞一个指针\n";
  std::cout << "     指向这张表。调用虚函数时就是通过 vptr 查表找地址。\n";
  std::cout << "     代价 = 每个对象 +1 指针 + 每次调用一次间接跳转（还挡优化）。\n";
  std::cout << "  3) 所以【不该】给下面这些加 virtual：\n";
  std::cout << "     - 不需要被继承、不需要多态的类（比如纯数据结构 / 简单的 struct）；\n";
  std::cout << "     - 性能敏感、且被大量实例化的小对象；\n";
  std::cout << "     - 需要保持「平凡类型」（trivially copyable）以便 memcpy / 共享内存\n";
  std::cout << "       的类 —— 加了虚函数就不再是平凡类型了。\n";
  return 0;
}
