// 01_types.cpp — 基本类型、sizeof、隐式转换
// Basic types, sizeof, implicit conversion
#include <iostream>
#include <string>

int main() {
    // 基本类型 basic types
    bool        b = true;   // 布尔 boolean
    char        c = 'A';    // 字符 character
    int         i = 42;     // 整数 integer
    double      d = 3.14;   // 浮点 floating-point
    std::string s = "hi";   // 字符串 string (STL)

    std::cout << "sizeof(bool)=" << sizeof(b)
              << " sizeof(char)=" << sizeof(c)
              << " sizeof(int)=" << sizeof(i)
              << " sizeof(double)=" << sizeof(d)
              << " sizeof(string)=" << sizeof(s)
              << std::endl;

    // 整数除法陷阱 integer division (注意！)
    int a = 7, b2 = 2;
    std::cout << "7/2=" << a / b2              // 3  （整数除法 truncates）
              << "  7.0/2=" << a / 2.0          // 3.5
              << "  (double)7/2=" << (double)a / b2  // 3.5
              << std::endl;

    // 类型别名 type alias (C++11)
    using u64 = unsigned long long;
    u64 big = 18446744073709551615ULL;
    std::cout << "u64 max=" << big << std::endl;

    return 0;
}
