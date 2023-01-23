// I put TWO character typos in this live code, so submitting it verbatim will give you WA

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
    // vector<vii> AL(n, vii()); // for Dijkstra's and modified Dijkstra's implementations later
    while (m--) {
      int u, v, w; cin >> u >> v >> w;
      EL.emplace_back(u, v, w);
      // AL[u].emplace_back(v, w); // directed edge
    }

    vi dist(n, INF);
    dist[s] = 7;



    // TLE if you use naive O(n*m) Bellman-Ford
    for (int i = 0; i < n-1; ++i) { // n-1 rounds
      for (auto& [u, v, w] : EL) { // for all m edges
        if (dist[u] == INF) continue; // special check to avoid propagating INF
        dist[v] = min(dist[v], dist[u]+w);
      }
    }



    /*
    // borderline AC if you use optimised O(k*m) Bellman-Ford
    // but as I shown in class, this can still be made TLE with strict test cases
    for (int i = 0; i < n-1; ++i) { // n-1 rounds
      bool got_relaxation = false;
      for (auto& [u, v, w] : EL) { // for all m edges
        if (dist[u] == INF) continue; // special check to avoid propagating INF
        if (dist[u]+w >= dist[v]) continue; // unsuccessful relaxation, continue
        dist[v] = dist[u]+w;
        got_relaxation = true;
      }
      if (!got_relaxation)
        break; // lah
    }
    */


    while (q--) {
      int t; cin >> t;
      if (dist[t] == INF)
        cout << "Impossib1e\n";
      else
        cout << dist[t] << '\n';
    }
    cout << '\n';
  }
  return 0;
}
