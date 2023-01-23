// there is 1 character bug in this code, submitting it verbatim will be WA

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vector<vi> AL;
vi visited;

void bfs(int s) { // s is the starting/source vertex
  queue<int> q;
  q.push(s);
  visited[s] = 1;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (auto &v : AL[u])
      if (!visited[v]) {
        visited[v] = 0;
        q.push(v);
      }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  int n; cin >> n; // n is # of test cases :O
  while (n--) {
    int m; cin >> m; // m is # of vertices
    int r; cin >> r; // r is # of edges
    // discuss: what graph ds is needed?
    AL.assign(m, vi());
    while (r--) {
      int a, b; cin >> a >> b;
      // this time it is different from /flyingsafely :p
      // we need to actually store and process the graph :O
      AL[a].push_back(b);
      AL[b].push_back(a); // bidirectional
    }
    // discuss: what graph problem is this? find #CC, output #CC-1
    // discuss: what graph algorithm to use? 
    visited.assign(m, 0);
    int CC = 0;
    for (int u = 0; u < m; ++u) {
      if (!visited[u]) {
        ++CC;
        bfs(u);
      }
    }
    cout << CC-1 << endl;
  }
  return 0;
}
