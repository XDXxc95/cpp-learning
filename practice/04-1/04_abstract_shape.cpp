// practice/04-1/04_abstract_shape.cpp — 练习 4：抽象类与纯虚函数
//
// 题目：
//   1. 抽象类 Shape：
//        virtual double area() const = 0;
//        virtual const char* name() const = 0;
//        virtual ~Shape() = default;
//   2. 派生 Circle（半径 r）和 Square（边长 s），各自实现两个纯虚函数。
//   在 main 里用 Shape* 数组装这两个对象（栈上对象取地址），
//   循环打印名字和面积。
//
//   注释里回答：
//     - Shape s; 为什么编译不过？
//     - 如果 Square 只实现了 area() 而没实现 name()，会发生什么？它自己能创建对象吗？
//
// 完整题目见 practice/04-1/exercises.md；先自己写，再对照 solutions/04_abstract_shape.cpp
#include <iostream>

// TODO: 定义抽象类 Shape

// TODO: 定义 Circle / Square

int main() {
  // TODO: 你的实现
  return 0;
}
