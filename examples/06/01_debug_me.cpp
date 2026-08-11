// 01_debug_me.cpp — gdb 调试练习目标 | debug practice target
// 编译 Compile: tools/compile.sh examples/06/01_debug_me.cpp
// 程序行为 Behavior: 输出相邻元素两两求和的结果（result[i] = v[i] + v[i+1]）
//   正确输出应为 3 个值：1+2, 2+3, 3+4 → "3 5 7"
//
// ⚠️ 这个程序输出错了，但编译无警告、运行不崩溃。用 gdb 找到原因。
// ⚠️ Wrong output, no warnings, no crash. Find the cause with gdb.

#include <iostream>
#include <vector>

// 相邻元素两两求和 | adjacent element sums
std::vector<int> adjacent_sums(const std::vector<int>& v) {
    std::vector<int> result;
    const int* p = v.data();          // 裸指针（无越界检查）| raw pointer, no bounds check
    size_t n = v.size();
    for (size_t i = 0; i < n; ++i) {
        result.push_back(p[i] + p[i + 1]);
    }
    return result;
}

int main() {
    std::vector<int> data = {1, 2, 3, 4};
    auto sums = adjacent_sums(data);
    for (int x : sums) std::cout << x << ' ';
    std::cout << '\n';
    return 0;
}
