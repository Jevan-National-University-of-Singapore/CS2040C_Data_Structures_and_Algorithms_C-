// there is one character bug in this code, submitting it verbatim will give you Wrong Answer

#include <iostream>
#include <numeric>
#include <sstream>
//#include <string> // optional now, C++ string is also defined in <sstream>
#include <vector>
using namespace std;

class student { // example of C++ class
private: // there is/are some private stuffs
  vector<bool> to_solve; // private (resizeable) array of Booleans
public: // there is/are some public stuffs
  student() { // class constructor
    to_solve.assign(1000, false); // [0..1000], I will sacrifice index 0
  }

  void solve(int this_problem_number) {
    to_solve[this_problem_number] = true;
  }

  void solve(int from_this_problem_number, int to_this_problem_number) { // example of function overloading, same function name but with different parameter list
    for (int i = from_this_problem_number; i <= to_this_problem_number; ++i) // actually not the best way to solve this problem :)
      to_solve[i] = true;
  }

  int count_problems_to_solve() {
    // int ans = 0;
    // for (int i = 1; i <= 1000; ++i) // the long way
    //   if (to_solve[i])
    //     ++ans;
    // return ans;
    return accumulate(to_solve.begin(), to_solve.end(), 0); // the shorter way, inside <numeric>
  }
};

int main() {
  string line; cin >> line;
  stringstream ss(line);
  string consecutive;
  student Hneitir;
  while (getline(ss, consecutive, ';')) {
    if (consecutive.find("-") == string::npos)
      Hneitir.solve(stoi(consecutive));
    else {
      stringstream ss2(consecutive);
      string lo; getline(ss2, lo, '-');
      string hi; getline(ss2, hi, '-');
      Hneitir.solve(stoi(lo), stoi(hi));
    }
  }
  cout << Hneitir.count_problems_to_solve() << "\n";
  return 0;
}
