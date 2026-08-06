// 练习 2 参考答案 · 素数判断
// Reference solution: isPrime
#include <iostream>

// 判断 n 是否为素数
bool isPrime(int n) {
    if (n < 2) return false;          // 0 和 1 不是素数
    if (n == 2) return true;          // 2 是唯一的偶素数
    if (n % 2 == 0) return false;     // 其他偶数直接排除
    // 只需检查奇数因子到 sqrt(n)
    for (int d = 3; d * d <= n; d += 2) {
        if (n % d == 0) return false;
    }
    return true;
}

int main() {
    std::cout << "primes in [2, 30]: ";
    for (int n = 2; n <= 30; ++n) {
        if (isPrime(n)) std::cout << n << " ";
    }
    std::cout << std::endl;
    return 0;
}
