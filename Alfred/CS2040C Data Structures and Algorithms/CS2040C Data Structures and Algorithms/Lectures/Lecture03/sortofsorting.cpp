// there is one character bug in this code, submitting it verbatim will give you Wrong Answer

/*
3
Mozart
Beethoven
Bach
5
Hilbert
Godel
Poincare <-- look at Po    incare
Ramanujan
Pochhammmer <--   vs Po    chhammer
0
*/

#include <bits/stdc++.h>
using namespace std;

/*
// pre C++ 11 way
bool cmp(string a, string b) {
  if (a[0] != b[0])
    return a[0] < b[0];
  else
    return a[1] < b[1];
}
*/

int main() { // the whole thing is O(N log N)
  freopen("in.txt", "r", stdin);
  bool FirstTestCase = true;
  int n;
  while (cin >> n, n) { // probably new "technique" to many of you: we can chain two C++ commands into one line using a comma, the last value (n here) is used as the test condition for the while loop, the while loop stops when n == 0
    vector<string> names(n); // declare locally so that it is fresh per test case :D
    for (auto &name : names) // C++11 way to read this input
      cin >> name;
    // study the difference of sort vs stable_sort in cppreference
    // stable_sort(names.begin(), names.end(), cmp); // old, pre C++11 way
    stable_sort(names.begin(), names.end(), [](string a, string b) { // using C++11 lambda function, note that you have to compile this file using g++ -std=c++11 sortofsorting.cpp
      if (a[0] != b[0]) return a[0] < b[0];
      return a[1] < b[1];
    }); // O(N log N)
    if (!FirstTestCase) printf("\n");
    FirstTestCase = false;
    for (auto &name : names) // O(N), I am using C++11 range-based for loop, I use & to avoid copying the value
      cout << name << endl;
  }
  return 0;
}
