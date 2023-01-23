// Kattis's Quest
// simulation of greedy algorithm (as outlined in the problem description)
// weak solution: using resizeable array (vector), will TLE

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  int N; cin >> N; cin.get();
  vector<ii> pool;

  while (N--) {
    string S; cin >> S;
    if (S == "add") {
      int E, G; cin >> E >> G; cin.get();
      pool.emplace_back(E, G); // insert pair (E, G) into the pool of quests (unordered)
    }
    else { // if (S == "query"), no need to really test
      int X; cin >> X; cin.get();
      ll ans = 0; // this ll thingy trapped a lot of people... it was just an exercise to recognize data type ranges (this 'error' is better managed with partial marks system today)

      while (X && (int)pool.size()) { // still have energy and still have quest to do
        int max_E = -1, max_G = -1, best_i = -1;
        for (int i = 0; i < (int)pool.size(); ++i) { // O(N), slow
          auto &[E, G] = pool[i];
          if (X < E) continue; // cannot do this quest, not enough energy
          if (E > max_E) {
            max_E = E;
            max_G = G;
            best_i = i;
          }
          else if (E == max_E) {
            if (G > max_G) {
              max_G = G;
              best_i = i;
            }
          }
        }

        if (best_i == -1) break;
        X -= pool[best_i].first; // reduce energy X by this amount
        ans += pool[best_i].second; // add answer by this amount
        pool.erase(pool.begin()+best_i); // O(N), slow also
      }

      cout << ans << endl;
    }
  }
  return 0;
}
