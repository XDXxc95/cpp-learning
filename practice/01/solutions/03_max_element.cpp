// 练习 3 参考答案 · 找最大值和下标（两种遍历对比）
// Reference solution: max element & its index
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v{4, 9, 2, 7, 5};

    // 版本一：下标 for 循环（能拿到下标）
    int maxIdx = 0;
    for (int i = 1; i < static_cast<int>(v.size()); ++i) {
        if (v[i] > v[maxIdx]) maxIdx = i;
    }
    std::cout << "max = " << v[maxIdx] << " at index " << maxIdx << std::endl;

    // 版本二：range-for（只拿值，拿不到下标）
    int maxVal = v[0];
    for (int x : v) {
        if (x > maxVal) maxVal = x;
    }
    std::cout << "max = " << maxVal << std::endl;

    return 0;
}
