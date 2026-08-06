// 练习 6 参考答案 · 指针版 swap
// Reference solution: swap via pointers
#include <iostream>

// 指针版：参数是指针，调用方传地址 &x、&y
void swapPtr(int* a, int* b) {
    // 防御：空指针不能解引用
    if (!a || !b) return;
    int t = *a;   // 解引用 dereference：取指针指向的值
    *a = *b;
    *b = t;
}

int main() {
    int x = 3, y = 5;
    std::cout << "before: x=" << x << " y=" << y << std::endl;
    swapPtr(&x, &y);                     // 取地址取址 operator&
    std::cout << "after:  x=" << x << " y=" << y << std::endl;
    return 0;
}
