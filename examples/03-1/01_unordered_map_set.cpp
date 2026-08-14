// examples/03-1/01_unordered_map_set.cpp — unordered_map/set：哈希表，平均 O(1) 查找
// unordered_map/set: hash-based, average O(1) lookup, but NO ordering
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

int main() {
  // unordered_map：用法和 map 几乎一样，底层是哈希表 → 平均 O(1) 查找
  std::unordered_map<std::string, int> freq;
  std::string words[] = {"apple", "banana", "apple", "cherry", "apple"};
  for (const std::string& w : words)
    freq[w]++; // 首次遇到自动插默认值 0 再自增

  std::cout << "frequency:\n";
  for (const auto& kv : freq) {
    std::cout << "  " << kv.first << ": " << kv.second << "\n";
  }
  // 注意：迭代顺序【不定】——由哈希决定，不保证输入序，更不是升序

  // 存在性检查：和 map 一样，[] 找不到会【自动插入默认值】，所以用 count/find
  std::cout << "count(apple)=" << freq.count("apple") << "\n"; // 1
  std::cout << "count(mango)=" << freq.count("mango") << "\n"; // 0

  // unordered_set：去重 + 平均 O(1) 存在性判断，但【无序】
  std::unordered_set<int> s;
  int a[] = {3, 1, 4, 1, 5, 9, 2, 6};
  for (int x : a)
    s.insert(x); // 重复的 1 只留一个
  std::cout << "set size=" << s.size() << "\n";
  std::cout << "has 4? " << s.count(4) << ", has 7? " << s.count(7) << "\n";
  // 去重后的顺序不定——想升序就换 std::set（M3 的 05_dedup 用过）

  return 0;
}
