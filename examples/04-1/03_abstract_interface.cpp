// examples/04-1/03_abstract_interface.cpp — 抽象类接口 + 虚析构（泄漏对比）
// Pure virtual / abstract class, and virtual destructor vs non-virtual (leak)
#include <iostream>
#include <string>
#include <vector>

// ================= 第 1 部分：非虚析构的坑 =================
class BadBase {
public:
  BadBase() { std::cout << "    [bad] BadBase ctor\n"; }
  ~BadBase() { std::cout << "    [bad] ~BadBase dtor\n"; } // ⚠️ 非虚析构

  virtual void hello() const { std::cout << "    [bad] hello from BadBase\n"; }
};

class BadDerived : public BadBase {
public:
  BadDerived() : buf_(new int[100]) { std::cout << "    [bad] BadDerived ctor (new int[100])\n"; }
  // 析构不写 override —— 基类析构非虚，这里只是一个普通析构函数
  ~BadDerived() {
    delete[] buf_;
    std::cout << "    [bad] ~BadDerived dtor (delete[] buf_)\n";
  }

  void hello() const override { std::cout << "    [bad] hello from BadDerived\n"; }

private:
  int* buf_;
};

// ================= 第 2 部分：虚析构（同一份代码，修好） =================
class GoodBase {
public:
  GoodBase() { std::cout << "    [good] GoodBase ctor\n"; }
  virtual ~GoodBase() { std::cout << "    [good] ~GoodBase dtor\n"; } // ✅ 虚析构

  virtual void hello() const { std::cout << "    [good] hello from GoodBase\n"; }
};

class GoodDerived : public GoodBase {
public:
  GoodDerived() : buf_(new int[100]) {
    std::cout << "    [good] GoodDerived ctor (new int[100])\n";
  }
  ~GoodDerived() override {
    delete[] buf_;
    std::cout << "    [good] ~GoodDerived dtor (delete[] buf_)\n";
  }

  void hello() const override { std::cout << "    [good] hello from GoodDerived\n"; }

private:
  int* buf_;
};

// ================= 第 3 部分：抽象类 = 接口 =================
class Shape {
public:
  virtual double area() const = 0;      // 纯虚函数：只声明，不实现
  virtual std::string name() const = 0; // 派生类必须实现
  virtual ~Shape() = default;           // 有虚函数的基类 → 析构要 virtual

  // Shape s;   // ✗ 想取消注释试试：抽象类不能创建对象
};

class Circle : public Shape {
public:
  explicit Circle(double r) : r_(r) {}
  double area() const override { return kPi * r_ * r_; }
  std::string name() const override { return "circle r=" + std::to_string(r_); }

private:
  static constexpr double kPi = 3.14159265358979323846;
  double r_;
};

class Rectangle : public Shape {
public:
  Rectangle(double w, double h) : w_(w), h_(h) {}
  double area() const override { return w_ * h_; }
  std::string name() const override {
    return "rect " + std::to_string(w_) + "x" + std::to_string(h_);
  }

private:
  double w_, h_;
};

int main() {
  std::cout << "=== 1. 非虚析构：delete 基类指针 → 派生类析构【不执行】 ===\n";
  {
    BadBase* p = new BadDerived;
    p->hello(); // 虚函数：多态本身是正常的
    std::cout << "    delete p ...\n";
    // 本示例【故意】演示错误写法。GCC/Clang 在这里会给出
    //   warning: deleting object of polymorphic class type 'BadBase'
    //            which has non-virtual destructor might cause undefined behavior
    //            [-Wdelete-non-virtual-dtor]
    // 这条警告由 -Wall 开启，是救命的——真实项目里要把基类析构改成 virtual，
    // 而不是像下面这样把警告压掉。这里压掉只是为了把「运行时到底发生了什么」演完。
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdelete-non-virtual-dtor"
    delete p; // ⚠️ 运行时只跑 ~BadBase，buf_ 泄漏
#pragma GCC diagnostic pop
  }
  std::cout << "    ↑ 上面没有 ~BadDerived —— new int[100] 泄漏了\n";
  std::cout << "    (注意：编译器在编译期就警告过这条 delete，见上面注释)\n";

  std::cout << "\n=== 2. 虚析构：同样的代码，派生类析构正常执行 ===\n";
  {
    GoodBase* p = new GoodDerived;
    p->hello();
    std::cout << "    delete p ...\n";
    delete p; // ✅ 先 ~GoodDerived（释放 buf_）再 ~GoodBase
  }
  std::cout << "    ↑ 上面两行析构都跑了，没有泄漏\n";

  std::cout << "\n=== 3. 抽象类当接口：只知道 Shape*，也能算各自面积 ===\n";
  {
    Circle c(2.0);
    Rectangle r(3.0, 4.0);

    std::vector<Shape*> shapes{&c, &r}; // 存指针 → 不切片（见 04 示例）
    double total = 0.0;
    for (const Shape* s : shapes) {
      std::cout << "    " << s->name() << "  ->  area = " << s->area() << "\n";
      total += s->area();
    }
    std::cout << "    total area = " << total << "\n";
    std::cout << "    (调用点只写了 s->area()，具体算谁的由对象真实类型决定)\n";
  }

  std::cout << "\n=== 4. 结论 ===\n";
  std::cout << "  基类可能有虚函数 → 析构就写 virtual ~Base() = default;\n";
  std::cout << "  抽象类（含纯虚函数）不能实例化，只能当接口用。\n";
  return 0;
}
