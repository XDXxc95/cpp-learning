// practice/04-1/solutions/08_slicing.cpp — 参考答案：对象切片
#include <iostream>
#include <string>
#include <vector>

class Animal {
public:
  virtual std::string kind() const { return "Animal"; }
  virtual ~Animal() = default;
};

class Dog : public Animal {
public:
  explicit Dog(const std::string& breed) : breed_(breed) {}
  std::string kind() const override { return "Dog/" + breed_; }

private:
  std::string breed_; // Dog 特有 —— 切片时这一份会被丢掉
};

void byValue(Animal a) { // ⚠️ 按值传参：发生切片
  std::cout << "  byValue: " << a.kind() << "\n";
}

void byRef(const Animal& a) { // ✅ 按引用：不切片
  std::cout << "  byRef  : " << a.kind() << "\n";
}

int main() {
  Dog d("corgi");

  std::cout << "=== 1. 按值 vs 按引用 ===\n";
  byValue(d); // Animal —— breed_ 丢了，多态失效
  byRef(d);   // Dog/corgi —— 多态正常

  std::cout << "\n=== 2. 容器存值 vs 存指针 ===\n";
  {
    std::vector<Animal> by_value;
    by_value.push_back(d); // 切片：只复制「Animal 那部分」
    std::cout << "  vector<Animal>  : " << by_value[0].kind() << "\n";

    std::vector<Animal*> by_ptr;
    by_ptr.push_back(&d);
    std::cout << "  vector<Animal*>: " << by_ptr[0]->kind() << "\n";
  }

  std::cout << "\n=== 答案 ===\n";
  std::cout << "  1) 切片的本质：Animal a = d; 用的是【基类的拷贝构造函数】，\n";
  std::cout << "     它只会复制基类子对象那部分字节；Dog 特有的 breed_ 成员、\n";
  std::cout << "     以及指向 Dog 虚表的 vptr，全都没被复制过来。\n";
  std::cout << "     结果 a 是一个货真价实的 Animal 对象，不再是 Dog。\n";
  std::cout << "  2) 引用/指针只是给原对象取了个「别名」，不发生对象拷贝，\n";
  std::cout << "     原对象还是完整的 Dog，vptr 没变 → 多态自然保留。\n";
  std::cout << "  3) 容器要多态就存【指针】：vector<Animal*> 或\n";
  std::cout << "     vector<unique_ptr<Animal>>（智能指针见 M5-1）。\n";
  std::cout << "     注意：不要写 void f(Animal a) —— 参数一律 const Base& / Base*。\n";
  return 0;
}
