// practice/03-1/01_unordered_freq.cpp — 练习 1：unordered_map 频率统计
//
// 题目：
//   输入第一行 n，第二行 n 个整数（可能重复）。
//   用 std::unordered_map<int, int> 统计每个数出现次数，按【任意顺序】输出「数 次数」，每行一个。
//   示例：输入 6 / 3 1 3 1 3 2 → 输出 1 2 / 2 1 / 3 3（顺序随意）。
//
// 注释里回答：
//   和 M3 练习 4 的 map 版本相比，输出顺序为什么可能不一样？把 unordered_map 换回 map 会怎样？
//   a:因为unordered_map 的 key 使用了 hash，会计算key的hash，直接放置，不会像map要更新红黑树节点 复杂度近似O(1) vs O(nlog)。换回map就有升序了。
//
// 完整题目见 practice/03-1/exercises.md；先自己写，再对照 solutions/01_unordered_freq.cpp
#include <iostream>
#include <unordered_map>

int main() {
  int n = 0;
  std::cin >> n;

  std::unordered_map<int, int> m;

  for (int i = 0; i < n; i++) {
    int input = 0;
    std::cin >> input;
    m[input]++;
  }

  for (const auto& i : m) {
    std::cout << i.first << " " << i.second << "\n";
  }

  return 0;
}
