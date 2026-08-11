// practice/03/solutions/09_word_freq_top.cpp — 参考答案：综合 · 词频 Top-K
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

int main() {
  std::string line;
  std::getline(std::cin, line);

  // 1. map 统计词频：freq[word]++ 首次遇到自动插默认值 0 再自增
  std::map<std::string, int> freq;
  std::istringstream iss(line);
  std::string word;
  while (iss >> word) freq[word]++;

  // 2. 倒进 vector<pair>，按次数降序、次数相同按字典序升序
  std::vector<std::pair<std::string, int>> items(freq.begin(), freq.end());
  std::sort(items.begin(), items.end(),
            [](const auto& a, const auto& b) {
              if (a.second != b.second) return a.second > b.second;
              return a.first < b.first;
            });

  // 3. 打印 Top-3
  int shown = 0;
  for (const auto& p : items) {
    if (shown >= 3) break;
    std::cout << p.first << " " << p.second << "\n";
    shown++;
  }
  return 0;
}
