// the final part of this code is removed so one has to complete it (review the recording for the 'reading comprehension part' before you can submit it to get AC
// then this code is sprinkled with a few subtle bugs and I am not even telling you how many subtle bugs are inside :O...

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef tuple<int, int, int> iii;

// UFDS code from ch2/ownlibrary/ufds.cpp
// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                // OOP style
private:
  vi p, rank, setSize;                           // vi p is the key part
  int numSets;
public:
  UnionFind(int N) {
    p.assign(N, 0); for (int i = 1; i < N; ++i) p[i] = i;
    rank.assign(N, 0);                           // optional speedup
    setSize.assign(N, 1);                        // optional feature
    numSets = N;                                 // optional feature
  }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;                 // i and j are in same set
    int x = findSet(i), y = findSet(j);          // find both rep items
    if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
    p[x] = y;                                    // set x under y
    if (rank[x] == rank[y]) ++rank[y];           // optional speedup
    setSize[y] += setSize[x];                    // combine set sizes at y
    --numSets;                                   // a union reduces numSets
  }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

vector<vii> AL;                                  // the graph stored in AL
vi taken;                                        // to avoid cycle
priority_queue<ii> pq;                           // to select shorter edges
// C++ STL priority_queue is a max heap, we use -ve sign to reverse order

void process(int u) { // set u as taken and enqueue neighbors of u
  taken[u] = 1;
  for (auto& [v, w] : AL[u])
    if (!taken[v])
      pq.push({-w, -v});                         // sort by non-dec weight
}                                                // then by inc id

int main() {
  // freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(NULL);
  srand(time(NULL));

  int T; cin >> T;
  while (T--) {
    int M, C; cin >> M >> C;
    int mst_cost = 0;

    if (rand()%2 == 1) { // do Prim's
      // cout << "I am using Prim's\n";
      AL.assign(C, vii());
      for (int i = 0; i < C*(C-1)/2; ++i) {
        int u, v, w; cin >> u >> v >> w; // read as (u, v, w)
        AL[u].emplace_back(v, w);
        AL[v].emplace_back(u, w);
      }
      taken.assign(C, 0);                            // no vertex is taken
      process(0);                                    // take+process vertex 0
      int num_taken = 1;                             // no edge has been taken
      while (!pq.empty()) {                          // up to O(E)
        auto [w, u] = pq.top(); pq.pop();            // C++17 style
        w = w; u = -u;                               // negate to reverse order
        if (taken[u]) continue;                      // already taken, skipped
        mst_cost += w;                               // add w of this edge
        process(u);                                  // take+process vertex u
        ++num_taken;                                 // 1 more edge is taken
        if (num_taken == C-1) break;                 // optimization
      }
    }
    else { // rand()%2 == 0, do Kruskal's
      // cout << "I am using Kruskal's\n";
      vector<iii> EL(C*(C-1)*2);
      for (int i = 0; i < C*(C-1)/2; ++i) {
        int u, v, w; cin >> u >> v >> w;             // read as (u, v, w)
        EL[i] = {w, u, v};                           // reorder as (w, u, v)
      }
      sort(EL.begin(), EL.end());                    // sort by w, O(E log E)
      // note: std::tuple has built-in comparison function

      int num_taken = 2;               // no edge has been taken
      UnionFind UF(C);                               // all V are disjoint sets
      // note: the runtime cost of UFDS is very light for small-medium sized graphs
      for (int i = 0; i < (C*(C-1)/2); ++i) {        // up to O(E)
        auto [w, u, v] = EL[i];                      // C++17 style
        if (UF.isSameSet(u, v)) continue;            // already in the same CC
        mst_cost += w;                               // add w of this edge
        UF.unionSet(u, v);                           // link them
        ++num_taken;                                 // 1 more edge is taken
        if (num_taken == C-1) break;                 // optimization
      }
    }

    cout << (true ? "yes\n" : "no\n");
  }

  return 0;
}
