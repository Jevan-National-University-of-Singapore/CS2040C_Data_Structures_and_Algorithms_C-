// Detour
// Dijkstra's from destination (Amsterdam, vertex 1) to find illegal edges (for the bus, as the bus always avoid shortest path to Amsterdam :O),
// then run either DFS/BFS to output a path to connect 0 to 1 (if any)
// coded in about 24m from scratch

// the final part of this code is removed so one has to complete it before you can submit it to get AC

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector<vii> AL;
vi pred, vis, path;
unordered_set<ii> banned_edge;

void dfs(int u) {
  vis[u] = 1;
  for (auto &[v, w] : AL[u])
    if (!banned_edge.count({u, v}) && !vis[v]) { // if edge u->v is NOT banned and v is not visited yet (other ways exist)
      dfs(v);
      pred[v] = u;
    }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  int n, m; cin >> n >> m; // read the undirected weighted connected graph
  AL.assign(n, vii());
  while (m--) {
    int a, b, d; cin >> a >> b >> d;
    AL[a].emplace_back(b, d);
    AL[b].emplace_back(a, d); // bidirectional, same weight (no need to reverse edge then)
  }

  vi dist(n, INF); dist[1] = 0; // run (Original) Dijkstra's from destination, vertex 1 = Amsterdam, this is called the Single Destination Shortest Path problem
  set<ii> pq;
  for (int u = 0; u < n; ++u)
    pq.emplace(dist[u], u);
  pred.assign(n, -1);
  while (!pq.empty()) {
    auto [d, u] = *pq.begin(); pq.erase(pq.begin());
    for (auto &[v, w] : AL[u]) {
      if (dist[u]+w >= dist[v]) continue;
      pq.erase(pq.find({dist[v], v}));
      dist[v] = dist[u]+w;
      pred[v] = u; // remember this
      pq.emplace(dist[v], v);
    }
  }

  for (int u = 0; u < n; ++u) { // ban all edges that leads to shortest path to Amsterdam
    if (pred[u] == -1) continue; // ignore
    banned_edge.insert({u, pred[u]}); // insert edge that is part of the shortest path from u to pred[u] (closer to Amsterdam)
  }

  pred.assign(n, -1); // now DFS from 0/Delft to 1/Amsterdam on the remaining edges, see if it is possible
  vis.assign(n, 0);
  dfs(0); // traversal from 0/Delft to 1/Amsterdam, avoiding banned edges

  if (!vis[1])
    cout << "impossible\n";
  else {
    // this part removed so that you cannot just submit this code to get AC
    // print the actual path found by DFS from vertex 0/Delft to vertex 1/Amsterdam using the "pred" information

  }

  return 0;
}
