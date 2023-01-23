// Kattis's Quest
// simulation of greedy algorithm (as outlined in the problem description)
// better solution: using priority_queue, will TLE in the search for correct quest with E <= X part...

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  int N; cin >> N; cin.get();
  priority_queue<ii> pool; // max PQ

  while (N--) {
    string S; cin >> S;
    if (S == "add") {
      int E, G; cin >> E >> G; cin.get();
      pool.push({E, G}); // insert pair (E, G) into the pool of quests (ordered by decreasing E and if ties, by decreasing G)
    }
    else { // if (S == "query"), no need to really test
      int X; cin >> X; cin.get();
      ll ans = 0; // this ll thingy trapped a lot of people... it was just an exercise to recognize data type ranges (this 'error' is better managed with partial marks system today)

      priority_queue<ii> tempPQ; // searching for the correct quest with E <= X  is slow, O(N) :(...
      while (!pool.empty()) {
        auto [E, G] = pool.top();
        if (E <= X) { // Kattis can do this quest
          X -= E;
          ans += G;
        }
        else
          tempPQ.push(pool.top()); // we temporarily pop this
        pool.pop();
      }

      pool = tempPQ; // O(N) copy :O..., not actually better than using plain resizeable array (vector) :O...

      cout << ans << endl;
    }
  }
  return 0;
}
