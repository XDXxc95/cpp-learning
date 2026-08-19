// practice/03-1/05_unordered_set_dedup.cpp — 练习 5：unordered_set 去重 + 存在性
//
// 题目：
//   输入第一行 n，第二行 n 个整数（可能重复），第三行一个 target。
//   用 std::unordered_set 去重，然后：
//     1. 打印去重后元素个数和所有元素（顺序随意，能看到乱序就行）
//     2. 判断 target 在不在集合里，输出 "target in" 或 "target not in"
//   示例：输入 6 / 3 1 3 2 1 4 / 3 → 输出 4 个元素 + "3 in"。
//
// 注释里回答：
//   对比 M3 练习 5 的 set 版——什么时候该用 set、什么时候用 unordered_set？
// 需要有序遍历、升序输出或前驱/后继查询时用 set，复杂度通常为 O(log n)；
// 只需要去重和存在性判断、不关心顺序时用 unordered_set，平均复杂度为 O(1)。
// 完整题目见 practice/03-1/exercises.md；先自己写，再对照 solutions/05_unordered_set_dedup.cpp
#include <iostream>
#include <unordered_set>

int main() {
  int n = 0;
  std::cin >> n;

  std::unordered_set<int> us;
  for (int i = 0; i < n; i++) {
    int input = 0;
    std::cin >> input;
    us.insert(input);
  }

  int target = 0;
  std::cin >> target;

  std::cout << "dedup count=" << us.size() << ": ";

  for (const auto& it : us) {
    std::cout << it << " ";
  }
  std::cout << "\n";

  bool in = us.find(target) != us.end();

  if (in) {
    std::cout << target << " in" << "\n";
  } else {
    std::cout << target << " not in" << "\n";
  }

  return 0;
}
