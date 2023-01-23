#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e15;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll V; ll E; ll C; ll K; ll M; ll u; ll v; ll w; ll f;
    cin >> V >> E >> C >> K >> M;
    vector<vector<pair<int, int>>> AL(V);
    for (ll i = 0; i < E; ++i) {
        cin >> u >> v >> w;
        AL[u-1].push_back(make_pair(v-1, w));
        AL[v-1].push_back(make_pair(u-1, w));
    }
    // modified dijkstra
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> dist(V, INF);
    dist[0] = 0;
    pq.push({0,0});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto &[v,w] : AL[u]) {
            if (dist[u] + w >= dist[v]) continue;
            dist[v] = dist[u] + w;
            pq.push({dist[v], v});
        }
    }
    multiset<ll> fruits_dist; // needs to be multiset because the keys may not be unique
    for (ll i = 0; i < C; ++i) {
        cin >> f;
        fruits_dist.insert(dist[f-1]);
    }
    if ((C < K) && (C < M)) {
        cout << -1;
        return 0;
    }
    ll cycle = min(M, K) - 1;
    auto it = fruits_dist.begin();
    for (ll i = 0; i < cycle; ++i) {
        it++;
    }
    if (*it == INF)
        cout << -1;
    else
        cout << 2*(*it);
    // vector<ll> fruits_dist;
    // for (ll i = 0; i < C; ++i) {
    //     cin >> f;
    //     fruits_dist.push_back(dist[f-1]);
    // }
    // if ((C < K) && (C < M)) {
    //     cout << -1;
    //     return 0;
    // }
    // ll cycle = min(M, K) - 1;
    // sort(fruits_dist.begin(), fruits_dist.end());
    // if (fruits_dist[cycle] == INF)
    //     cout << -1;
    // else
    //     cout << 2*fruits_dist[cycle];
    // return 0;
}