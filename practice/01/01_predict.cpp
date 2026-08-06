// practice/01/01_predict.cpp — M1 练习1：预测输出（类型与转换）
// 先不编译，把预测值填到每行的 "我预测:" 后面，再编译运行对比。
#include <iostream>

int main() {
    int a = 7, b = 2;

    double r1 = a / b;          // 我预测:3.0
    double r2 = (double)a / b;  // 我预测:3.5
    bool   r3 = 3 > 2;          // 我预测:1
    char   r4 = 'A' + 1;        // 我预测:B
    int    r5 = r4;             // 我预测:66

    std::cout << r1 << " " << r2 << " " << r3 << " " << r4 << " " << r5 << "\n";
    return 0;
}
