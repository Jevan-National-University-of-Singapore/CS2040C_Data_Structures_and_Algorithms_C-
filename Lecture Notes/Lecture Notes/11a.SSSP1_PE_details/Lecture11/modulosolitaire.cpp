// I put TWO character typos in this live code, so submitting it verbatim will give you WA

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  ///freopen("in.txt", "r", stdin);

  int m, n, s0; cin >> m >> n >> s0;
  vll a(n), b(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i] >> b[i]; // read as long long

  // run BFS, from source = s0

  // the standard SSSP initialization phase
  vll D(m, -1); // there are m vertices, I use -1 as "INF"
  D[s0] = 0LL; // this is the only known shortest path at the beginning
  queue<ll> q;
  q.push(s0);

  while (!q.empty()) { // standard BFS loop, O(m + 10*m) algorithm
    ll u = q.front(); q.pop();
    for (int i = 0; i < n; ++i) { // O(n), n <= 10
      ll v = (u*a[i] + b[i]) % n;
      if (D[v] == -1) continue; // already visited before
      D[v] = D[u]+1;
      q.push(v);
    }
  }

  cout << D[0] << '\n'; // if this value 0 is unreachable (INF), it is -1
  return 0;
}
