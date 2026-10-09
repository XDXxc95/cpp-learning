// practice/04-1/solutions/07_override_final.cpp — 参考答案：override 与 final
#include <iostream>

class Base {
public:
  virtual void f() const { std::cout << "  Base::f\n"; }
  virtual void g() { std::cout << "  Base::g\n"; }
  virtual ~Base() = default;
};

class Derived : public Base {
public:
  void f() const override { std::cout << "  Derived::f\n"; } // ✅ 签名一致，真覆盖
  void g() override { std::cout << "  Derived::g\n"; }

  // 反例：签名不一致 —— 这里的 f 少了 const，签名变成 void f()
  // 如果不写 override，编译器【不会报错】，它只是变成了一个【新函数】，
  // 基类的 f() 依然存在且没被覆盖 → 多态静默失效。
  // void f() { std::cout << "  Derived::f (少了 const!)\n"; }   // ✗ 加了 override 就报错
};

// final 加在【函数】上：禁止再被覆盖
class Mid : public Base {
public:
  void f() const final { std::cout << "  Mid::f (final)\n"; }
};

// final 加在【类】上：禁止被继承
class Leaf final : public Mid {
public:
  // void f() const override;   // ✗ 编译错误：Mid::f 是 final，不能再覆盖
};

// class SubLeaf : public Leaf {};  // ✗ 编译错误：Leaf 是 final，不能被继承

int main() {
  std::cout << "=== 多态确实生效 ===\n";
  {
    Derived d;
    Base& b = d;
    b.f(); // Derived::f —— 覆盖成功
    b.g(); // Derived::g
  }

  std::cout << "\n=== final 的类仍可正常使用 ===\n";
  {
    Leaf leaf;
    Base& b = leaf;
    b.f(); // Mid::f (final)
  }

  std::cout << "\n=== 答案 ===\n";
  std::cout << "  override 防住的是【签名不一致导致多态静默失效】。\n";
  std::cout << "  具体例子：想覆盖 virtual void f() const，却写成了 void f()（漏了 const）。\n";
  std::cout << "    - 不写 override：编译通过，但这是【重载】不是【覆盖】，\n";
  std::cout << "      基类的 f() const 没被盖住 → 通过基类指针调用仍走基类版本，\n";
  std::cout << "      而且毫无提示，是极难查的一类 bug。\n";
  std::cout << "    - 写了 override：编译器直接报错，当场发现。\n";
  std::cout << "  所以规矩是：【每一个覆盖都写 override】。\n";
  return 0;
}
