// practice/04-1/08_slicing.cpp — 练习 8：对象切片
//
// 题目：
//   1. 基类 Animal：virtual std::string kind() const 返回 "Animal"；
//      派生 Dog：额外成员 std::string breed_，kind() 返回 "Dog/" + breed_
//   2. 写两个函数：void byValue(Animal a) 和 void byRef(const Animal& a)，
//      都打印 a.kind()
//   3. main 里各调一次，比较输出
//   4. 再对比 std::vector<Animal>（push_back 一个 Dog）
//      和 std::vector<Animal*>（push_back &dog）打印 kind()
//
//   注释里回答：
//     - 切片的【本质】是什么？（拷贝了什么？丢了什么？）
//     - 为什么引用/指针不会切片？
//     - 容器里想放多态对象，应该存什么？
//
// 完整题目见 practice/04-1/exercises.md；先自己写，再对照 solutions/08_slicing.cpp
#include <iostream>
#include <string>
#include <vector>

// TODO: 定义 Animal / Dog

// TODO: 定义 byValue / byRef

int main() {
  // TODO: 你的实现
  return 0;
}
