// practice/03/09_word_freq_top.cpp — M3 练习9：综合 · 词频 Top-K（学后收口）
// 目标：把 string + map + vector + sort 全串起来，贴近刷题（LeetCode「前 K 个高频词」同款）
// 输入：一行英文句子（可能含空格，用 getline）
// 输出：
//   1. 用 std::map<std::string, int> 统计每个单词出现次数（词频）
//   2. 把 (单词, 次数) 倒进 vector<pair<string,int>>，按「次数降序」排序，
//      次数相同按「单词字典序」升序（用 std::sort + lambda 自定义比较）
//   3. 打印次数最多的 3 个词，格式「word count」，每行一个
// 示例：输入 "a cat a dog a cat" → 输出 a 3 / cat 2 / dog 1
// 提示：分词用 <sstream> 的 std::istringstream；排序用 sort 第三个参数（lambda）
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

int main() {
  // TODO: 你的实现（要求 1-3）
  std::string s;
  std::getline(std::cin, s);

  std::istringstream iss(s);
  std::string word;
  std::map<std::string, int> recode;
  while (iss >> word) {
    recode[word]++;
  }

  std::vector<std::pair<std::string, int>> output;
  for (const auto& it : recode) {
    output.push_back({it.first, it.second});
  }

  std::sort(output.begin(), output.end(), [](const auto& a, const auto& b) {
    if (a.second != b.second) {
      return a.second > b.second;
    }
    return a.first < b.first;
  });

  constexpr size_t MAX_OUTPUT_COUNTS = 3;

  size_t length = std::min(output.size(), MAX_OUTPUT_COUNTS);
  for (size_t i = 0; i < length; i++) {
    std::cout << output[i].first << " " << output[i].second << "\n";
  }

  return 0;
}
