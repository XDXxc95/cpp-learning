// practice/03/solutions/02_string_warmup.cpp — 参考答案：string 最小操作
#include <iostream>
#include <string>

int main() {
  std::string s1 = "Hello", s2 = "World";
  std::string joined = s1 + s2;
  std::cout << "concat=" << joined << "\n";              // HelloWorld

  std::string sub = s2.substr(0, 3);
  std::cout << "substr=" << sub << "\n";                 // Wor

  std::size_t pos = s1.find("lo");
  std::cout << "find 'lo' at " << pos << "\n";           // 3
  std::size_t miss = s1.find("xyz");
  std::cout << (miss == std::string::npos ? "not found" : "found") << "\n";

  std::string line;
  std::getline(std::cin, line);
  std::cout << "line length=" << line.size() << " content=" << line << "\n";
  return 0;
}
