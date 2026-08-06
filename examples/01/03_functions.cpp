// 03_functions.cpp — 函数：值传递、默认参数、重载、引用参数
// Functions: pass-by-value, default args, overloading, pass-by-reference
#include <iostream>
#include <string>

// 值传递 pass by value —— 复制一份，函数里改不到原变量
int add(int a, int b) { return a + b; }

// 默认参数 default arguments（默认值只能靠右放）
void greet(const std::string& name, const std::string& prefix = "Hello") {
    std::cout << prefix << ", " << name << "!" << std::endl;
}

// 重载 overloading —— 同名函数、不同参数列表
int    max(int a, int b)    { return a > b ? a : b; }
double max(double a, double b) { return a > b ? a : b; }

// 引用参数 pass by reference —— 可以改原变量，且不复制
void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

int main() {
    int x = 3, y = 5;
    std::cout << "add(3,5)=" << add(x, y) << std::endl;

    greet("Alice");          // 用默认前缀
    greet("Bob", "Hi");      // 显式前缀

    std::cout << "max(1,2)=" << max(1, 2)
              << " max(1.5,2.5)=" << max(1.5, 2.5) << std::endl;

    swap(x, y);
    std::cout << "after swap: x=" << x << " y=" << y << std::endl;  // x=5 y=3
    return 0;
}
