// practice/04-1/01_inheritance_access.cpp — 练习 1：继承与访问控制
//
// 题目：
//   1. 基类 Person：protected std::string name_、private int age_、
//      public void greet() const（打印 "Hi, I'm <name_>"）
//   2. 派生类 Student : public Person：构造函数接受 name 和 age，
//      另有 void study() const（打印 "<name_> is studying"）
//   在 main 里创建一个 Student，调用 greet()（继承来的）和 study()。
//
//   注释里回答：
//     - Student::study() 里能直接读 name_ 吗？能读 age_ 吗？各为什么？
//     - main 里能写 s.name_ 吗？能写 s.age_ 吗？各为什么？
//
// 完整题目见 practice/04-1/exercises.md；先自己写，再对照 solutions/01_inheritance_access.cpp
#include <iostream>
#include <string>

// TODO: 定义基类 Person

// TODO: 定义派生类 Student

int main() {
  // TODO: 你的实现
  return 0;
}
