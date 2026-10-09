// practice/04-1/solutions/03_virtual_override.cpp — 参考答案：virtual 覆盖初体验
#include <iostream>
#include <string>

class Animal {
public:
  virtual void speak() const { std::cout << "generic animal sound\n"; }
  virtual ~Animal() = default;
};

class Dog : public Animal {
public:
  void speak() const override { std::cout << "Woof!\n"; }
};

class Cat : public Animal {
public:
  void speak() const override { std::cout << "Meow!\n"; }
};

// 参数是【基类引用】——这是多态生效的必要条件之一
void makeSpeak(const Animal& a) {
  a.speak(); // 这一行在编译期只认 Animal，但运行期按对象真实类型分派
}

int main() {
  Dog d;
  Cat c;

  std::cout << "=== makeSpeak() 的输出 ===\n";
  std::cout << "  dog: ";
  makeSpeak(d); // Woof!
  std::cout << "  cat: ";
  makeSpeak(c); // Meow!

  std::cout << "\n=== 答案 ===\n";
  std::cout << "  1) 为什么写死了 a.speak() 却结果不同？\n";
  std::cout << "     speak() 是 virtual，且通过【基类引用】调用 → 动态绑定：\n";
  std::cout << "     运行期查对象的虚函数表，调的是对象真实类型那一版。\n";
  std::cout << "  2) 删掉基类的 virtual 会怎样？\n";
  std::cout << "     两次都输出 generic animal sound。此时是静态绑定，\n";
  std::cout << "     编译器只看 a 的声明类型 Animal&，编译期就定死了调 Animal::speak。\n";
  return 0;
}
