// practice/03/solutions/01_vector_warmup.cpp — 参考答案：vector 最小操作
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v;
  for (int x : {10, 20, 30}) {
    v.push_back(x);
    std::cout << "after push: size=" << v.size() << " cap=" << v.capacity()
              << "\n";
  }

  std::cout << "size=" << v.size() << " first=" << v[0] << "\n";

  std::cout << "all: ";
  for (int x : v) std::cout << x << " ";
  std::cout << "\n";
  // 扩容真相：size 1→2→3 时 cap 1→2→4（翻倍），push_back 均摊 O(1)
  return 0;
}
