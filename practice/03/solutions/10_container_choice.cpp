// practice/03/solutions/10_container_choice.cpp — 参考答案：容器选型
//
// 场景 A：需要快速判断「某个数在不在集合里」，且希望集合自动排好序
//   → std::set：插入/查找/删除都 O(log n)，自动升序（红黑树）。
//     若要支持「排序后二分」，也可 vector + sort + binary_search。
//
// 场景 B：统计每个单词出现次数，想按键（字典序）遍历输出
//   → std::map<std::string, int>：freq[word]++ 自动插入默认值，按键升序遍历。
//     （只计数不要求有序时用 unordered_map 更快，本模块先掌握 map。）
//
// 场景 C：长度运行时才知的动态数组，只往末尾加、要按下标随机访问
//   → std::vector：push_back 均摊 O(1)，按下标访问 O(1)，自动管理内存——
//     正是不用手动 new[]/delete[] 的原因（对比 M2）。
//
// 场景 D：频繁拼接、查找子串、按行读入文字
//   → std::string：+ 拼接、find + std::string::npos 判断、substr、getline 读整行。
//
// 场景 E：一组可能重复的数去重，数量不小，还要二分查找
//   → 集合语义用 std::set（去重 + 有序，成员 find 是 O(log n)）；
//     但 set 迭代器不是随机访问，binary_search 用不了——更常见的写法是
//     vector 收集 → sort → unique 原地去重 → binary_search 查找。
//
// 核心口诀：按键要排序 → map/set；只要顺序/下标 → vector；纯文本 → string。
#include <iostream>

int main() {
  std::cout << "选型答案全在文件顶部注释里（容器 + 理由 + 复杂度）。\n";
  return 0;
}
