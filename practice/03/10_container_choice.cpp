// practice/03/10_container_choice.cpp — M3 练习10：容器选型设计题（学后收口）
// 目标：练「看到需求 → 选对容器」——刷题和面试的高频考点
// 对下面每个场景，在文件顶部的注释里写：用什么容器 + 为什么 + 大致复杂度
// 全部答案对照 practice/03/solutions/10_container_choice.cpp
//
//   场景 A：需要快速判断「某个数在不在集合里」，且希望集合自动排好序                 set 自动排序+自动去重 logn
//   场景 B：统计一段文字里每个单词出现次数，想按键（字典序）遍历输出                 map key为string，iterator默认字典序。 插入 logn ，n个就是 nlogn
//   场景 C：需要一个长度运行时才知道的动态数组，只往末尾加元素，要按下标随机访问      vector 运行时初始化，变长+idx访问。 1 扩容是 n
//   场景 D：要频繁拼接、查找子串、按行读入整段文字                                 string += append,find + npos， getline 
//   场景 E：把一组可能重复的数去重，数量不小，还要做二分查找                        set 去重+红黑树自动排序  logn  vector+sort+unique
#include <iostream>

int main() {
  // 本题不写实现逻辑，答案写在文件顶部的注释里，main 保持最小、能编译即可。
  std::cout << "选型设计题：答案写在注释里，对照 solutions/10_container_choice.cpp\n";
  return 0;
}
