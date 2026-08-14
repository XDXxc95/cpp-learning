// practice/03-1/07_queue_josephus.cpp — 练习 7：报数出列（queue 约瑟夫环）
//
// 题目：
//   经典约瑟夫环：n 个人从 1 到 n 编号围成一圈，从 1 开始报数，报到 k 的人出列，
//   下一个人从 1 重新报数，直到所有人出列。
//   用 queue 模拟（每轮）：
//     - 队头出队，作为「报数」的这个人
//     - 没报到 k → 重新放回队尾（轮到后面再报）
//     - 报到 k → 打印出列，不再放回
//   输入：第一行 n k。输出：出列顺序，空格分隔。
//   示例：输入 5 3 → 输出 3 1 5 2 4。
//
// 完整题目见 practice/03-1/exercises.md；先自己写，再对照 solutions/07_queue_josephus.cpp
#include <iostream>
#include <queue>

int main() {
  // TODO: 你的实现
  return 0;
}
