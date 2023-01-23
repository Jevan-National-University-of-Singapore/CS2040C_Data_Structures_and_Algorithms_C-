// Join Strings
// list splice, takes time to actually understand list splice
// code: 5.12pm, submit: 5.27m (15m, AC)

#include <bits/stdc++.h>
using namespace std;

void debug(list<string> &zz) {
  for (auto &z : zz)
    cout << z << " ";
  cout << endl;
}

int main() {
  // freopen("3.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(NULL);
  int N; cin >> N;
  list<string> S[N]; // array of N lists
  for (int i = 0; i < N; ++i) { // store in 0-based
    string Si; cin >> Si;
    S[i].push_back(Si);
    // debug(S[i]);
  }
  int a = 0, b;
  for (int i = 1; i <= N-1; ++i) { // process N-1 operations
    cin >> a >> b; --a; --b; // to 0-based indexing
    // debug(S[a]);
    // debug(S[b]);
    S[a].splice(S[a].end(), S[b]);
    // debug(S[a]);
    // debug(S[b]);
    // cout << endl;
  }
  for (auto &Si : S[a])
    cout << Si;
  cout << endl;
  return 0;
}
