// examples/03-1/01_string_basics.cpp — std::string 基础操作
#include <cstddef>
#include <iostream>
#include <string>

int main() {
  // --- 创建 ---
  std::string s1 = "hello";
  std::string s2(5, 'a');            // "aaaaa"
  std::string s3 = s1 + ", world";   // 拼接
  std::cout << "s1 = " << s1 << "\n";
  std::cout << "s2 = " << s2 << "\n";
  std::cout << "s3 = " << s3 << "\n";

  // --- 大小与判空 ---
  std::cout << "s1.size() = " << s1.size() << "\n";     // 5
  std::cout << "s1.length() = " << s1.length() << "\n"; // 5，与 size 等价
  std::cout << "s3.empty() = " << std::boolalpha << s3.empty() << "\n";

  // --- 索引与修改 ---
  s1[0] = 'H';           // 改首字符
  s1.push_back('!');     // 尾部追加
  std::cout << "s1 = " << s1 << "\n";   // "Hello!"

  // --- 查找：find 找不到返回 std::string::npos ---
  std::size_t pos = s3.find("world");
  if (pos != std::string::npos) {
    std::cout << "'world' at index " << pos << "\n";  // 7
  } else {
    std::cout << "'world' not found\n";
  }

  // --- 子串 substr(pos, len)，len 省略 = 到末尾 ---
  std::cout << "s3.substr(7) = " << s3.substr(7) << "\n";     // "world"
  std::cout << "s3.substr(0, 5) = " << s3.substr(0, 5) << "\n";  // "hello"

  // --- 遍历（range-for，只读）---
  for (char c : s1) {
    std::cout << c << ' ';
  }
  std::cout << "\n";

  // --- 比较（字典序）---
  if (s1 == "Hello!") std::cout << "s1 == \"Hello!\"\n";
  if (s1 > "abc") std::cout << "s1 > \"abc\" (lexicographic)\n";

  return 0;
}
