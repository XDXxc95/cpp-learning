// practice/04-1/10_shape_system.cpp — 练习 10：简易图形清单系统（综合）
//
// 题目：
//   1. 抽象基类 Shape：
//        virtual double area() const = 0;
//        virtual double perimeter() const = 0;
//        virtual const char* name() const = 0;
//        virtual ~Shape() = default;
//   2. 三个派生类 Circle（半径）、Rectangle（宽高）、
//      Triangle（三边，周长 = 三边和；面积用海伦公式）
//   3. main 里：
//        - 用 new 创建若干图形，放进 std::vector<Shape*>
//        - 遍历打印每个图形的 name / area / perimeter
//        - 打印总面积和面积最大的图形名字
//        - 最后循环 delete 释放，【验证每个派生类的析构都执行了】
//          （在派生类析构里打印一行，如 "[dtor] Circle"）
//
//   示例输出形状（数值自己算）：
//        circle  area=12.5664  perimeter=12.5664
//        rect    area=12       perimeter=14
//        tri     area=6        perimeter=12
//        total area = 30.5664
//        largest = circle
//        [dtor] Circle
//        [dtor] Rectangle
//        [dtor] Triangle
//
//   注释里回答：
//     - 为什么这里 ~Shape() 必须是 virtual？如果写成非虚，最后那三行 [dtor] 会少哪些？
//     - 为什么容器是 std::vector<Shape*> 而不是 std::vector<Shape>？
//     - 海伦公式：三边 a,b,c，半周长 s=(a+b+c)/2，
//       面积 sqrt(s(s-a)(s-b)(s-c))（需要 <cmath>）
//
// 完整题目见 practice/04-1/exercises.md；先自己写，再对照 solutions/10_shape_system.cpp
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

// TODO: 定义抽象类 Shape

// TODO: 定义 Circle / Rectangle / Triangle

int main() {
  // TODO: 你的实现
  return 0;
}
