// practice/03/solutions/04_string_ops.cpp — 参考答案：string 单词处理
#include <iostream>
#include <sstream>
#include <string>

int main() {
  std::string line;
  std::getline(std::cin, line);

  // istringstream 按空白自动切分，每次 >> 出一个单词
  std::istringstream iss(line);
  std::string word, longest;
  int count = 0;
  while (iss >> word) {
    count++;
    if (word.length() > longest.length()) longest = word;   // 并列取第一个
  }

  std::string rev(line.rbegin(), line.rend());   // 反向迭代器构造反转串
  std::cout << "words=" << count << "\n";
  std::cout << "longest=" << longest << "\n";
  std::cout << "reversed=" << rev << "\n";
  return 0;
}
