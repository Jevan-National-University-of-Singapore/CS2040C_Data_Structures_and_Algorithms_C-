// there is a one character typo in this code, submitting it verbatim will give you WA :O

// Kattis's Quest
// simulation of greedy algorithm (as outlined in the problem description) using Priority Queue
// map int to pq (one of the easiest possible way), there are other ways
// code: 6.15pm, submit: 6.38m (23m, AC) -- real testing using myself last sem

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  int N; cin >> N; cin.get();
  map<int, priority_queue<int>> pool;
  while (N--) {
    string S; cin >> S;
    if (S == "add") {
      int E, G; cin >> E >> G; cin.get();
      pool[E].push(G); // insert G into the correct priority queue (of energy E)
    }
    else { // if (S == "query"), no need to really test
      int X; cin >> X; cin.get();
      ll ans = 0; // this ll thingy trapped a lot of people... it was just an exercise to recognize data type ranges (this 'error' is better managed with partial marks system today)
      while (X) {
        auto pos = pool.upper_bound(X); // find the largest energy quest from current pool of quest
        if (pos == pool.begin()) break; // I don't have any... stop
        --pos; // this needs some time to debug :O
        X -= pos->first; // reduce energy X by this amount
        priority_queue<int> &pq = pos->second; // notice the usage of & (by address) so that I can really modify the PQ
        ans += pq.top(); pq.pop(); // add answer by this amount
        if (pq.empty()) // important check so that line 27 above is correct
          pool.erase(pos);
      }
      cout << ans << endl;
    }
  }
  return 0;
}
