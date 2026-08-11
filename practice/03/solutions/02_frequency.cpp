// practice/03/solutions/02_frequency.cpp — 参考答案：map 频率统计
#include <iostream>
#include <map>

int main() {
  int n = 0;
  std::cin >> n;

  std::map<int, int> freq;
  for (int i = 0; i < n; i++) {
    int x = 0;
    std::cin >> x;
    freq[x]++;   // 键不存在时自动插入默认值 0，再自增 → 统计出现次数
  }

  // map 内部按键升序存储（红黑树中序遍历），所以输出天然升序
  for (auto& kv : freq) {
    std::cout << kv.first << " " << kv.second << "\n";
  }
  return 0;
}
