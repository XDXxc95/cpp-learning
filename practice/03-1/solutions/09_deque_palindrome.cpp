// practice/03-1/solutions/09_deque_palindrome.cpp — 参考答案：deque 回文检查
#include <deque>
#include <iostream>
#include <string>

int main() {
  std::string line;
  std::getline(std::cin, line);

  std::deque<char> d(line.begin(), line.end()); // 整串塞进 deque
  bool pal = true;
  while (d.size() > 1) {
    if (d.front() != d.back()) { // 头尾不同 → 不是回文
      pal = false;
      break;
    }
    d.pop_front();
    d.pop_back();
  }
  std::cout << (pal ? "palindrome" : "not palindrome") << "\n";
  return 0;
}
// 思路：deque 两端都能 O(1) 取 + 删，天然适合「头尾对称比较」。
// 用 vector 也能做（下标左右夹逼），但 deque 的 pop_front/pop_back 语义更直接。
