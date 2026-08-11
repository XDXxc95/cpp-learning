// practice/03/04_frequency.cpp — M3 练习4：map 频率统计
// 输入：第一行 n，第二行 n 个整数（可能重复）
// 输出：每个数出现次数，按键升序「数 次数」，每行一个
// 示例：6 / 3 1 3 1 3 2 → 1 2 / 2 1 / 3 3
// 注释里回答（两个问题）：
//   ① 为什么输出天然就是升序的？（提示：map 内部怎么存的） 红黑树会自动更新节点顺序，int是基础类型，就会按照大小排好顺序。string就会触发字典排序。
//   ② 用 freq[x]++ 时，如果 x 第一次出现（键不存在），会发生什么？（提示：[] 找不到会怎样） 会在map中默认增加一个值，key是x,value 是value的默认值。
#include <iostream>
#include <map>

int main() {

  int n = 0;
  std::cin >> n;

  std::map<int, int> countMap;
  for (int i = 0; i < n; i++) {
    int input = 0;
    std::cin >> input;
    countMap[input]++;
  }

  for (const auto& iter : countMap) {
    std::cout << iter.first << " " << iter.second << "\n";
  }

  return 0;
}
