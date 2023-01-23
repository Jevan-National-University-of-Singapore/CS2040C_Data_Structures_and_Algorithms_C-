// Fantasy Draft
// ds simulation
// code 10:33am, submit 11:06am (33m, RTE), 11:19am (46m, ??)

#include <bits/stdc++.h>
using namespace std;

typedef list<string> ls;

int main() {
  //freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(NULL);
  int n, k;  cin >> n >> k;
  vector<ls> preferences(n);
  for (auto &drafting : preferences) {
    int q; cin >> q;
    while (q--) {
      string s; cin >> s;
      drafting.push_back(s); // this owner's preferred order
    }
  }

  unordered_map<string, int> ranking(100000); // hash table is fine
  map<int, string> available; // bBST, we need the ordering
  int p; cin >> p;
  for (int i = 0; i < p; ++i) { // p players, ordered by previous year's ranking (use 0-based)
    string name; cin >> name;
    ranking[name] = i;
    available[i] = name;
  }

  vector<ls> selections(n);
  while (k--) { // repeat k rounds
    for (int i = 0; i < n; ++i) { // for each owner i, in order, he will pick a player based on his preferences first
      bool has_picked = false; // go through owner i's preferences first
      while (((int)preferences[i].size() > 0)) {
        string preferred = preferences[i].front(); preferences[i].pop_front(); // O(1) for LL
        int rank = ranking[preferred];
        if (available.count(rank)) { // if this player (at certain rank) is still available
          selections[i].push_back(preferred);
          available.erase(rank);
          has_picked = true;
          break;
        }
      }
      if (!has_picked) { // if owner i does not get his preferred selection, just give next best
        auto [rank, next_best] = *available.begin();
        selections[i].push_back(next_best);
        available.erase(rank);
      }
    }
  }

  for (auto ith_owner : selections) { // output n lines, the ith lines contains k names selected by ith owner
    for (auto &name : ith_owner)
      cout << name << " ";
    cout << endl;
  }
  return 0;
}