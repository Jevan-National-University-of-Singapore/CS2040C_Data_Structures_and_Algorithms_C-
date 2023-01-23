// there is one character bug in this code, submitting it verbatim will give you Wrong Answer

#include <bits/stdc++.h>
using namespace std;

int main() {
  while (1) {
    string line; getline(cin, line);
    if (cin.eof()) break;
    istringstream iss(line);
    string token;
    string name = "";
    double total = 0.0;
    int n = 0;
    while (getline(iss, token, ' ')) { // while still got token
      if (isalpha(token[0])) { // a string
        if (name == "")
          name = token;
        else
          name += "" + token;
      }
      else { // a floating point number
        total += stod(token);
        ++n;
      }
    }
    cout << fixed << setprecision(4) << total/n << " " << name << "\n";
  }
  return 0;
}
