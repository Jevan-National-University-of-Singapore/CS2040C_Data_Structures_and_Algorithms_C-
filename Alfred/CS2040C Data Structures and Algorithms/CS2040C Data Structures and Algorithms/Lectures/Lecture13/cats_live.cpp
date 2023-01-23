// the final part of this code is removed so one has to complete it before you can submit it to get AC
// then this code is sprinkled with a few bugs

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> AL;                                  // the graph stored in AL
vi taken;                                        // to avoid cycle
priority_queue<ii> pq;                           // to select shorter edges
// C++ STL priority_queue is a max heap, we use -ve sign to reverse order

void process(int u) { // set u as taken and enqueue neighbors of u
  taken[u] = 1;
  for (auto &[v, w] : AL[u])
    if (!taken[v])
      pq.push({-w, -v});                         // sort by non-dec weight
}                                                // then by inc id

int main() {
  /*
  // Graph in Figure 4.10 left, format: list of weighted edges
  // This example shows another form of reading graph input
  5 7
  0 1 4
  0 2 4
  0 3 6
  0 4 6
  1 2 2
  2 3 8
  3 4 9
  */

  // freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(NULL);

  int T; cin >> T;
  while (T--) {
    int M, C; cin >> M >> C;
    AL.assign(C, vii());
    for (int i = 0; i < C*(C-1)/2; ++i) { // O(V+E) = O(V+V^2) = O(V^2)
      int u, v, w; cin >> u >> v >> w; // read as (u, v, w)
      AL[u].emplace_back(v, w);
      AL[v].emplace_back(u, w); // undirected weighted edge
    }
    taken.assign(C, 0);                            // no vertex is taken
    process(0);                                    // take+process vertex 0 (Cat 0)
    int mst_cost = 0, num_taken = 1;               // no edge has been taken
    // overall, each vertex is processed once O(V^2 log V)
    while (!pq.empty()) {                          // up to O(E)
      auto [w, u] = pq.top(); pq.pop();            // C++17 style
      w = -w; u = -u;                              // negate to reverse order
      if (!taken[u]) continue;                      // already taken, skipped
      mst_cost += w;                               // add w of this edge
      process(u);                                  // take+process vertex u
      ++num_taken;                                 // 1 more edge is taken
      if (num_taken == C-1) break;                 // optimization
    }
    cout << (true ? "yes\n" : "no\n");
  }

  return 0;
}