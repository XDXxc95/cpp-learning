// practice/03-1/solutions/01_string_reverse.cpp — M3-1 练习1 参考答案
#include <cstddef>
#include <iostream>
#include <string>

int main() {
  std::cout << "enter a line: ";
  std::string s;
  std::getline(std::cin, s);   // 读一整行（含空格）

  // 1. 长度 —— size() 返回 size_t
  std::cout << "length  = " << s.size() << "\n";

  // 2. 空格个数 —— range-for 遍历计数
  std::size_t spaces = 0;
  for (char c : s) {
    if (c == ' ') {
      ++spaces;
    }
  }
  std::cout << "spaces  = " << spaces << "\n";

  // 3. 反转 —— 从后往前取字符 push 进新 string
  //    用 i > 0 的写法，空串时循环不执行，也不会 size_t 下溢
  std::string rev;
  for (std::size_t i = s.size(); i > 0; --i) {
    rev.push_back(s[i - 1]);
  }
  std::cout << "reversed = " << rev << "\n";

  return 0;
}
