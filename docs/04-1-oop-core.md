# M04-1 · 面向对象核心 | OOP Core: Inheritance & Polymorphism

> 目标 Goals：掌握 C++ 面向对象的三大支柱——**继承（inheritance）**、**多态（polymorphism）**、**封装**中的前两者在 C++ 里的具体机制：`public` 继承、`virtual` 动态绑定、纯虚函数与抽象类、虚析构函数、对象切片 ｜ 预计 Est.：3~4 小时 ｜ 难度：★★★
>
> M2 讲过「栈与堆、new/delete、内存错误」，练习 2 里你已经抓过泄漏和悬垂。本模块的**虚析构函数**一节会把那条线接上——**多态 + 非虚析构 = 静默内存泄漏**，这是最经典的一类 C++ bug。多态也是设计模式（工厂、策略、观察者）和几乎所有 C++ 面试题的地基。

## 本节要点 Key Points

- **继承**：`class Dog : public Animal`——`Dog`(派生类 derived) 复用 `Animal`(基类 base) 的成员；构造顺序**基类 → 成员 → 派生类**，析构**完全相反**
- **多态**：通过**基类指针/引用**调用 `virtual` 函数时，实际执行的是**对象真实类型**那一版（动态绑定 dynamic binding）
- **纯虚函数** `virtual double area() const = 0;` → 该类成为**抽象类**（abstract class），不能实例化，只能当接口用
- **虚析构函数**：只要类可能被**通过基类指针 delete**，基类析构函数就必须 `virtual`，否则派生类析构不执行 → 泄漏
- **对象切片** object slicing：按值传递/按值存进容器会把派生类对象「切」成基类，多态失效——必须用指针或引用
- `override` 让编译器替你检查「确实覆盖了基类虚函数」，拼错函数签名的救命符；`final` 禁止继续覆盖/继承

## 正文 Body

### 1. 继承基础 Inheritance Basics（examples/04-1/01_*）

继承表达 **is-a（是一种）** 关系：`Dog` 是一种 `Animal`。

```cpp
class Animal {
 public:
  Animal(const std::string& n) : name_(n) {}   // 基类构造函数
  void breathe() const { std::cout << name_ << " breathes\n"; }
 protected:
  std::string name_;   // protected：派生类能访问，外界不能
};

class Dog : public Animal {                    // public 继承
 public:
  // 派生类构造函数必须在【初始化列表】里调用基类构造函数
  Dog(const std::string& n) : Animal(n) {}
  void fetch() const { std::cout << name_ << " fetches\n"; }  // 能访问 name_
};

Dog d("Rex");
d.breathe();   // 继承自 Animal，直接用
d.fetch();     // Dog 自己的
```

**三种继承方式**决定基类成员在派生类里的可见性（刷题/工程里 99% 用 `public`）：

| 基类中的成员 | `public` 继承 | `protected` 继承 | `private` 继承 |
| --- | --- | --- | --- |
| `public` | `public` | `protected` | `private` |
| `protected` | `protected` | `protected` | `private` |
| `private` | **不可访问** | **不可访问** | **不可访问** |

⚠️ 基类的 `private` 成员，**任何继承方式下派生类都访问不到**（只能通过基类的 public/protected 成员函数间接碰）。

**三种访问修饰符**（和继承方式不是一回事）：

| 修饰符 | 本类内部 | 派生类 | 外界/其他代码 |
| --- | --- | --- | --- |
| `public` | ✅ | ✅ | ✅ |
| `protected` | ✅ | ✅ | ❌ |
| `private` | ✅ | ❌ | ❌ |

**构造 / 析构顺序**（必考，也是练习 1 的重点）：

```text
构造： 基类构造 → 成员变量构造（按声明顺序）→ 派生类构造体
析构： 派生类析构 → 成员变量析构 → 基类析构     （完全逆序）
```

口诀：**构造从外到内（先父后子），析构从内到外（先子后父）**。像剥洋葱——先在里层建好，再从外层拆掉。

### 2. 虚函数与多态 Virtual Functions & Polymorphism（examples/04-1/02_*）

**这是本模块的核心。** 先看「不加 virtual」会发生什么：

```cpp
class Animal {
 public:
  void speak() const { std::cout << "generic sound\n"; }   // 没有 virtual
};
class Dog : public Animal {
 public:
  void speak() const { std::cout << "Woof\n"; }
};

Dog d;
Animal* p = &d;    // 基类指针指向派生类对象（合法：Dog is-a Animal）
p->speak();        // 输出 generic sound —— 不是 Woof！
```

为什么？因为**没有 `virtual` 就是静态绑定（static binding）**：编译器只看指针的**声明类型**（`Animal*`），在编译期就定死了调用 `Animal::speak`。

加上 `virtual` 就变成**动态绑定（dynamic binding）**——运行期看**对象的真实类型**：

```cpp
class Animal {
 public:
  virtual void speak() const { std::cout << "generic sound\n"; }   // virtual
  virtual ~Animal() = default;                                     // 顺带：析构也 virtual，见第 4 节
};
class Dog : public Animal {
 public:
  void speak() const override { std::cout << "Woof\n"; }           // override 让编译器检查
};

Dog d;
Animal& r = d;      // 基类引用
r.speak();          // Woof！—— 动态绑定，按对象真实类型 Dog 调用

std::vector<Animal*> zoo{&d};
zoo[0]->speak();    // Woof
```

**多态的三要素**（缺一不可，练习 2 会让你刻意破坏每一个来观察）：

1. 基类里有 `virtual` 函数
2. 派生类**覆盖（override）**了它（签名必须一致）
3. 通过**基类指针或引用**调用（用对象本身调用永远是静态绑定）

**`override` 关键字（C++11）**：写在派生类函数后面，让编译器验证「确实覆盖了某个基类虚函数」。签名写错（比如漏了 `const`）时，编译器直接报错，而不是悄悄地变成一个新函数——**强烈建议每个覆盖都写**。

```cpp
class Dog : public Animal {
 public:
  void speak() override;          // ✅ 编译器检查
  // void speak();                // ❌ 漏 const → 编译报错（否则会静默变成新函数，多态失效）
};
```

**`final` 关键字**：修饰函数 → 禁止再被覆盖；修饰类 → 禁止被继承。

```cpp
class Dog : public Animal {
 public:
  void speak() const final;   // 再有人覆盖它就报错
};
class Puppy final : public Dog { };   // 再有人继承 Puppy 就报错
```

底层实现是**虚函数表（vtable）**：每个含虚函数的类有一张函数指针表，对象里藏一个指向它的指针（`vptr`）。调用虚函数 = 运行时通过 vptr 查表。**代价**：每个对象多一个指针（64 位上 8 字节）+ 一次间接跳转，所以不是所有函数都该加 `virtual`。

### 3. 纯虚函数与抽象类 Pure Virtual & Abstract Class（examples/04-1/03_*）

```cpp
class Shape {
 public:
  virtual double area() const = 0;     // = 0 → 纯虚函数：只声明，不给实现
  virtual void draw() const = 0;
  virtual ~Shape() = default;          // 有虚函数的基类，析构也要 virtual
};

// Shape s;          // ❌ 编译错误：抽象类不能创建对象
// Shape* p;         // ✅ 指针/引用可以

class Circle : public Shape {
 public:
  explicit Circle(double r) : r_(r) {}
  double area() const override { return 3.14159265358979 * r_ * r_; }  // 必须实现
  void draw() const override { std::cout << "circle r=" << r_ << "\n"; }
 private:
  double r_;
};
```

规则：

- 含**至少一个纯虚函数**的类 = **抽象类（abstract class）**，不能实例化。
- 派生类**必须实现所有纯虚函数**，才能创建对象（漏一个 → 它自己也是抽象类）。
- 纯虚函数**可以有实现体**（`virtual void f() = 0;` 然后在类外给定义），派生类仍必须覆盖——少见，知道即可。
- 抽象类的作用就是**定义接口（interface）**：只规定「能做什么」，不管「怎么做」。这就是设计模式里「面向接口编程」的基础。

### 4. 虚析构函数 Virtual Destructor（examples/04-1/03_*）

**接上 M2 的内存管理。** 看这个 bug：

```cpp
class Base {
 public:
  ~Base() { std::cout << "~Base\n"; }        // ⚠️ 非虚析构
};
class Derived : public Base {
 public:
  Derived() : buf_(new int[100]) {}
  ~Derived() { delete[] buf_; std::cout << "~Derived\n"; }
 private:
  int* buf_;
};

Base* p = new Derived;
delete p;    // ⚠️ 只输出 ~Base！~Derived 根本没执行 → buf_ 泄漏
```

`delete p` 时 `p` 的声明类型是 `Base*`，析构函数**不是虚函数**→ 静态绑定 → 只调用 `~Base()`，派生类的析构被跳过，`buf_` 永远泄漏。**这就是 M2 练习 2 里那类泄漏的「多态版」。**

**好消息**：GCC/Clang 对**直接**的 `delete p` 会给出警告（`-Wall` 就带，本项目 `-Wall -Wextra` 已开启）：

```text
warning: deleting object of polymorphic class type 'Base' which has
non-virtual destructor might cause undefined behavior [-Wdelete-non-virtual-dtor]
```

**别把这条警告压掉**——它就是在提醒你「这里少了个 `virtual`」。但**也不能拿它当兜底**：警告只在编译器能看穿 `delete` 那一处的静态类型时才出现，走智能指针、藏在别的函数里、或类型被擦除时都可能不报。`examples/04-1/03_*` 为了把运行时后果演示完整，**刻意**用 `#pragma` 压掉了这一条（源码里有说明），真实项目里正确做法是**改基类析构为 `virtual`**。

修法只有一个字：

```cpp
class Base {
 public:
  virtual ~Base() = default;   // ✅ 现在 delete p 会先 ~Derived 再 ~Base
};
```

**经验法则（背下来）**：

> 只要一个类**有可能被通过基类指针删除**，它的析构函数就必须是 `virtual`。
> 更省事的判据：**基类只要有一个虚函数，析构函数就顺手写成 virtual**。

反过来：**不需要做基类的类，析构函数不要加 virtual**（白白多一个 vptr，还阻止对象被当平凡类型优化）。

### 5. 对象切片 Object Slicing（examples/04-1/04_*）

多态**只能通过指针或引用生效**。按值传递会把派生类对象「切」成基类：

```cpp
void describe(Animal a) {        // ⚠️ 按值传参
  a.speak();
}

Dog d;
describe(d);     // 调用的是 Animal::speak —— Dog 的部分被切掉了
```

发生过程：`Animal a = d;` 用基类拷贝构造，只复制「Animal 那部分」子对象，`Dog` 特有的数据成员和虚表指针全丢——多态彻底失效，而且**不报错**。

```cpp
void describe(const Animal& a) { a.speak(); }   // ✅ 引用：不拷贝，多态保留
describe(d);                                    // Woof
```

同样的坑还有：把派生类对象按值塞进 `std::vector<Animal>`（存的是切片后的副本）。**要多态就存指针**（`std::vector<Animal*>` 或 `std::unique_ptr<Animal>`，后者见 M5-1）。

### 6. 一张图收口 Putting It Together

```text
                    ┌─────────────┐
                    │   Shape     │  抽象类（含纯虚 area()）
                    │ virtual area│  ← 接口
                    └──────┬──────┘
                  ┌────────┴────────┐
            ┌─────┴─────┐     ┌─────┴─────┐
            │  Circle   │     │  Square   │  派生类，各自实现 area()
            └───────────┘     └───────────┘
                  ▲
                  │  通过 Shape* / Shape& 调用
        vector<Shape*> shapes;  →  shapes[i]->area()  动态绑定
```

- 基类 = 接口、派生类 = 实现
- 容器存**指针**、函数收**引用** → 多态才能生效
- 基类析构 `virtual` → 删指针时派生类析构才会跑

## 代码示例 Examples → `examples/04-1/`

| 文件 | 演示 |
| --- | --- |
| `01_inheritance_basic.cpp` | public 继承、protected 成员的可见性、构造/析构顺序（三层继承链打印） |
| `02_virtual_polymorphism.cpp` | **同一个调用，加不加 virtual 结果完全不同**——静态绑定 vs 动态绑定；`override` |
| `03_abstract_interface.cpp` | 纯虚函数 / 抽象类 / 接口；虚析构 vs 非虚析构——靠析构函数里的打印证明「派生类析构到底跑没跑」 |
| `04_slicing_and_override.cpp` | 对象切片（按值 vs 按引用）、`vector<Base>` vs `vector<Base*>`、`final` |

## 易错点 Common Pitfalls

1. **忘了 `virtual` → 多态静默失效**。基类函数加了 `virtual` 吗？是通过指针/引用调用的吗？两个都得满足。
2. **`override` 签名不一致**（最常见是漏 `const`）——不写 `override` 的话编译器不报错，多态悄悄失灵。**每个覆盖都写 `override`**。
3. **基类析构非虚 + 通过基类指针 delete = 派生类析构不执行 = 内存泄漏**。GCC/Clang 会用 `-Wdelete-non-virtual-dtor` 警告这种**直接** delete（`-Wall` 已含），但间接场景未必报——**看到这条警告就加 `virtual`，别压掉它**。基类有虚函数就顺手 `virtual ~Base() = default;`。
4. **按值传参导致对象切片**——多态参数一律 `const Base&`（或 `Base*`）。
5. **容器存值而非存指针**——`std::vector<Base>` 存进去的是切片副本；要多态用 `std::vector<Base*>`。
6. **构造函数里调虚函数不会多态**：此时派生类部分还没构造好，调用的永远是基类版本。构造函数/析构函数里别调虚函数。
7. **派生类构造函数忘记调基类构造**——不写的话编译器调基类的**默认构造函数**；基类没有默认构造 → 编译错误。
8. **`private` 基类成员在派生类里访问不到**，哪怕是 `public` 继承。需要给派生类用就改 `protected`。
9. **不要在不需要做基类的类上乱加 `virtual`**——每个对象多一个 vptr，且会影响结构体能否作为平凡类型（trivially copyable）使用。

## 练习 Exercises → `practice/04-1/exercises.md`

**10 道练习**，按「由浅入深」分三层推进（先自己写，再对照 `practice/04-1/solutions/`）：

- **A 热身 Basic**：① 单继承与 protected 可见性 ② 构造/析构顺序（三层继承链）③ 访问修饰符矩阵 ④ 手写一个 `virtual` 覆盖
- **B 核心 Core**：⑤ 多态面积求和（`Shape*` 容器，对比非虚版本）⑥ 抽象类接口 + 派生类实现 ⑦ 虚析构 vs 非虚析构（用析构计数器证明泄漏）⑧ `override` 与 `final` 的编译期保护 ⑨ 对象切片（按值 vs 按引用）
- **C 综合 Capstone**：⑩ 小型图形/动物园系统——抽象基类 + 多态 + 虚析构 + 指针容器串起来

做完填文末自评表，回来 review。

## 自测 Self-Check

- `public` / `protected` / `private` 三种**继承方式**，和三种**成员访问修饰符**，分别控制什么？基类的 `private` 成员派生类能碰到吗？
- 三层继承 `A → B → C`，`C c;` 的构造和析构顺序分别是什么？
- 「不加 `virtual` 通过基类指针调用」和「加了 `virtual`」结果为什么不同？分别叫什么绑定？
- 多态生效的三个必要条件是什么？缺一个会怎样？
- 为什么基类析构函数要写成 `virtual`？不写会发生什么（具体到内存）？
- 什么是对象切片？为什么 `void f(Base b)` 会切片而 `void f(const Base& b)` 不会？
- `override` 关键字解决了什么问题？不写它会踩什么坑？
- 什么时候**不该**把析构函数写成 `virtual`？
