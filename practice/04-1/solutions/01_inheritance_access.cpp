// practice/04-1/solutions/01_inheritance_access.cpp — 参考答案：继承与访问控制
#include <iostream>
#include <string>

class Person {
public:
  Person(const std::string& n, int a) : name_(n), age_(a) {}

  void greet() const { std::cout << "Hi, I'm " << name_ << "\n"; }

protected:
  std::string name_; // protected：派生类内部可以访问，外界不行

private:
  int age_; // private：连派生类也访问不到
};

class Student : public Person {
public:
  Student(const std::string& n, int a) : Person(n, a) {}

  void study() const {
    std::cout << name_ << " is studying\n"; // ✅ name_ 是 protected，派生类内部能读
    // std::cout << age_;                   // ✗ 编译错误：age_ 是 private，派生类也读不到
  }
};

int main() {
  std::cout << "=== 1. 继承来的 public 成员直接用 ===\n";
  {
    Student s("Alice", 20);
    s.greet(); // 继承自 Person
    s.study(); // Student 自己的
    // s.name_ = "Bob";   // ✗ 编译错误：protected 只对派生类【内部】开，main 里访问不到
    // s.age_ = 21;       // ✗ 编译错误：private 更是哪里都碰不到
    std::cout << "  (上面两行注释掉的赋值都编译不过)\n";
  }

  std::cout << "\n=== 2. 答案 ===\n";
  std::cout << "  Student::study() 里：name_ 能读（protected，派生类内部可见），\n";
  std::cout << "                       age_  不能读（private，连派生类也看不到）。\n";
  std::cout << "  main 里：两者都读不到 —— protected 只对【派生类内部】开放，\n";
  std::cout << "            private 只对【本类内部】开放，继承方式也救不了它。\n";
  return 0;
}
