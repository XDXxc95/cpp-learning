// 练习 4 参考答案 · 银行账户类
// Reference solution: BankAccount class with encapsulation
#include <iostream>
#include <string>

class BankAccount {
public:
    // 构造函数 constructor
    BankAccount(const std::string& owner, double initial_balance)
        : owner_(owner), balance_(initial_balance) {}

    // 存钱 deposit
    void deposit(double amount) {
        if (amount < 0) {  // 防御性：拒绝负数
            std::cout << "deposit rejected: amount < 0\n";
            return;
        }
        balance_ += amount;
    }

    // 取钱 withdraw：余额不足拒绝
    bool withdraw(double amount) {
        if (amount < 0) {
            std::cout << "withdraw rejected: amount < 0\n";
            return false;
        }
        if (amount > balance_) {
            std::cout << owner_ << " insufficient funds, need "
                      << amount - balance_ << " more\n";
            return false;
        }
        balance_ -= amount;
        return true;
    }

    // 查余额 query balance（const：不修改状态）
    double balance() const { return balance_; }

    // 打印账户 print account
    void report() const {
        std::cout << owner_ << " balance = " << balance_ << std::endl;
    }

private:
    std::string owner_;   // 私有：外部只能通过方法访问
    double      balance_;
};

int main() {
    BankAccount acc("Alice", 100.0);
    acc.deposit(50);
    acc.report();                       // Alice balance = 150

    bool ok1 = acc.withdraw(30);
    std::cout << "withdraw 30 ok=" << ok1 << std::endl;   // ok=1
    acc.report();                       // Alice balance = 120

    bool ok2 = acc.withdraw(500);
    std::cout << "withdraw 500 ok=" << ok2 << std::endl;  // ok=0（余额不足）
    acc.report();                       // 余额不变

    return 0;
}
