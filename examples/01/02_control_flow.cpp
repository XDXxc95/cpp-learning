// 02_control_flow.cpp — 控制流：if/for/range-for/while/do-while/switch
// Control flow
#include <iostream>
#include <vector>

int main() {
    // if / else
    for (int i = 0; i < 5; ++i) {
        if (i % 2 == 0)
            std::cout << i << " is even\n";
        else
            std::cout << i << " is odd\n";
    }

    // range-based for (C++11) 基于范围的 for，遍历容器
    std::vector<int> v{10, 20, 30};
    std::cout << "v: ";
    for (int x : v) std::cout << x << " ";
    std::cout << std::endl;

    // while
    int n = 3;
    while (n > 0) {
        std::cout << "while n=" << n << "\n";
        --n;
    }

    // do-while：至少执行一次 runs at least once
    int m = 0;
    do {
        std::cout << "do-while m=" << m << "\n";
    } while (m > 0);

    // switch
    int day = 3;
    switch (day) {
        case 1: std::cout << "Monday\n";   break;
        case 2: std::cout << "Tuesday\n";  break;
        default: std::cout << "Other day\n"; break;  // 不要漏 break！
    }

    return 0;
}
