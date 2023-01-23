// Kattis's Quest
// simulation of greedy algorithm (as outlined in the problem description)
// better solution: using set that allows binary search, will WA because set does NOT accept duplicates but it has a quick fix...

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  int N; cin >> N; cin.get();
  set<ii> pool; // using balanced BST (C++ STL set) as a PQ

  while (N--) {
    string S; cin >> S;
    if (S == "add") {
      int E, G; cin >> E >> G; cin.get();
      pool.insert({-E, -G}); // insert pair (-E, -G) into the pool of quests (ordered by decreasing E and if ties, by decreasing G), using negative to reverse the sorted order
    }
    else { // if (S == "query"), no need to really test
      int X; cin >> X; cin.get();
      ll ans = 0; // this ll thingy trapped a lot of people... it was just an exercise to recognize data type ranges (this 'error' is better managed with partial marks system today)

      while (X) {
        auto it = pool.upper_bound({-X, INT_MIN});
        if (it == pool.end()) break; // no such quest
        X += it->first; // it was negated
        ans -= it->second; // it was negated
        pool.erase(it);
      }

      cout << ans << endl;
    }
  }
  return 0;
}
