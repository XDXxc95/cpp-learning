// examples/03/03_map_set.cpp — map / set：有序关联容器，查找 O(log n)
// map / set: ordered associative containers, lookup O(log n)
#include <iostream>
#include <map>
#include <set>
#include <string>

int main() {
  // map：键 → 值，按键升序存储
  std::map<std::string, int> score;
  score["Alice"] = 90;
  score["Bob"] = 85;
  score["Alice"] = 95;      // 同键覆盖 → Alice 现在是 95

  // 遍历：按键升序；元素是 pair，用 first / second 取键和值
  for (auto& kv : score) {
    std::cout << kv.first << ": " << kv.second << "\n";
  }

  // 存在性检查：map[key] 找不到时会【自动插入默认值】，所以判断存在要用 count/find
  std::cout << "count(Bob)=" << score.count("Bob") << "\n";   // 1
  std::cout << "count(Tom)=" << score.count("Tom") << "\n";   // 0
  auto it = score.find("Tom");
  if (it == score.end()) {
    std::cout << "Tom not found\n";
  }

  // set：只有键，天然去重 + 有序
  std::set<int> s;
  int a[] = {3, 1, 4, 1, 5, 9, 2, 6};
  for (int x : a) s.insert(x);          // 重复的 1 只留一个
  std::cout << "set size=" << s.size() << " (去重后) : ";
  for (int x : s) std::cout << x << " ";   // 升序输出
  std::cout << "\n";
  std::cout << "set has 4? " << (s.count(4) > 0) << "\n";

  return 0;
}
