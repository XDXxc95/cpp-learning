// practice/04-1/solutions/06_virtual_dtor.cpp — 参考答案：虚析构与内存泄漏
#include <iostream>

// ================= 非虚析构：会泄漏 =================
class BadBase {
public:
  BadBase() { std::cout << "  [bad] BadBase ctor\n"; }
  ~BadBase() { std::cout << "  [bad] ~BadBase dtor\n"; } // ⚠️ 非虚

  virtual void hello() const { std::cout << "  [bad] hello\n"; }
};

class BadDerived : public BadBase {
public:
  BadDerived() : buf_(new int[100]) { std::cout << "  [bad] BadDerived ctor (new int[100])\n"; }
  ~BadDerived() {
    delete[] buf_;
    std::cout << "  [bad] ~BadDerived dtor (delete[] buf_)\n";
  }

private:
  int* buf_;
};

// ================= 虚析构：修好了 =================
class GoodBase {
public:
  GoodBase() { std::cout << "  [good] GoodBase ctor\n"; }
  virtual ~GoodBase() { std::cout << "  [good] ~GoodBase dtor\n"; } // ✅ 虚析构

  virtual void hello() const { std::cout << "  [good] hello\n"; }
};

class GoodDerived : public GoodBase {
public:
  GoodDerived() : buf_(new int[100]) { std::cout << "  [good] GoodDerived ctor (new int[100])\n"; }
  ~GoodDerived() override {
    delete[] buf_;
    std::cout << "  [good] ~GoodDerived dtor (delete[] buf_)\n";
  }

private:
  int* buf_;
};

int main() {
  std::cout << "=== 1. 非虚析构 ===\n";
  {
    BadBase* p = new BadDerived;
    p->hello();
    std::cout << "  delete p ...\n";
    // 本示例【故意】演示错误写法。GCC/Clang 在这里会给出
    //   warning: deleting object of polymorphic class type 'BadBase' which has
    //            non-virtual destructor might cause undefined behavior
    //            [-Wdelete-non-virtual-dtor]
    // 这条警告由 -Wall 开启。真实项目里应把基类析构改成 virtual，
    // 这里压掉只是为了把「运行时到底发生了什么」演完。
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdelete-non-virtual-dtor"
    delete p;
#pragma GCC diagnostic pop
  }

  std::cout << "\n=== 2. 虚析构（同一份代码，改一个字）===\n";
  {
    GoodBase* p = new GoodDerived;
    p->hello();
    std::cout << "  delete p ...\n";
    delete p;
  }

  std::cout << "\n=== 答案 ===\n";
  std::cout << "  1) 第 1 步只输出了 ~BadBase，【没有】~BadDerived：\n";
  std::cout << "     delete p 按 p 的声明类型 BadBase* 静态绑定到 ~BadBase()，\n";
  std::cout << "     派生类析构被整个跳过 → 构造里 new int[100] 泄漏了。\n";
  std::cout << "  2) 编译器【有】告警：-Wdelete-non-virtual-dtor，\n";
  std::cout << "     关键字是 delete-non-virtual-dtor（本项目 -Wall 已开启）。\n";
  std::cout << "     别把这条警告压掉——它就是在提醒你少写了一个 virtual。\n";
  std::cout << "  3) 修复：把基类析构写成 virtual，即 virtual ~BadBase()。\n";
  std::cout << "     经验法则：基类只要可能有虚函数，析构就顺手 virtual。\n";
  return 0;
}
