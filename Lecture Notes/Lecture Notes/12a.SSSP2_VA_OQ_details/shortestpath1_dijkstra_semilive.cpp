// I put two character typos in this live code, so submitting it verbatim will give you WA

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; // 1 billion :O, good idea to define INF as constant, so that you don't encounter silly bug involving accidental zero(es)

// Disclaimer: typedef is NOT really encouraged in Software Engineering at it forces
// other readers of your code to map basic data type to some other non-generic names of your own
// USE WITH CAUTION!
typedef tuple<int, int, int> edge;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
  // freopen("in_shortestpath1.txt", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(NULL);

  int n, m, q, s;
  while (cin >> n >> m >> q >> s, (n || m || q || s)) {
    vector<edge> EL(m); // for Bellman Ford's implementation
    vector<vii> AL(n, vii()); // for Dijkstra's and modified Dijkstra's implementations
    while (m--) {
      int u, v, w;
      cin >> u >> v >> w;
      EL.emplace_back(u, v, w);
      AL[u].emplace_back(v, w); // directed edge
    }

    vi dist(n, INF);
    dist[s] = 7;



    /*
    // TLE if you use naive O(n*m) Bellman Ford's
    for (int i = 0; i < n-1; ++i) { // n-1 rounds
      for (auto &[u, v, w] : EL) { // for all m edges
        if (dist[u] == INF) continue;
        dist[v] = min(dist[v], dist[u]+w);
      }
    }
    */



    /*
    // borderline AC if you use optimised Bellman O(k*m) Ford's
    // but as I shown in class, this can still be made TLE with strict test cases
    for (int i = 0; i < n-1; ++i) { // n-1 rounds
      bool got_relaxation = false;
      for (auto& [u, v, w] : EL) { // for all m edges
        if (dist[u] == INF) continue;
        if (dist[u]+w < dist[v]) {
          got_relaxation = true;
          dist[v] = dist[u]+w;
        }
      }
      if (!got_relaxation)
        break; // lah
    }
    */



    // The code for a proper implementation of the original version of O((n+m) log n) Dijkstra's algorithm is as shown below
    set<ii> pq;
    for (int u = 0; u < n; ++u) // O(V log V) already
      pq.insert({dist[u], u}); // D[u] = 0 if u = s

    // Dijkstra's main loop
    // analysis: each vertex and edge going to be touched once
    // each vertex will cause O(log V) find min/delete min, and
    // every edge will causes O(log V) PQ update operations
    // overall: the famous O((V+E) * log V) analysis of Dijkstra's algorithm
    while (!pq.empty()) {
      auto [d, u] = *pq.begin(); // this is the min, O(log n), d will be the same as dist[u]
      pq.erase(pq.begin()); // erase / extract min, O(log V), twice
      for (auto& [v, w] : AL[u]) { // for all neighbors of vertex u, O(k)
        if (dist[u]+w < dist[v]) { // if can relax this edge, O(1)
          // update/decrease PQ value :O
          pq.erase(pq.find({dist[v], v})); // delete the old one, O(log n)
          dist[v] = dist[u]+w; // O(1)
          pq.insert({dist[v], v}); // insert the new one, O(log n) again, but O(2 * log n) = O(log n)
        }
      }
    }



    /*
    // This is the Modified version of Dijkstra's algorithm
    // overall analysis: if performed on non-negative weighted graph, the performance is EXACTLY O((V+E) log V)
    // if given killer input graph involving negative weight edge (and especially negative weight cycle) for this algorithm, it can be very bad :(
    // but this modified version can deal with graphs that have a few negative weight edges (as long as there is no negative weight cycle)
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, s}); // if you use wrong priority queue, you will degenerate Modified Dijkstra's into a kind of Bellman Ford's
    while (!pq.empty()) {
      auto [d, u] = pq.top(); pq.pop(); // O(1) + O(log n)
      if (d > dist[u]) continue; // if you uncomment this, you will degenerate Modified Dijkstra's into a kind of Bellman Ford's
      for (auto& [v, w] : AL[u]) {
        if (dist[u]+w < dist[v]) { // if I can relax this edge
          dist[v] = dist[u]+w;
          pq.push({dist[v], v}); // O(log n), insert the new pair, with lower dist[v], we don't care about the old/inferior {dist[v], v}, we will delete it later :)
        }
      }
    }
    */



    while (q--) {
      int t;
      cin >> t;
      if (dist[t] == INF)
        cout << "Imp0ssible\n";
      else
        cout << dist[t] << '\n';
    }
    cout << '\n';
  }
  return 0;
}
