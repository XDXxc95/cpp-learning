// practice/03-1/solutions/08_topk_largest.cpp — 参考答案：前 K 大（最小堆 size=k）
#include <functional> // std::greater
#include <iostream>
#include <queue>
#include <vector>

int main() {
  int n, k;
  std::cin >> n >> k;

  // 做法 b（推荐）：维护大小为 k 的【最小堆】，比堆顶（当前第 k 大）大才替换
  std::priority_queue<int, std::vector<int>, std::greater<int>> topk;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    if (topk.size() < static_cast<std::size_t>(k)) {
      topk.push(x);
    } else if (x > topk.top()) {
      topk.pop();
      topk.push(x);
    }
  }

  // 堆里就是最大的 k 个（最小堆按升序吐出）
  while (!topk.empty()) {
    std::cout << topk.top() << " ";
    topk.pop();
  }
  std::cout << "\n";
  return 0;
}
// 做法 a（备选）：全部入默认最大堆，pop k 次。O(n log n)。
// 注释回答：做法 a O(n log n)（所有元素都入堆），做法 b O(n log k)（堆一直保持 k 个）。
// n=10⁶、k=10 时，b 大约 10⁶×log10 ≈ 3.3M 次比较，a 是 10⁶×log(10⁶) ≈ 20M 次——
// b 只关心前 K，不排序无关元素，明显更省。
