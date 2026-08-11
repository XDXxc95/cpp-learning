// practice/03-1/01_string_reverse.cpp — M3-1 练习1：string 反转
// 要求：getline 读一行 → 打印长度/空格数/反转字符串
#include <iostream>
#include <string>

int main() {
  // TODO: 读入一行（含空格），完成 3 个任务
  //   1. 长度（size()）
  //   2. 空格个数（遍历数 ' '）
  //   3. 反转后的字符串（倒序拼到新 string）

  std::string s;
  std::getline(std::cin, s);

  size_t length = s.size();
  std::cout << "length : " << length << "\n";

  int spaceCount = 0;
  for (auto ch : s) {
    if (ch == ' ') {
      spaceCount++;
    }
  }
  std::cout << "spaceCount : " << spaceCount << "\n";

  std::string reversed;
  for (size_t i = length ; i > 0; --i) {
    reversed.push_back(s[i-1]);
  }
  std::cout << "reversed : " << reversed << "\n";

  return 0;
}
