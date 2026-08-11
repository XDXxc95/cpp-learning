// practice/03/02_string_warmup.cpp — M3 练习2：string 最小操作（热身）
// 目标：跑通 string 最常用的 4 个点
//   1. 拼接：s1 = "Hello"，s2 = "World"，用 + 拼出 "HelloWorld" 打印
//   2. 子串：substr(pos, len) 取 "World" 的前 3 个字符 "Wor" 打印
//   3. 查找：find 找 "lo" 在 "Hello" 里的下标位置，找不到时怎么判断——打印位置
//   4. 读整行：getline 读一行（可能含空格），打印读到的长度和内容
// 提示：find 找不到返回 std::string::npos（是个极大值），用它判断
#include <iostream>
#include <string>

int main() {
  // TODO: 你的实现（要求 1-4）
  std::string s1 = "Hello";
  std::string s2 = "World";
  std::string s = s1 + s2;

  std::cout << s << "\n";

  std::cout << s2.substr(0, 3) << "\n";

  auto pos = s1.find("lo");
  if (pos == std::string::npos) {
    std::cout << "not found!\n";
  } else {
    std::cout << pos << "\n";
  }

  std::string input;

  std::getline(std::cin, input);
  std::cout << "input : " << input << " length : " << input.size();

  return 0;
}
