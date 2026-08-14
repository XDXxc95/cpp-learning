// practice/03-1/solutions/06_valid_parentheses.cpp — 参考答案：括号匹配（LeetCode 20）
#include <iostream>
#include <stack>
#include <string>

bool matching(char open, char close) {
  return (open == '(' && close == ')') || (open == '[' && close == ']') ||
         (open == '{' && close == '}');
}

int main() {
  std::string s;
  std::getline(std::cin, s);

  std::stack<char> st;
  bool ok = true;
  for (char c : s) {
    if (c == '(' || c == '[' || c == '{') {
      st.push(c); // 左括号入栈，等配对的右括号
    } else {
      // 右括号：栈空（没左括号可配）或栈顶不是同类型 → 不合法
      if (st.empty() || !matching(st.top(), c)) {
        ok = false;
        break;
      }
      st.pop(); // 配对成功，弹出
    }
  }
  if (!st.empty())
    ok = false; // 还有没闭合的左括号
  std::cout << (ok ? "valid" : "invalid") << "\n";
  return 0;
}
