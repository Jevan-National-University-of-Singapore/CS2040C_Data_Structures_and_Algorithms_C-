// if your compiler can compile this, it is C++17 compliant

#include <bits/stdc++.h>
using namespace std;
int main() {
  map<string, int> mapper = {{"Z", 2040}, {"Steven", 7}, {"AAAAA", 10}};
  for (auto &[k, v] : mapper)
    cout << k << "->" << v << "\n";
  return 0;
}

// if you run this program, the output should be:
/*

AAAAA->10
Steven->7
Z->2040

*/

// we will revisit map in Week 08 (Balanced BST)
