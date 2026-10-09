// practice/04-1/03_virtual_override.cpp — 练习 3：virtual 覆盖初体验
//
// 题目：
//   1. 基类 Animal：virtual void speak() const 打印 "generic animal sound"
//   2. 派生 Dog：void speak() const override 打印 "Woof!"
//   3. 派生 Cat：void speak() const override 打印 "Meow!"
//   4. 自由函数 void makeSpeak(const Animal& a)，函数体只有 a.speak();
//   在 main 里对 Dog 和 Cat 各调一次 makeSpeak()。
//
//   注释里回答：
//     - 为什么 makeSpeak 函数体写死了 a.speak()，却分别输出了 Woof! 和 Meow!？
//     - 如果把基类的 virtual 关键字【删掉】，输出会变成什么？为什么？
//
// 完整题目见 practice/04-1/exercises.md；先自己写，再对照 solutions/03_virtual_override.cpp
#include <iostream>
#include <string>

// TODO: 定义 Animal / Dog / Cat

// TODO: 定义 makeSpeak

int main() {
  // TODO: 你的实现
  return 0;
}
