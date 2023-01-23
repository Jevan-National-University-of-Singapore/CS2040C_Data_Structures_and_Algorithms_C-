// On Average They're Purple
// the answer is the number of edges in unweighted SSSP from 1 to N (minus one); BFS
// read and code: 3:59pm, submit 4:07pm (8m, AC)

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int INF = 1e9;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  
  int N, M; cin >> N >> M;
  vector<vi> AL(N, vi());
  while (M--) {
    int a, b; cin >> a >> b; --a; --b; // to 0-based indexing
    AL[a].push_back(b);
    AL[b].push_back(a); // bidirectional
  }
    
  vi dist(N, INF); dist[0] = 0;
  queue<int> q; q.push(0);
  while (!q.empty()) { // BFS
    int u = q.front(); q.pop();
    for (int v : AL[u]) {
      if (dist[v] != INF) continue; // already visited before
      dist[v] = dist[u]+1;
      q.push(v);
    }
  }

  cout << dist[N-1]-1 << endl; // this is the answer
  return 0;
}
