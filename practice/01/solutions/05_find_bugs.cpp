// 练习 5 参考答案 · 找 Bug（修复版）
// Reference solution: fixed version
#include <iostream>

int main() {
    // Bug1: 原代码 `i <= 10` 会打印 0~10 共 11 个数（多打一个 0²）
    //       目标 1~10，应为 `i <= 10`，且从 i=1 开始。
    // 修复：for (int i = 1; i <= 10; ++i)
    // Bug2: 原代码换行条件 `i % 5 == 0` 会多出一个空行在 10 之后。
    //       改为「每 5 个一行」，用计数器控制。
    int col = 0;
    for (int i = 1; i <= 10; ++i) {
        std::cout << i * i << " ";
        ++col;
        if (col % 5 == 0) std::cout << "\n";
    }
    std::cout << std::endl;
    return 0;
}
