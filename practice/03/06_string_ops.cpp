// practice/03/06_string_ops.cpp — M3 练习6：string 字符串处理
// 输入：一行英文句子（可能含空格，用 getline）
// 输出：单词个数 / 最长单词（并列取第一个）/ 反转后的整个句子
// 提示：数单词用 <sstream> 的 std::istringstream（>> 按空白切分）；
//       反转用反向迭代器 std::string rev(line.rbegin(), line.rend());
#include <iostream>
#include <sstream>
#include <string>

int main() {
  std::string s;
  std::getline(std::cin, s);

  std::istringstream iss(s);

  std::string word, longest;
  int count = 0;
  while (iss >> word) {
    count++;
    if (word.length() > longest.length()) {
      longest = word;
    }
  }
  std::string reversed(s.rbegin(), s.rend());

  std::cout << count << "\n" << longest << "\n" << reversed << "\n";

  return 0;
}
