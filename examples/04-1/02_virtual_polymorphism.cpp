// examples/04-1/02_virtual_polymorphism.cpp — 静态绑定 vs 动态绑定
// Static binding vs dynamic binding: the same call, with and without virtual
#include <iostream>
#include <string>
#include <vector>

// ========== 版本 A：基类函数【没有】virtual ==========
class StaticAnimal {
public:
  void speak() const { std::cout << "    generic animal sound\n"; }
  virtual ~StaticAnimal() = default;
};

class StaticDog : public StaticAnimal {
public:
  void speak() const { std::cout << "    Woof!\n"; }
};

// ========== 版本 B：基类函数【有】virtual ==========
class Animal {
public:
  virtual void speak() const { std::cout << "    generic animal sound\n"; }
  virtual ~Animal() = default; // 有虚函数的基类，析构也 virtual
};

class Dog : public Animal {
public:
  void speak() const override { std::cout << "    Woof!\n"; }
};

class Cat : public Animal {
public:
  void speak() const override { std::cout << "    Meow!\n"; }
};

int main() {
  std::cout << "=== 1. 没有 virtual：静态绑定（编译期按指针类型定死）===\n";
  {
    StaticDog sd;
    StaticAnimal* sp = &sd; // 基类指针指向派生类对象（合法：Dog is-a Animal）
    std::cout << "  sp->speak()  (基类指针)：\n";
    sp->speak(); // generic —— 不是 Woof！
    std::cout << "  sd.speak()   (派生类对象)：\n";
    sd.speak(); // Woof —— 用对象本身调用永远是静态绑定
  }

  std::cout << "\n=== 2. 有 virtual：动态绑定（运行期按对象真实类型定）===\n";
  {
    Dog d;
    Cat c;

    Animal* by_pointer = &d;
    std::cout << "  通过基类指针 Animal* ：\n";
    by_pointer->speak(); // Woof

    Animal& by_reference = c;
    std::cout << "  通过基类引用 Animal& ：\n";
    by_reference.speak(); // Meow

    std::cout << "  通过基类指针容器 vector<Animal*> ：\n";
    std::vector<Animal*> zoo{&d, &c};
    for (Animal* p : zoo) {
      p->speak(); // Woof / Meow —— 同一个调用点，不同结果，这就是多态
    }

    std::cout << "  直接用对象调用 d.speak() ：\n";
    d.speak(); // Woof（这里本来就是 Dog）
  }

  std::cout << "\n=== 3. 多态三要素（缺一不可）===\n";
  std::cout << "  1) 基类函数有 virtual      2) 派生类 override 了它\n";
  std::cout << "  3) 通过【基类指针或引用】调用 —— 用对象本身调用不算\n";
  std::cout << "\n  对照第 1 节和第 2 节：同一句 p->speak()，\n";
  std::cout << "  有 virtual 时输出取决于【对象真实类型】，没有则取决于【指针声明类型】。\n";
  return 0;
}
