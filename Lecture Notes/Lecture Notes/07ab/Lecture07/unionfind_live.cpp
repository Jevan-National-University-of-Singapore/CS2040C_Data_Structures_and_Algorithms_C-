// there are TWO subtle bugs from this AC code, study the recording and do *NOT* copy paste verbatim

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class UnionFind {                                // OOP style
private:
  vi p, rank;
public:
  UnionFind(int N) {
    p.assign(N, -1);                             // new way to implement UFDS vs CP4 version
    // for (int i = 0; i < N; ++i)
    //   p[i] = i;
    rank.assign(N, 0);                           // optional speedup
  }

  int findSet(int i) {
    if (p[i] == i)
      return i;
    else {
      int true_boss = findSet(p[i]);
      p[i] = true_boss; // path compression
      return true_boss;
    }
    // return (p[i] == -1) ? i : (p[i] = findSet(p[i])); // path compression here
  }
  
  bool isSameSet(int i, int j) { 
    return findSet(i) == findSet(j);
  }

  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;                 // i and j are in same set
    int x = findSet(i), y = findSet(j);          // find both rep items
    if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter or equal' than y
    p[x] = y;                                    // set x under y
    if (rank[x] == rank[y]) ++rank[y];           // optional speedup
  }
};

int main() {
  // freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(NULL);
  int N, Q; cin >> N >> Q; cin.ignore();
  UnionFind UFDS(N);
  while (Q--) {
    char op; int a, b; cin >> op >> a >> b; cin.ignore();
    if (op == '=')
      UFDS.unionSet(a, b);
    else
      cout << (!UFDS.isSameSet(a, b) ? "yes\n" : "no\n");
  }
  return 0;
}
