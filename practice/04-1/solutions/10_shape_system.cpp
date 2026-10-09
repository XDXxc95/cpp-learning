// practice/04-1/solutions/10_shape_system.cpp — 参考答案：简易图形清单系统（综合）
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

// ================= 抽象基类 = 接口 =================
class Shape {
public:
  virtual double area() const = 0;
  virtual double perimeter() const = 0;
  virtual const char* name() const = 0;
  virtual ~Shape() = default; // 关键：下面要 delete Shape*，没有它派生类析构不会跑

  // Shape s;   // ✗ 抽象类不能实例化
};

class Circle : public Shape {
public:
  explicit Circle(double r) : r_(r) {}
  double area() const override { return kPi * r_ * r_; }
  double perimeter() const override { return 2 * kPi * r_; }
  const char* name() const override { return "circle"; }
  ~Circle() override { std::cout << "[dtor] Circle\n"; }

private:
  static constexpr double kPi = 3.14159265358979323846;
  double r_;
};

class Rectangle : public Shape {
public:
  Rectangle(double w, double h) : w_(w), h_(h) {}
  double area() const override { return w_ * h_; }
  double perimeter() const override { return 2 * (w_ + h_); }
  const char* name() const override { return "rect"; }
  ~Rectangle() override { std::cout << "[dtor] Rectangle\n"; }

private:
  double w_, h_;
};

class Triangle : public Shape {
public:
  Triangle(double a, double b, double c) : a_(a), b_(b), c_(c) {}
  double area() const override {
    double s = (a_ + b_ + c_) / 2.0;                      // 半周长
    return std::sqrt(s * (s - a_) * (s - b_) * (s - c_)); // 海伦公式
  }
  double perimeter() const override { return a_ + b_ + c_; }
  const char* name() const override { return "tri"; }
  ~Triangle() override { std::cout << "[dtor] Triangle\n"; }

private:
  double a_, b_, c_;
};

int main() {
  // 容器存【指针】——存值会切片
  std::vector<Shape*> shapes;
  shapes.push_back(new Circle(2.0));
  shapes.push_back(new Rectangle(3.0, 4.0));
  shapes.push_back(new Triangle(3.0, 4.0, 5.0));

  std::cout << "=== 图形清单 ===\n";
  double total = 0.0;
  const Shape* largest = nullptr;
  for (const Shape* s : shapes) {
    double a = s->area();
    std::cout << "  " << s->name() << "\tarea=" << a << "\tperimeter=" << s->perimeter() << "\n";
    total += a;
    if (largest == nullptr || a > largest->area()) {
      largest = s;
    }
  }
  std::cout << "=== 汇总 ===\n";
  std::cout << "total area = " << total << "\n";
  std::cout << "largest = " << largest->name() << "\n";

  // 统一释放：因为 ~Shape() 是 virtual，每个派生类析构都会被执行
  std::cout << "=== 释放 ===\n";
  for (Shape* s : shapes) {
    delete s;
  }
  shapes.clear();

  std::cout << "\n=== 答案 ===\n";
  std::cout << "  1) ~Shape() 必须 virtual：否则 delete s（静态类型 Shape*）只会调 ~Shape()，\n";
  std::cout << "     三个派生类的析构全被跳过，最后三行 [dtor] 一行都不会出现。\n";
  std::cout << "     虽然这个例子里派生类没有持有堆资源，但那是运气好；\n";
  std::cout << "     一旦有 new/malloc 出来的成员，就是实打实的泄漏。\n";
  std::cout << "  2) 为什么用 Shape* 而不是 Shape：\n";
  std::cout << "     vector<Shape> push_back 一个 Circle 会发生【对象切片】——\n";
  std::cout << "     只复制基类子对象，半径 r_ 和 vptr 都丢了，\n";
  std::cout << "     之后调 area() 只会得到纯虚/默认版本，多态彻底失效。\n";
  std::cout << "  3) 海伦公式：s=(a+b+c)/2，area=sqrt(s(s-a)(s-b)(s-c))。\n";
  std::cout << "     三角形 3/4/5 → s=6，area=sqrt(6*3*2*1)=sqrt(36)=6，周长 12。\n";
  return 0;
}
