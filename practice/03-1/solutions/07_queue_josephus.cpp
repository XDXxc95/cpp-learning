// practice/03-1/solutions/07_queue_josephus.cpp — 参考答案：报数出列（约瑟夫环）
#include <iostream>
#include <queue>

int main() {
  int n, k;
  std::cin >> n >> k;

  std::queue<int> q;
  for (int i = 1; i <= n; i++)
    q.push(i); // 初始：1..n 围成一圈

  int count = 0; // 当前报到第几号
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    count++;
    if (count == k) {
      std::cout << cur << " "; // 报到 k，出列（不再放回）
      count = 0;               // 下一个人重新从 1 报数
    } else {
      q.push(cur); // 没报到 k，放回队尾 → 模拟「绕圈」
    }
  }
  std::cout << "\n";
  return 0;
}
// 思路：queue 天然模拟「围成一圈」——队头报数，没出列就绕到队尾继续。
