// practice/01/02_is_prime.cpp — M1 练习2：素数判断 isPrime
// 达标标准：① 能处理 n < 2 ② 有提前返回 ③ 循环到 √n 即可（可先写简单版再优化）
#include <iostream>
#include <cmath>
// 判断 n 是否为素数（质数）| returns true if n is prime
bool isPrime(int n) {
    // TODO: 你自己写。要点：
    //  1) n < 2 直接 return false（提前返回 early return）
    //  2) 在 2 到 sqrt(n) 之间找因子：有能整除 n 的 → return false
    //     （用 i * i <= n 就不用引 <cmath>）
    //  3) 都没有 → return true
#define SOLUTION

#ifndef SOLUTION
    if (n < 2)
    {
        return false;
    }

    int limit = static_cast<int>(std::sqrt(n));

    for (int i = 2; i <= limit; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
#else
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i*i <= n; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;

#endif


}

int main() {
    // 打印 2~30 的所有素数
    for (int n = 2; n <= 30; ++n) {
        if (isPrime(n)) {
            std::cout << n << " ";
        }
    }
    std::cout << "\n";
    return 0;
}
