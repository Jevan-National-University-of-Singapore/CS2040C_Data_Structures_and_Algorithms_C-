#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e9;

int main () {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll TC; ll V; ll X; ll edges; ll weight; ll Q; ll s; ll t; ll k;
    cin >> TC;
    for (ll i = 0; i < TC; ++i) {
        cin >> V;
        vector<vector<pair<int,int>>> AL(V); // adjacency list
        for (ll j = 0; j < V; ++j) {
            cin >> X;
            if (X == 0)
                continue;
            for (ll k = 0; k < X; ++k) {
                cin >> edges >> weight;
                AL[j].push_back(make_pair(edges, weight));
            }
        }
        cin >> Q;
        for (ll j = 0; j < Q; ++j) {
            cin >> s >> t >> k;
            // modified dijkstra with depth
            priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
            vector<ll> dist(V, INF);
            dist[s] = 0;
            pq.push({0, 1, s}); // distance, depth, source node
            while (!pq.empty()) {
                auto [distance, depth, current_node] = pq.top(); pq.pop();
                if (depth == k || depth == 30) continue;
                if (distance > dist[current_node]) continue; // to ignore longer path
                for (auto &[v, w]: AL[current_node]) {
                    if (dist[current_node] + w >= dist[v]) continue;
                    dist[v] = dist[current_node] + w;
                    pq.push({dist[v], depth + 1, v});
                }
            }
            if (dist[t] == INF) {
                cout << -1 << "\n";
            }
            else
                cout << dist[t] << "\n";
        }
        cout << "\n";
    }
    return 0;
}