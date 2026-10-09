// practice/04-1/solutions/04_abstract_shape.cpp — 参考答案：抽象类与纯虚函数
#include <iostream>

class Shape {
public:
  virtual double area() const = 0;      // = 0 → 纯虚函数，Shape 成为抽象类
  virtual const char* name() const = 0; // 派生类必须实现
  virtual ~Shape() = default;           // 有虚函数的基类，析构也要 virtual
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

class Square : public Shape {
public:
  explicit Square(double s) : s_(s) {}
  double area() const override { return s_ * s_; }
  const char* name() const override { return "square"; }

private:
  double s_;
};

int main() {
  Circle c(2.0);
  Square q(3.0);

  std::cout << "=== 通过 Shape* 调用各自的实现 ===\n";
  Shape* shapes[] = {&c, &q};
  double total = 0.0;
  for (Shape* s : shapes) {
    std::cout << "  " << s->name() << " area = " << s->area() << "\n";
    total += s->area();
  }
  std::cout << "  total = " << total << "\n";

  std::cout << "\n=== 答案 ===\n";
  std::cout << "  1) Shape s; 编译不过：Shape 含纯虚函数，是抽象类，不能创建对象。\n";
  std::cout << "     但 Shape* / Shape& 可以用——抽象类就是拿来当接口的。\n";
  std::cout << "  2) Square 只实现 area() 不实现 name()：\n";
  std::cout << "     Square 自己仍然是抽象类，Square q(3.0); 一样编译不过；\n";
  std::cout << "     而且编译器会明确告诉你「哪个纯虚函数还没实现」。\n";
  // Shape s;      // ✗ 编译错误：cannot declare variable 's' to be of abstract type 'Shape'
  // Square bad;   // ✗ 若 name() 没实现，这里同样编译不过
  return 0;
}
