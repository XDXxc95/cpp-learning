// practice/01/04_bank_account.cpp — M1 练习4：银行账户类 BankAccount（封装）
#include <iostream>
#include <string>

class BankAccount {
  // 私有成员 private members：外部看不到、改不了
  std::string owner_;
  double balance_;

public:
  // 构造 constructor：初始化 owner_ 和 balance_
  BankAccount(const std::string &name, double initial_balance)
      : owner_(name), balance_(initial_balance) {}
  // 存钱 deposit
  void deposit(double amount) {
    // TODO: balance_ += amount
    balance_ += amount;
  }

  // 取钱 withdraw：余额不足则打印错误并拒绝
  void withdraw(double amount) {
    // TODO:
    //  if (amount > balance_) 打印错误并直接 return（拒绝）
    //  else balance_ -= amount
    if (amount > balance_) {
      std::cout << "Insufficient Balance!" << std::endl;
      return;
    }
    balance_ -= amount;
  }

  // 查余额 balance —— const 成员函数：承诺不修改对象
  double balance() const {
    // TODO: 返回 balance_
    return balance_;
  }
};

int main() {
  BankAccount acc("Alice", 1000);

  acc.deposit(500);    // 余额 1500
  acc.withdraw(200);   // 余额 1300
  acc.withdraw(99999); // 应该打印错误并拒绝

  std::cout << "Balance: " << acc.balance() << "\n"; // 期望 1300
  return 0;
}
