// examples/02/04_memory_bugs.cpp — 常见内存错误：注释讲解 + 安全对照
// Common memory bugs: commented demos + safe patterns
// ⚠️ 危险代码全部注释掉了——取消注释运行会崩溃或未定义行为(UB)。
// 本程序本身只运行安全写法，验证输出稳定。
#include <iostream>

// 谁 new 谁 delete：本函数 new 了数组，责任交给调用方
int* makeArray(int n) { return new int[n]; }

int main() {
  // ── Bug 1: 悬垂指针 Dangling pointer (use-after-free) ──
  // int* p = new int(1);
  // delete p;
  // std::cout << *p << "\n";   // ❌ UB：p 指向已释放内存，读的是垃圾
  // 修复：删完立刻置空
  int* p = new int(1);
  delete p;
  p = nullptr;
  if (p != nullptr) {            // 判空防御
    std::cout << *p << "\n";
  }

  // ── Bug 2: 内存泄漏 Memory leak ──
  // for (int i = 0; i < 1000000; ++i) {
  //   new int(i);                // ❌ new 了不 delete，堆无限膨胀
  // }                            //    长跑服务/循环里泄漏必挂
  // 修复：一个 new 恰好一个 delete；或改用 vector / 智能指针（M5）
  int* leak = new int(10);
  std::cout << *leak << "\n";
  delete leak;

  // ── Bug 3: 双重释放 Double free ──
  // int* q = new int(5);
  // delete q;
  // delete q;                    // ❌ UB：同一块内存释放两次，堆损坏
  // 修复：只删一次 + 删完置空
  int* q = new int(5);
  delete q;
  q = nullptr;

  // ── Bug 4: 返回局部变量的地址/引用 ──
  // int& badRef() { int x = 1; return x; }   // ❌ 函数返回后 x 销毁
  // 修复：按值返回；或让对象活得更久（堆 / 由调用方传入）

  // ── Bug 5: new[] 配 delete（配对错误）──
  // int* a = new int[10];
  // delete a;                    // ❌ 必须 delete[] a
  // 修复：new[] 永远配 delete[]

  // ── 安全对照：动态数组的正确完整收尾 ──
  int* arr = makeArray(4);
  for (int i = 0; i < 4; ++i) {
    arr[i] = i + 1;
  }
  delete[] arr;
  arr = nullptr;

  std::cout << "all safe patterns ran fine\n";
  return 0;
}
