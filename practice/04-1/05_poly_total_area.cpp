// practice/04-1/05_poly_total_area.cpp — 练习 5：多态求总面积
//
// 题目：
//   Shape 基类（virtual double area() const，非纯虚，给个 return 0; 的默认实现），
//   派生 Circle、Rect、Triangle。
//   用 std::vector<Shape*> 装齐三个对象（栈上对象取地址），
//   遍历求【总面积】并打印，再打印【面积最大】的图形的名字。
//
//   注释里回答：
//     - 如果把基类 area() 的 virtual 去掉，总面积会变成多少？为什么？
//     - 这里的调用点只写了 s->area()，编译器怎么知道该算谁的？
//
// 完整题目见 practice/04-1/exercises.md；先自己写，再对照 solutions/05_poly_total_area.cpp
#include <iostream>
#include <string>
#include <vector>

// TODO: 定义 Shape / Circle / Rect / Triangle

int main() {
  // TODO: 你的实现
  return 0;
}
