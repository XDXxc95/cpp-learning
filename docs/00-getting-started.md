# M00 · 环境与工作流 | Getting Started

> 目标 Goals：跑通「编译 → 运行 → 调试」全链路，学会发起一次学习会话 ｜ 预计 Est.：20 分钟 ｜ 难度：★☆☆

## 本节要点 Key Points

- 确认本机 C++ 工具链可用（g++ 7.3 + gdb）
- 学会用 `tools/compile.*` 一键编译运行
- 学会用 `tools/gdb.*` 进调试器
- 明白「Claude 生成内容、你写练习」的学习循环

## 环境 Environment

本项目的编译命令封装在 `tools/` 里，无需记复杂参数：

| 用途 | Git Bash | Windows cmd |
| --- | --- | --- |
| 编译 + 运行 | `tools/compile.sh 文件.cpp` | `tools\compile.bat 文件.cpp` |
| 编译 + 调试 | `tools/gdb.sh 文件.cpp` | `tools\gdb.bat 文件.cpp` |

内部实际执行的命令（可自行在脚本里查看/修改）：

```bash
g++ -std=c++17 -Wall -Wextra -g -o build/xxx.exe 源文件.cpp
```

- `-std=c++17`：C++17 标准（本工具链 g++ 16.1，完整支持 C++17/20/23，`<filesystem>` 也可用）
- `-Wall -Wextra`：打开警告，**警告是老师**
- `-g`：生成调试信息（gdb 用）

## 跑通第一个程序 First Run

```bash
tools/compile.sh examples/00-getting-started/hello.cpp
```

预期输出：

```text
==> 编译 Compiling: examples/00-getting-started/hello.cpp
==> 运行 Running: build/hello.exe
Hello, World!
year=2026 pi=3.14159 msg=C++ learning ready=1
==> 退出码 Exit code: 0
```

看到 `Hello, World!` 并且退出码为 0，环境正常 ✅

## 看一眼代码 Code Walkthrough

打开 `examples/00-getting-started/hello.cpp`：

```cpp
#include <iostream>   // 输入输出流 input/output stream
#include <string>     // std::string 字符串类 string class

int main() {                    // 主函数，程序入口 entry point
    std::cout << "Hello, World!" << std::endl;  // 输出到控制台
    int year = 2026;            // 整数 integer
    double pi = 3.1415926;      // 浮点数 floating-point
    std::string msg = "C++ learning";  // 字符串 string
    bool ready = true;          // 布尔 boolean
    std::cout << "year=" << year << " pi=" << pi
              << " msg=" << msg << " ready=" << ready << std::endl;
    return 0;                   // 返回 0 = 正常结束
}
```

观察点：`<<` 是流插入运算符（stream insertion operator），`std::` 是命名空间前缀（namespace），`endl` 是「换行并刷新」。

## 进入调试器 Try gdb

```bash
tools/gdb.sh examples/00-getting-started/hello.cpp
```

然后在 `(gdb)` 提示符下依次输入：

```text
break main      ← 在 main 入口设断点 breakpoint
run             ← 运行，会停在断点
info locals     ← 查看局部变量（此时还没赋值，是未初始化状态）
next            ← 单步执行下一行
print year      ← 打印变量 year 的值
quit            ← 退出
```

## 学习循环再强调一遍 The Loop

```text
你发起对话 → Claude 生成 文档/示例/练习（已验证可编译）
   → 你在 practice/ 亲手写练习
   → 回来 review → 进度更新 → 下一模块
```

M0 到这里就完成了。**下一步**：对 Claude 说「开始模块 M1 语法查漏补缺」，Claude 会生成一份自测题，帮你找出基础里的薄弱点。

## 易错点 Common Pitfalls

- 源码文件名不要带空格；输出文件名 = 源文件名去掉 `.cpp`。
- 编译失败时，先读**第一条**错误信息（通常就指向真正的问题）。
- `build/` 目录是编译产物，可以随时整个删掉，不影响源码。

## 自测 Self-Check

1. 不加 `-Wall -Wextra` 编译一个写了没用的变量，能看到警告吗？（提示：对比 `tools/compile.sh` 里的参数）
2. gdb 里 `info locals` 为什么显示的是未初始化值？（提示：断点停在 main 第 10 行时，代码还没执行到）
3. `std::cout` 里的 `std::` 去掉会怎样？试试。
