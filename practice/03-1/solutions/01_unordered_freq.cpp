// practice/03-1/solutions/01_unordered_freq.cpp — 参考答案：unordered_map 频率统计
#include <iostream>
#include <unordered_map>

int main() {
  int n;
  std::cin >> n;
  std::unordered_map<int, int> freq;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    freq[x]++; // 首次遇到自动插默认值 0 再自增
  }
  // 输出顺序【不定】——哈希表的桶顺序决定，不是输入序、不是升序
  for (const auto& kv : freq) {
    std::cout << kv.first << " " << kv.second << "\n";
  }
  return 0;
}
// 注释回答：map 底层是红黑树，遍历天然升序；unordered_map 底层是哈希表，
// 元素按哈希值散落在不同桶里，遍历顺序由桶 + 哈希决定 → 每次运行都可能不同。
// 换回 map 后输出会变成升序，但查找从平均 O(1) 变成 O(log n)。
