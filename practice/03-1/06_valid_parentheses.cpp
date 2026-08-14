// practice/03-1/06_valid_parentheses.cpp — 练习 6：括号匹配（stack）
//
// 题目：
//   输入一行只含 ( ) [ ] { } 的字符串（可用 getline）。
//   判断括号是否匹配：每个左括号必须被对应类型的右括号闭合，且嵌套顺序正确。
//   匹配输出 "valid"，否则 "invalid"。
//
//   算法（用 stack）：
//     - 遇到左括号 → push
//     - 遇到右括号 → 看栈顶是不是同类型的左括号：是就 pop，不是/栈空 → invalid
//     - 结束时栈必须为空（否则有左括号没闭合）
//   示例：({[]}) → valid；([)] → invalid；((() → invalid；() → valid。
//
//   这是 LeetCode 20 原题。
//
// 完整题目见 practice/03-1/exercises.md；先自己写，再对照 solutions/06_valid_parentheses.cpp
#include <iostream>
#include <stack>
#include <string>

int main() {
  // TODO: 你的实现
  return 0;
}
