// 04_class_basics.cpp — 类与对象：构造、封装、const 成员函数
// Classes: construction, encapsulation, const member functions
#include <iostream>
#include <string>

class Counter {
public:
    // 构造函数 constructor（初始化列表 initialization list）
    Counter(std::string name, int start) : name_(name), count_(start) {}

    void increment() { ++count_; }

    // const 成员函数：承诺不修改对象状态
    int value() const { return count_; }

    void report() const {
        std::cout << name_ << " count=" << count_ << std::endl;
    }

private:
    std::string name_;   // 私有成员 private members —— 外部不可直接访问
    int         count_;
};

int main() {
    Counter c("app", 10);
    c.increment();
    c.increment();
    c.report();                    // app count=12

    Counter d("db", 0);
    d.report();                    // db count=0

    // c.count_ = 99;  // 编译错误：count_ 是私有成员 cannot access private member
    std::cout << "c.value()=" << c.value() << std::endl;
    return 0;
}
