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

  return 0;
}
