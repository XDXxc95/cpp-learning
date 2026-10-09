// practice/03-1/10_topk_freq_words.cpp — 练习 10：前 K 高频词（堆解法）
//
// 题目：
//   这是 M3 练习 9 的「堆解法」版——把 unordered_map + priority_queue 串起来，LeetCode 347 思路：
//     1. 用 std::unordered_map<std::string,int> 统计一行句子里每个单词出现次数
//        （getline + istringstream 分词，同 M3 练习 9）
//     2. 把 (单词, 次数) 倒进 std::vector<std::pair<...>>
//     3. 放进 priority_queue，自定义比较器，按「次数降序，次数相同字典序升序」取前 3 个词，
//        格式 "word count" 每行一个
//
//   自定义比较器方向提示：priority_queue 里 comp(a, b) 返回 true 表示 a 的优先级比 b 低（a 更晚出队）。
//   想要「次数多的先出」：
//     - a.second != b.second → 返回 a.second < b.second（次数少的 = 优先级低）
//     - 相同 → 返回 a.first > b.first（字典序大的 = 优先级低）
//
//   示例：输入 a cat a dog a cat → 输出 a 3 / cat 2 / dog 1。
//
// 完整题目见 practice/03-1/exercises.md；先自己写，再对照 solutions/10_topk_freq_words.cpp
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

struct Compare {
  bool operator()(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
    if (a.second != b.second) {
      return a.second < b.second;
    }
    return a.first > b.first;
  }
};

int main() {

  std::string line;
  std::getline(std::cin, line);

  std::unordered_map<std::string, int> freq;
  std::istringstream iss(line);
  std::string word;
  while (iss >> word) {
    freq[word]++;
  }

  //
  std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>,
                      Compare>
      pq;
  for (const auto& kv : freq) {
    pq.push(kv);
  }

  int shown = 0;
  while (!pq.empty() && shown < 3) {
    std::cout << pq.top().first << " " << pq.top().second << "\n";
    pq.pop();
    shown++;
  }

  return 0;
}
