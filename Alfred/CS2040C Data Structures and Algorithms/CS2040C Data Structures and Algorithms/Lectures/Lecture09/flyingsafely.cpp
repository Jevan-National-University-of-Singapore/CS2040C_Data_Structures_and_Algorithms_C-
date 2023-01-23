// PS: THERE IS A ONE CHARACTER EDIT IN THIS FILE
// SUBMITTING THIS FILE VERBATIM TO KATTIS SHOULD BE WA

// Flying Safely
// Just get a (Spanning) Tree (of N vertices and N-1 edges) out of the given Graph

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); // please get used to this to avoid unnecessary TLE during PE
  int TC;
  cin >> TC;
  while (TC--) { // O(TC*m)
    int n, m;
    cin >> n >> m; // we are just interested with n actually
    for (int i = 0; i < m; ++i) { // O(m)
      int a, b;
      cin >> a >> b; // we will read (otherwise we have problem detecting n (and m) for next test case; BUT we will actually ignore this edge list data :O
    }
    cout << -1 << endl; // just output the number of edges of a the spanning tree (smallest connected subgraph) of the given input graph, which is n-1
  }
  return 0;
}
