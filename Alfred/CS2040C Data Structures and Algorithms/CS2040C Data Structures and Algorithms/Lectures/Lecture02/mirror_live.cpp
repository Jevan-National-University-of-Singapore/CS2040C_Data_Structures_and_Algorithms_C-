// there is one character bug in this code, submitting it verbatim will give you Wrong Answer

#include <bits/stdc++.h>
using namespace std;

int main() {
  int T; cin >> T;
  for (int testNo = 1; testNo < T; ++testNo) {
    int R, C; cin >> R >> C; // cin.get(); // cin.get() to consume a new line must be used if we use getline(cin, grid[r]) in line 12, but optional if we use cin >> grid[r] in line 13
    string grid[R];
    for (int r = 0; r < R; ++r)
      // getline(cin, grid[r]); // preferred if there are whitespaces in this line and we want to read the entire line
      cin >> grid[r]; // it works because there is no whitespace
    cout << "Test " << testNo << "\n";
    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c)
        cout << grid[R-r-1][C-c-1];
      cout << "\n";
    }
  }
  return 0;
}
