// examples/04-1/01_inheritance_basic.cpp — 继承基础：访问控制与构造/析构顺序
// Inheritance basics: access control and construction/destruction order
#include <iostream>
#include <string>

// 基类 base class
class Animal {
public:
  explicit Animal(const std::string& n) : name_(n) {
    std::cout << "  [ctor] Animal(" << name_ << ")\n";
  }
  virtual ~Animal() { // 有虚函数的基类，析构也写 virtual（理由见 03 示例）
    std::cout << "  [dtor] ~Animal(" << name_ << ")\n";
  }

  void breathe() const { std::cout << "  " << name_ << " breathes\n"; }

protected:
  std::string name_; // protected：派生类内部可以访问，外界不行

private:
  int id_ = 0; // private：连派生类也访问不到
};

// 派生类 derived class：public 继承（最常用，表达 is-a）
class Dog : public Animal {
public:
  // 派生类构造函数必须在【初始化列表】里调用基类构造函数
  Dog(const std::string& n, const std::string& breed) : Animal(n), breed_(breed) {
    std::cout << "  [ctor] Dog(" << name_ << ", " << breed_ << ")\n"; // name_ 是 protected，能读
  }
  ~Dog() override { std::cout << "  [dtor] ~Dog(" << name_ << ")\n"; }

  void fetch() const { std::cout << "  " << name_ << " (" << breed_ << ") fetches\n"; }

protected:
  std::string breed_;
};

// 三层继承链：Animal -> Dog -> Puppy
class Puppy final : public Dog {
public:
  explicit Puppy(const std::string& n) : Dog(n, "mixed") {
    std::cout << "  [ctor] Puppy(" << name_ << ")\n";
  }
  ~Puppy() override { std::cout << "  [dtor] ~Puppy(" << name_ << ")\n"; }
};

int main() {
  std::cout << "=== 1. 继承来的成员直接用 ===\n";
  {
    Dog d("Rex", "corgi");
    d.breathe(); // 继承自 Animal
    d.fetch();   // Dog 自己的

    // 下面两行都【编译不过】，取消注释可以自己验证：
    // d.id_ = 1;    // ✗ Animal 的 private 成员，派生类访问不到
    // d.name_ = "X"; // ✗ protected 成员，外界（main 里）访问不到
    std::cout << "  (d.breathe() 用的是继承来的 public 函数，"
                 "protected/private 成员都被挡在外面)\n";
  }
  std::cout << "  上面作用域结束 → Dog d 析构\n";

  std::cout << "\n=== 2. 三层继承链 Animal -> Dog -> Puppy 的构造/析构顺序 ===\n";
  {
    Puppy p("Buddy");
    std::cout << "  (p 还在作用域内)\n";
  }
  std::cout << "  作用域结束 → Puppy 析构\n";

  std::cout << "\n=== 3. 结论 ===\n";
  std::cout << "  构造：基类 -> 成员 -> 派生类（从外到内，先父后子）\n";
  std::cout << "  析构：派生类 -> 成员 -> 基类（从内到外，先子后父）\n";
  return 0;
}
