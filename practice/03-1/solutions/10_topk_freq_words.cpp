// practice/03-1/solutions/10_topk_freq_words.cpp — 参考答案：前 K 高频词（堆解法，LeetCode 347 思路）
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

// 自定义比较器：返回 true 表示 a 的优先级比 b 低（a 更晚出队）
// priority_queue 的 top 是「按 comp 排序时排最后」的那个
struct Compare {
  bool operator()(const std::pair<std::string, int>& a,
                  const std::pair<std::string, int>& b) const {
    if (a.second != b.second)
      return a.second < b.second; // 次数少 → 优先级低
    return a.first > b.first;     // 次数相同 → 字典序大 → 优先级低
  }
};

int main() {
  std::string line;
  std::getline(std::cin, line);

  // 1. unordered_map 统计词频（平均 O(1) 插入）
  std::unordered_map<std::string, int> freq;
  std::istringstream iss(line);
  std::string word;
  while (iss >> word)
    freq[word]++;

  // 2. 全部倒进 priority_queue，自定义比较器让「次数多、字典序小」先出
  std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>,
                      Compare>
      pq;
  for (const auto& kv : freq)
    pq.push(kv);

  // 3. 取前 3 个
  int shown = 0;
  while (!pq.empty() && shown < 3) {
    std::cout << pq.top().first << " " << pq.top().second << "\n";
    pq.pop();
    shown++;
  }
  return 0;
}
