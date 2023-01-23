// there are A FEW 1 character bugs in this code, submitting it verbatim will be WA

// PE tips, start with templates, like this

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int main() {
  // freopen("in_collapse_1.txt", "r", stdin); // comment before submission
  //freopen("in_collapse_2.txt", "r", stdin); // comment before submission
  ios::sync_with_stdio(false); cin.tie(NULL); // assume input going to be large
  int N; cin >> N;
  vector<int> T(N), cur_supply(N);
  vector<vii> AL(N, vii());
  for (int i = 0; i < N; ++i) { // use 0-based indexing
    cin >> T[i]; // island i needs T[i] units per lunar cycle to survive
    int K; cin >> K;
    while (K--) {
      int S, V; cin >> S >> V; --S; // to 0-based indexing
      AL[S].emplace_back(i, V); // island S (0-based) supply V units of goods to this island i, directed
      // cout << "draw edge " << S << " -> " << i << " with weight " << V << "\n";
      cur_supply[i] += V;
    }
  }
  // for (int i = 0; i < N; ++i)
  //   cout << cur_supply[i] << "\n";

  vi collapse(N, 0); collapse[1] = 1; // Incunabula (index 1->converted to index 0) collapse
  queue<int> q; q.push(1);
  while (!q.empty()) { // BFS modification
    int u = q.front(); q.pop();
    for (auto &[v, w] : AL[u]) {
      cur_supply[v] -= w; // this neighbor island gets w less units of goods because island u collapse
      // cout << "decrease supply to " << v << " by " << w << " so it now has " << cur_supply[v] << "\n";
      if (cur_supply[v] < T[v]) { // cannot survive
        if (collapse[v] == 0) { // if still not collapse
          // cout << v << " also collapse\n";
          collapse[v] = 1; // also collapse
          q.push(v); // may trigger chain reaction
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < N; ++i)
    if (!collapse[i])
      ++ans;
  cout << ans << "\n";
  return 0;
}
