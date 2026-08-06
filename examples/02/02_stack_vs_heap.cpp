// examples/02/02_stack_vs_heap.cpp — 栈与堆：地址与生命周期
// Stack vs heap: addresses and lifetimes
// 每次运行地址值不同，关注的是：
//   ① 三类变量（静态/栈/堆）落在不同地址区间，互不重叠
//   ② 递归调用时栈地址逐层递减（栈向下生长）
//   ③ 相邻分配的堆地址递增（堆向上生长）
// 教科书常画「栈最高、堆中间、静态最低」——那是 Linux 布局；
// Windows 上静态区往往在高地址。记住规律，别背数字。
#include <iostream>

int g_global = 1;        // 全局变量：静态存储区 | static storage
static int g_static = 2; // 文件内 static：同样在静态存储区

// 递归观察栈：每层调用产生新的局部变量，地址逐层"下降"（栈向下生长）
void showStack(int depth) {
  int local = depth * 10;
  std::cout << "  depth " << depth << ": &local = " << &local << "\n";
  if (depth < 3) {
    showStack(depth + 1);
  }
  // depth 3 返回后，depth 2 的 local 还活着（地址复用同一位置）
}

int main() {
  int local_a = 100;                // 栈上 | on the stack
  int local_b = 200;

  int* heap_a = new int(1000);      // 堆上 | on the heap
  int* heap_b = new int(2000);

  std::cout << "--- addresses ---\n";
  std::cout << "&g_global = " << &g_global << "  (static)\n";
  std::cout << "&g_static = " << &g_static << "  (static)\n";
  std::cout << "&local_a  = " << &local_a << "  (stack)\n";
  std::cout << "&local_b  = " << &local_b << "  (stack)\n";
  std::cout << "heap_a    = " << heap_a << "  (heap)\n";
  std::cout << "heap_b    = " << heap_b << "  (heap)\n";

  std::cout << "\n--- stack grows downward (recursion) ---\n";
  showStack(0);

  std::cout << "\n--- heap memory must be freed by hand ---\n";
  delete heap_a;
  // heap_a 现在是悬垂指针：不要再解引用它（例 04 详解）
  delete heap_b;
  std::cout << "done\n";
  return 0;
}
