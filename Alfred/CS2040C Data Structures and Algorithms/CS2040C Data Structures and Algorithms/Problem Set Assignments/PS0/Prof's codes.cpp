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
          name += " " + token;
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


/*

  int T; cin >> T;
  for (int testNo = 1; testNo <= T; ++testNo) {
    int R, C; cin >> R >> C; cin.get();
    string grid[R];
    for (int r = 0; r < R; ++r)
      // getline(cin, grid[r]);
      cin >> grid[r];
    cout << "Test " << testNo << "\n";
    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c)
        cout << grid[R-r-1][C-c-1];
      cout << "\n";
    }
  }

*/


/*

  int P, D; cin >> P >> D;
  vector<int> vA(D+1, 0), vB(D+1, 0);
  int V = 0;
  while (P--) {
    int d, a, b; cin >> d >> a >> b;
    vA[d] += a;
    vB[d] += b;
    V += (a+b);
  }
  int total_wA = 0, total_wB = 0;
  for (int d = 1; d <= D; ++d) {
    int win = (vA[d]+vB[d])/2 + 1;
    int wA, wB;
    if (vA[d] >= win) { // party A wins in district d
      wA = vA[d]-win;
      wB = vB[d];
      cout << "A " << wA << " " << wB << "\n";
    }
    else { // party B wins in district d
      wA = vA[d];
      wB = vB[d]-win;
      cout << "B " << wA << " " << wB << "\n";
    }
    total_wA += wA;
    total_wB += wB;
  }
  cout << fixed << setprecision(12) << (double)abs(total_wA-total_wB) / V << "\n";

  */
