// practice/04-1/solutions/05_poly_total_area.cpp — 参考答案：多态求总面积
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

class Shape {
public:
  virtual double area() const { return 0.0; } // 非纯虚：给个默认实现
  virtual const char* name() const { return "shape"; }
  virtual ~Shape() = default;
};

class Circle : public Shape {
public:
  explicit Circle(double r) : r_(r) {}
  double area() const override { return kPi * r_ * r_; }
  const char* name() const override { return "circle"; }

private:
  static constexpr double kPi = 3.14159265358979323846;
  double r_;
};

class Rect : public Shape {
public:
  Rect(double w, double h) : w_(w), h_(h) {}
  double area() const override { return w_ * h_; }
  const char* name() const override { return "rect"; }

private:
  double w_, h_;
};

class Triangle : public Shape {
public:
  Triangle(double b, double h) : b_(b), h_(h) {}
  double area() const override { return b_ * h_ / 2.0; }
  const char* name() const override { return "triangle"; }

private:
  double b_, h_;
};

int main() {
  Circle c(2.0);
  Rect r(3.0, 4.0);
  Triangle t(6.0, 2.0);

  std::vector<Shape*> shapes{&c, &r, &t}; // 存指针，不切片

  double total = 0.0;
  const Shape* largest = shapes[0];
  std::cout << "=== 各图形面积 ===\n";
  for (const Shape* s : shapes) {
    double a = s->area();
    std::cout << "  " << s->name() << " area = " << a << "\n";
    total += a;
    if (a > largest->area()) {
      largest = s;
    }
  }
  std::cout << "  total area = " << total << "\n";
  std::cout << "  largest    = " << largest->name() << "\n";

  std::cout << "\n=== 答案 ===\n";
  std::cout << "  1) 去掉 virtual：total 变成 0。因为静态绑定后，\n";
  std::cout << "     循环里 s->area() 编译期就定死调 Shape::area()（默认实现 return 0），\n";
  std::cout << "     派生类各自的面积根本没被调用到，而且不会有任何报错。\n";
  std::cout << "  2) 编译器其实【不知道】该算谁的——它生成的是一条「运行期查虚表」的指令：\n";
  std::cout << "     每个含虚函数的对象里藏着一个指向虚函数表的指针（vptr），\n";
  std::cout << "     调用时按对象的真实类型从表里取函数地址。这就是动态绑定。\n";
  return 0;
}
