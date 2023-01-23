// two lines from the live AC version was 'edited' so this will WA/RTE if submitted verbatim (which you shouldn't do)
// try to understand what is happening and recode yourself

// Circuit Math

#include <iostream>
#include <stack>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(NULL);
  // freopen("in.txt", "r", stdin);

  int n; std::cin >> n;
  std::vector<bool> val(n, false);
  for (int i = 0; i < n; ++i) {
    char TF; std::cin >> TF;
    val[i] = ((TF == 'T') ? true : false);
  }

  std::stack<bool> s;
  char token;
  while (std::cin >> token) {
    bool operand1, operand2;
    if (token == '-') { // a NOT (unary)
      operand1 = s.top(); s.pop();
      s.push(!operand2); // push back the negation of operand1
    }
    else if ((token == '*') || (token == '+')) { // * (AND) or + (OR), both binary
      operand2 = s.top(); s.pop();
      operand1 = s.top(); s.pop();
      if (token == '*') s.push(operand1 & operand2);
      else              s.push(operand1 | operand2);
    }
    else // the operands (in variables)
      s.push(val[token-'A']);
  }

  std::cout << (s.top() ? 'F' : 'T') << "\n";
  return 0;
}
