// practice/03-1/08_topk_largest.cpp — 练习 8：前 K 大（priority_queue）
//
// 题目：
//   输入第一行 n k，第二行 n 个整数。输出最大的 k 个数（顺序随意即可，空格分隔逐个打印）。
//
//   两种做法任选（都练更好）：
//     - 做法 a（最大堆）：全部入默认堆，pop k 次。O(n log n)。
//     - 做法 b（最小堆，推荐）：维护大小为 k 的最小堆，比堆顶大才替换。O(n log k)。
//
// 注释里回答：
//   两种做法复杂度各是多少？n 很大而 k 很小（如 n=10^6, k=10）时，哪个更省？
//       a。O(n log n)。     b。O(n log k)。
// 完整题目见 practice/03-1/exercises.md；先自己写，再对照 solutions/08_topk_largest.cpp
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int main() {
  int n = 0, k = 0;
  std::cin >> n >> k;

  if (n <= 0 || k <= 0 || k > n) {
    return 0;
  }

  // std::priority_queue<int> qp;
  std::priority_queue<int, std::vector<int>, std::greater<int>> gp;

  for (int i = 0; i < n; i++) {
    int in = 0;
    std::cin >> in;

    // qp.push(in);

    if (gp.size() < static_cast<size_t>(k)) {
      gp.push(in);
    } else if (gp.top() < in) {
      gp.pop();
      gp.push(in);
    }
  }

  // for (int i = 0; i < k; i++) {
  //   std::cout << qp.top() << " ";
  //   qp.pop();
  // }
  // std::cout << "\n";

  while (!gp.empty()) {
    std::cout << gp.top() << " ";
    gp.pop();
  }
  std::cout << "\n";

  return 0;
}
