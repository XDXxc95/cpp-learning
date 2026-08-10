// examples/03/02_string_ops.cpp — std::string 字符串常用操作
// Common std::string operations
#include <iostream>
#include <string>

int main() {
  // 构造与拼接
  std::string s = "Hello";
  s += ", ";
  s += "world";
  std::cout << s << "\n";                     // Hello, world
  std::cout << "length=" << s.length() << "\n";  // 12

  // 子串与查找：substr / find（找不到返回 npos）
  std::string sub = s.substr(0, 5);           // 从 0 开始取 5 个字符
  std::cout << "substr(0,5)=" << sub << "\n";
  size_t pos = s.find("world");
  std::cout << "find(\"world\")=" << pos << "\n";   // 7
  if (s.find("xyz") == std::string::npos) {
    std::cout << "\"xyz\" not found (npos=" << std::string::npos << ")\n";
  }

  // 按字符访问与修改
  s[0] = 'J';
  std::cout << s << "\n";                     // Jello, world

  // 读整行（含空格）：getline；注意它和 >> 混用时要先吃残留换行
  std::cout << "input a line: ";
  std::string line;
  std::getline(std::cin, line);
  std::cout << "you said: [" << line << "]\n";

  // 与 C 字符串互转：c_str() 返回 const char*；s 再被修改后指针可能失效
  const char* c = s.c_str();
  std::cout << "c_str: " << c << "\n";

  // 比较：字典序
  std::cout << "\"abc\" < \"abd\" ? " << (std::string("abc") < std::string("abd")) << "\n";

  return 0;
}
