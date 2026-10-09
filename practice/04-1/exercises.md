# M4-1 练习 · 面向对象核心

> 规则：**先自己写，再对照** `practice/04-1/solutions/`。全部完成后填文末自评表。
> 所有练习文件在 `practice/04-1/` 下，命名 `NN_主题.cpp`，用 `tools/compile.sh` 编译运行。
> 练习文件是**空骨架**，你往里面填实现。
> **建议顺序**：按 A → B → C 分层推进；每层做完可先对照答案，再进下一层。

## A 区 · 基础热身 Basic Warm-up

> 目的：把继承/虚函数/抽象类「各跑通一遍」求手感，题很小，重点是看清输出。

### 练习 1 · 继承与访问控制 | inheritance & access control

文件：`practice/04-1/01_inheritance_access.cpp`

1. 基类 `Person`：`protected std::string name_`、`private int age_`、`public void greet() const`（打印 `Hi, I'm <name_>`）
2. 派生类 `Student : public Person`：构造函数接受 name 和 age，另有 `void study() const`（打印 `<name_> is studying`）

在 `main` 里创建一个 `Student`，调用 `greet()`（继承来的）和 `study()`。

注释里回答：
- `Student::study()` 里能直接读 `name_` 吗？能读 `age_` 吗？各为什么？
- `main` 里能写 `s.name_` 吗？能写 `s.age_` 吗？各为什么？

### 练习 2 · 构造 / 析构顺序 | construction & destruction order

文件：`practice/04-1/02_ctor_dtor_order.cpp`

定义三层继承链 `A → B → C`（`B : public A`，`C : public B`），每层的构造函数和析构函数都打印自己的类名，例如 `A ctor` / `A dtor`。

在 `main` 里写一个作用域 `{ C c; }`，观察输出。

注释里回答：
- 构造顺序是什么？析构顺序是什么？
- 两者为什么是**逆序**关系？（提示：想想「先建好的后拆」）

### 练习 3 · virtual 覆盖初体验 | first virtual override

文件：`practice/04-1/03_virtual_override.cpp`

1. 基类 `Animal`：`virtual void speak() const` 打印 `generic animal sound`
2. 派生 `Dog`：`void speak() const override` 打印 `Woof!`
3. 派生 `Cat`：`void speak() const override` 打印 `Meow!`
4. 写一个自由函数 `void makeSpeak(const Animal& a)`，函数体只有 `a.speak();`

在 `main` 里对 `Dog` 和 `Cat` 各调一次 `makeSpeak()`。

注释里回答：
- 为什么 `makeSpeak` 函数体写死了 `a.speak()`，却分别输出了 `Woof!` 和 `Meow!`？
- 如果把基类的 `virtual` 关键字**删掉**，输出会变成什么？为什么？

### 练习 4 · 抽象类与纯虚函数 | abstract class & pure virtual

文件：`practice/04-1/04_abstract_shape.cpp`

1. 抽象类 `Shape`：
   - `virtual double area() const = 0;`
   - `virtual const char* name() const = 0;`
   - `virtual ~Shape() = default;`
2. 派生 `Circle`（半径 `r`）和 `Square`（边长 `s`），各自实现两个纯虚函数

在 `main` 里用 `Shape*` 数组装这两个对象（栈上对象取地址），循环打印名字和面积。

注释里回答：
- `Shape s;` 为什么编译不过？
- 如果 `Square` 只实现了 `area()` 而没实现 `name()`，会发生什么？它自己能创建对象吗？

## B 区 · 核心应用 Core

> 目的：每个知识点对应刷题/工程里的典型用法。

### 练习 5 · 多态求总面积 | polymorphic total area

文件：`practice/04-1/05_poly_total_area.cpp`

`Shape` 基类（`virtual double area() const`，非纯虚，给个 `return 0;` 的默认实现），派生 `Circle`、`Rect`、`Triangle`。

用 `std::vector<Shape*>` 装齐三个对象（栈上对象取地址），遍历求**总面积**并打印，再打印**面积最大**的图形的名字。

注释里回答：
- 如果把基类 `area()` 的 `virtual` 去掉，总面积会变成多少？为什么？
- 这里的调用点只写了 `s->area()`，编译器怎么知道该算谁的？

### 练习 6 · 虚析构与内存泄漏 | virtual destructor & leak

文件：`practice/04-1/06_virtual_dtor.cpp`

1. 写 `BadBase`（**非虚**析构）和 `BadDerived`：`BadDerived` 构造里 `new int[100]`，析构里 `delete[]` 并打印 `~BadDerived`（`BadBase` 析构也打印）
2. 在 `main` 里 `BadBase* p = new BadDerived; delete p;`，观察哪些析构跑了
3. 复制一份改成 `GoodBase`（**虚**析构）/ `GoodDerived`，同样操作，再观察

注释里回答：
- 第 2 步输出了哪些析构？哪个没跑？泄漏了什么？
- 编译器对第 2 步的 `delete` 有没有告警？告警名字里的关键字是什么？
- 修复办法是什么（一个字）？

### 练习 7 · override 与 final | override & final

文件：`practice/04-1/07_override_final.cpp`

1. 基类 `Base` 有 `virtual void f() const` 和 `virtual void g()`
2. 派生 `Derived : public Base`，用 `override` 正确覆盖 `f()` 和 `g()`
3. 演示两种 `final`：一个 `final` 的类、一个 `final` 的函数

注释里写清楚：
- `override` 帮你防住了什么错误？给一个**具体例子**（比如派生类漏写 `const` 会怎样）
- 把「取消注释就会编译报错」的那几行代码**以注释形式**写在 `main` 或类定义处，并标注错误原因

### 练习 8 · 对象切片 | object slicing

文件：`practice/04-1/08_slicing.cpp`

1. 基类 `Animal`：`virtual std::string kind() const` 返回 `"Animal"`；派生 `Dog`：额外成员 `std::string breed_`，`kind()` 返回 `"Dog/" + breed_`
2. 写两个函数：`void byValue(Animal a)` 和 `void byRef(const Animal& a)`，都打印 `a.kind()`
3. 在 `main` 里各调一次，比较输出
4. 再对比 `std::vector<Animal>`（`push_back` 一个 `Dog`）和 `std::vector<Animal*>`（`push_back` `&dog`）打印 `kind()`

注释里回答：
- 切片的**本质**是什么？（提示：拷贝了什么？丢了什么？）
- 为什么引用/指针不会切片？
- 容器里想放多态对象，应该存什么？

### 练习 9 · 虚函数对被调用的代价 | the cost of virtual

文件：`practice/04-1/09_vptr_size.cpp`

1. 定义 `Plain`：两个 `int` 成员，无虚函数
2. 定义 `Poly`：两个 `int` 成员 + 一个 `virtual void f() const`
3. 用 `sizeof` 打印两者的字节数，以及一个 `int*` 的大小作为参照

注释里回答：
- 两者的 `sizeof` 差多少？这个差值是什么？
- 为什么加了 `virtual` 对象会变大？（提示：虚函数表 / vptr）
- 由此推论：什么时候**不该**给函数加 `virtual`？

## C 区 · 综合 · 学后练习 Capstone

> 目的：把本模块知识串起来，题型贴近实际设计。

### 练习 10 · 简易图形清单系统 | shape inventory system

文件：`practice/04-1/10_shape_system.cpp`

设计一个小系统，把本模块的全部要点串起来：

1. **抽象基类** `Shape`：
   - `virtual double area() const = 0;`
   - `virtual double perimeter() const = 0;`
   - `virtual const char* name() const = 0;`
   - `virtual ~Shape() = default;` ← 注意这里
2. **三个派生类** `Circle`（半径）、`Rectangle`（宽高）、`Triangle`（三边，周长 = 三边和；面积用海伦公式）
3. 在 `main` 里：
   - 用 `new` 创建若干图形，放进 `std::vector<Shape*>`
   - 遍历打印每个图形的 `name` / `area` / `perimeter`
   - 打印**总面积**和**面积最大**的图形名字
   - 最后循环 `delete` 释放，**验证每个派生类的析构都执行了**（在派生类析构里打印一行）

示例输出形状（数值自己算）：

```text
circle  area=12.5664  perimeter=12.5664
rect    area=12       perimeter=14
tri     area=6        perimeter=12
total area = 30.5664
largest = circle
[dtor] Circle
[dtor] Rectangle
[dtor] Triangle
```

注释里回答：
- 为什么这里 `~Shape()` 必须是 `virtual`？如果写成非虚，最后那三行 `[dtor]` 会少哪些？
- 为什么容器是 `std::vector<Shape*>` 而不是 `std::vector<Shape>`？
- 海伦公式：已知三边 `a,b,c`，半周长 `s=(a+b+c)/2`，面积 `sqrt(s(s-a)(s-b)(s-c))`（需要 `<cmath>`）

## 自评表 Self-Assessment

| 项目 | ✅ 熟练 | 🔶 基本掌握 | ❌ 薄弱 |
| --- | --- | --- | --- |
| 继承语法与访问控制（`public` 继承、`protected`/`private` 可见性） | | | |
| 构造 / 析构顺序（基类 → 派生类，析构逆序） | | | |
| `virtual` 与动态绑定（基类指针/引用调用） | | | |
| 纯虚函数与抽象类（接口设计） | | | |
| 虚析构函数（为什么必须 `virtual`） | | | |
| 对象切片与 `override` / `final` | | | |
| 多态 + 指针容器的综合运用 | | | |

填完把结果发给 Claude，全 ✅ → 收官 M4-1 → 进 M4-2 拷贝控制。
