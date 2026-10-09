// examples/04-1/04_slicing_and_override.cpp — 对象切片与 final
// Object slicing, and the final keyword
#include <iostream>
#include <string>
#include <vector>

class Animal {
public:
  virtual ~Animal() = default;
  virtual std::string kind() const { return "Animal"; }
  virtual void speak() const { std::cout << "generic animal sound\n"; }
};

class Dog : public Animal {
public:
  explicit Dog(const std::string& breed) : breed_(breed) {}
  std::string kind() const override { return "Dog/" + breed_; }
  void speak() const override { std::cout << "Woof! (a " + breed_ + ")\n"; }

private:
  std::string breed_; // Dog 特有的数据成员 —— 切片时会被丢掉
};

// 按【值】传参：发生切片
void describeByValue(Animal a) {
  std::cout << "    [按值 Animal a  ] kind=" << a.kind() << " -> ";
  a.speak();
}

// 按【引用】传参：多态保留
void describeByRef(const Animal& a) {
  std::cout << "    [按引用 const&  ] kind=" << a.kind() << " -> ";
  a.speak();
}

int main() {
  Dog d("corgi");

  std::cout << "=== 1. 按值传参 vs 按引用传参 ===\n";
  describeByValue(d); // kind=Animal —— breed_ 被切掉，多态失效
  describeByRef(d);   // kind=Dog/corgi —— 多态正常

  std::cout << "\n=== 2. vector<Animal> 存值 vs vector<Animal*> 存指针 ===\n";
  {
    std::vector<Animal> by_value; // ⚠️ 存值
    by_value.push_back(d);        // 切片：只复制「Animal 那部分」
    std::cout << "    vector<Animal>  : kind=" << by_value[0].kind() << " -> ";
    by_value[0].speak();

    std::vector<Animal*> by_pointer; // ✅ 存指针
    by_pointer.push_back(&d);
    std::cout << "    vector<Animal*>: kind=" << by_pointer[0]->kind() << " -> ";
    by_pointer[0]->speak();
  }

  std::cout << "\n=== 3. 为什么会这样 ===\n";
  std::cout << "    Animal a = d;  ← 用基类拷贝构造，只复制基类子对象\n";
  std::cout << "    dog 特有的 breed_ 和它的虚表指针都丢了，对象被「切」成 Animal\n";
  std::cout << "    结论：要多态就传引用/指针，容器存指针（智能指针见 M5-1）\n";

  std::cout << "\n=== 4. final：禁止继续覆盖 / 禁止继承（编译期保护）===\n";
  {
    class SledDog final : public Dog { // 类加 final
    public:
      SledDog() : Dog("husky") {}
    };
    SledDog s;
    std::cout << "    SledDog s;  kind=" << s.kind() << "\n";

    // 下面两行都【编译不过】，取消注释可以自己验证：
    // class SuperSledDog : public SledDog {};  // ✗ SledDog 是 final，不能被继承
    // class Weird : public Dog { void kind() const final override; };
    //                                          // ✗ final 函数不能再被覆盖
    std::cout << "    (final 的效果是编译期报错，运行期看不到)\n";
  }

  return 0;
}
