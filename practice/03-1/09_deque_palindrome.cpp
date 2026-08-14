// practice/03-1/09_deque_palindrome.cpp — 练习 9：deque 回文检查
//
// 题目：
//   输入一行字符串（可能含空格，用 getline）。
//   把每个字符放进 deque<char>，用双端比较判断是否回文：
//     - while (size > 1)：比较 front() 和 back()
//     - 不同 → 不是回文，结束；相同 → pop_front() + pop_back()，继续
//   回文输出 "palindrome"，否则 "not palindrome"。
//   示例：racecar → palindrome；hello → not palindrome；a b a → palindrome（含空格也照样判）。
//
// 完整题目见 practice/03-1/exercises.md；先自己写，再对照 solutions/09_deque_palindrome.cpp
#include <deque>
#include <iostream>
#include <string>

int main() {
  // TODO: 你的实现
  return 0;
}
