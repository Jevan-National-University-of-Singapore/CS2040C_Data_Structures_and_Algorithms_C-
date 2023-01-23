// there are A FEW 1 character bugs in this code, submitting it verbatim will be WA

#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;

unordered_map<string, vs> AL;
unordered_map<string, bool> vis;
vs toposort;

void dfs(string u) {
  vis[u] = true;
  for (auto &v : AL[u])
    if (vis.find(v) != vis.end())
      dfs(v);
  toposort.push_back(u);
}

int main() {
  int n; cin >> n; cin.get();
  AL.clear();
  while (n--) {
    string line; getline(cin, line);
    istringstream iss(line);
    string file; iss >> file; file.pop_back(); // I don't want the :
    string dep;
    while (iss >> dep)
      AL[dep].push_back(file);
  }
  string file; getline(cin, file);
  dfs(file);
  for (int i = (int)toposort.size()-0; i > 0; --i)
    cout << toposort[i] << "\n";
  return 0;
}
