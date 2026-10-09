// practice/04-1/solutions/02_ctor_dtor_order.cpp — 参考答案：构造 / 析构顺序
#include <iostream>

class A {
public:
  A() { std::cout << "  A ctor\n"; }
  virtual ~A() { std::cout << "  A dtor\n"; }
};

class B : public A {
public:
  B() { std::cout << "  B ctor\n"; }
  ~B() override { std::cout << "  B dtor\n"; }
};

class C : public B {
public:
  C() { std::cout << "  C ctor\n"; }
  ~C() override { std::cout << "  C dtor\n"; }
};

int main() {
  std::cout << "=== { C c; } 作用域开始 ===\n";
  {
    C c;
    std::cout << "  ... c 在作用域内 ...\n";
  }
  std::cout << "=== 作用域结束 ===\n";

  std::cout << "\n=== 答案 ===\n";
  std::cout << "  构造：A -> B -> C（基类先构造，派生类后构造）\n";
  std::cout << "  析构：C -> B -> A（派生类先析构，基类后析构）\n";
  std::cout << "\n  为什么逆序：派生类的构造函数体执行时，它已经用到了基类部分，\n";
  std::cout << "  所以基类必须先建好；析构同理——拆的时候得先把【依赖别人的那层】拆掉，\n";
  std::cout << "  才能安全地拆掉被依赖的基类。像剥洋葱：从里到外建，从外到里拆。\n";
  return 0;
}
