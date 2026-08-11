// hello.cpp — 环境验证：编译 → 运行 → 退出码
// Environment check: compile -> run -> exit code
// 编译运行 Compile & run: tools/compile.sh examples/00/hello.cpp

#include <iostream>
#include <string>

int main() {
    // 标准输出流 standard output stream
    std::cout << "Hello, World!" << std::endl;

    // 基本类型与字符串 basic types & string
    int year = 2026;                     // 整数 integer
    double pi = 3.1415926;               // 浮点 floating point
    std::string msg = "C++ learning";    // 字符串 string (STL)
    bool ready = true;                   // 布尔 boolean

    std::cout << "year=" << year
              << " pi=" << pi
              << " msg=" << msg
              << " ready=" << ready
              << std::endl;

    return 0; // 0 = 成功 success
}
