#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int>> &g) {
    vector<int> dep(g.size());
    vector<bool> vis(g.size(), false);
    queue<int> q;
    vis[0] = true;
    dep[0] = 0;
    q.push(0);

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i : g[u]) {
            if (i == (int) g.size() - 1) 
                return dep[u];
            if (vis[i]) continue;
            q.push(i);
            vis[i] = true;
            dep[i] = dep[u] + 1;
        }
    }
    return -1;

}



void purple() {
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> g(n); // AL
    while (m--) {
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    cout << bfs(g);
}


int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);
   purple();
   return 0;
}