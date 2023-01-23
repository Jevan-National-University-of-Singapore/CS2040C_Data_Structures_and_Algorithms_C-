// the final part of this code is removed so one has to complete it before you can submit it to get AC

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9; // 1 Billion, this is a safer constant for SSSP problem

vector<vii> RevAL; // I use global, sorry
vi visited;

int main() {
  freopen("in.txt", "r", stdin);

  // read the graph
  int P, T; cin >> P >> T; // P = V, T = E, s = 0, t = P-1
  vector<vii> AL(P, vii()); // create AL
  while (T--) {
    int p1, p2, l; cin >> p1 >> p2 >> l;
    AL[p1].emplace_back(p2, l); // this and the line below (slightly faster)
    AL[p2].push_back({p1, l}); // are equal (slightly slower)
  }

  // find shortest path from s = 0 (entrance) to EVERYWHERE (including t = P-1)
  // let's write crispy Dijkstra's
  vi dist(P, INF); dist[0] = 0;
  priority_queue<ii, vector<ii>, greater<ii>> pq; // min pq now
  pq.emplace(0, 0); // coz s = 0, and dist[s] = 0, so (dist[s], s) = (0, 0)
  RevAL.assign(P, vii()); // reversed graph
  while (!pq.empty()) { // O((P+T) log P) steps
    auto [d, u] = pq.top(); pq.pop();
    if (d > dist[u]) continue; // inferior vertex info pair
    // optional optimization (if RevAL traversal is done correctly)
    // if (u == P-1) break; // exclude vertices that are further than highest peak
    for (auto &[v, w] : AL[u]) {
      if (dist[u]+w > dist[v])
        continue; // not a successful relaxation
      else if (dist[u]+w == dist[v]) {
        RevAL[v].emplace_back(u, w); // add reversed edge v->u with weight w
      }
      else { // if (dist[u]+w < dist[v]
        RevAL[v].clear(); // clear first
        RevAL[v].emplace_back(u, w); // add rev edge v->u with weight w
        dist[v] = dist[u]+w;
        pq.push({dist[v], v});
      }
    }
  }

  // RevAL structure, for debugging purpose
  // for (int u = 0; u < P; ++u) {
  //   cout << " in reversed graph, vertex " << u << " has ";
  //   for (auto &[v, w] : RevAL[u])
  //     cout << "(" << v << ", " << w << ") ";
  //   cout << endl;
  // }

  // now do a DFS/BFS traversal from t = P-1 back to s = 0 on RevAL, sum edge weights, times two
  // coz not all edges are needed
  visited.assign(P, 0);
  cout << "do as suggested in the comment" << endl;

  return 0;
}
