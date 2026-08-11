// practice/03/solutions/07_iterators.cpp — 参考答案：迭代器专项
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> v;
  for (int i = 0; i < n; i++) {
    int x = 0;
    std::cin >> x;
    v.push_back(x);
  }

  // 1. 正向迭代器遍历（显式写出迭代器类型，体会它是「指向元素的指针式对象」）
  for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";

  // 2. distance 求长度 = n
  std::cout << "distance=" << std::distance(v.begin(), v.end()) << "\n";

  // 3. 左闭右开：end() 不指向任何元素，最后一个元素是 *(end()-1)
  std::cout << "last=" << *(v.end() - 1) << "\n";

  // 4. 反向迭代器倒序（auto 让代码更简洁）
  for (auto rit = v.rbegin(); rit != v.rend(); ++rit) {
    std::cout << *rit << " ";
  }
  std::cout << "\n";
  // 答：区间是 [begin, end) 左闭右开——end() 指向「最后一个元素之后」的哨兵位，
  //    不是合法元素，所以不能 <=（对它解引用是未定义行为）；而且对链表/哈希表这类
  //    迭代器比较大小无意义，!= 才是唯一通用的终止写法。
  return 0;
}
