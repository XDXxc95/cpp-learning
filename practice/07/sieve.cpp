// practice/07/sieve.cpp — M7 预习：埃拉托色尼筛法 | Sieve of Eratosthenes (preview)
// 目标：一次找出 [2..n] 的所有素数，复杂度 O(N log log N)
// 期望输出 Expected: 2 3 5 7 11 13 17 19 23 29
#include <iostream>
#include <vector>

// 返回 [2..n] 里所有素数（升序）
std::vector<int> sieve(int n) {
    std::vector<char> is_prime(n + 1, 1);  // 1 = 暂时认为是素数（用 char，避免 vector<bool> 的坑）
    // TODO: 实现三小步
    //  1) is_prime[0] = is_prime[1] = 0;            // 0、1 不是素数
    is_prime[0] = 0;
    is_prime[1] = 0;
    //  2) 外层 for (int i = 2; i * i <= n; ++i):    
    //        if (is_prime[i])                        // i 还是素数
    //           内层 for (int j = i * i; j <= n; j += i) is_prime[j] = 0;   // 划掉 i 的倍数，从 i*i 开始
    
    for (int i = 2; i * i <= n; ++i)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                is_prime[j] = 0;
            }
        }
    }
    //  3) 收集所有 is_prime[i] 仍为 1 的 i 到结果里
    std::vector<int> vec_res;
    int length = is_prime.size();
    for (int i = 0; i < length ; i++)
    {
        if (is_prime[i])
        {
            vec_res.emplace_back(i);
        }   
    }
    return vec_res;


}

int main() {
    auto primes = sieve(2);
    for (int p : primes) std::cout << p << " ";
    std::cout << "\n";
    return 0;
}
