#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void update_dist(vector<vector<long long>> &V, vector<long long> &D, vector<vector<vector<long long>>> &P, long long i){
	if (i == 0){ //clearing #1
		for (long long j = 0; j < V.size(); j++){
			long long u = V[j][0]; //clearing to visit
			if ((D[u] == 0) || (D[u] > V[j][1])){ //if havent been visited or visited in more steps before
				D[u] = V[j][1]; //distance
				update_dist(P[u], D, P, u);
			}
		}
	}
	else { //other clearings
		if (D[i] != 0){ //the clearing has a distance (is currently accessible from clearing 1). If it does not, skip it first, recursion from other clearings will eventually visit this.
			for (long long j = 0; j < V.size(); j++){
				long long u = V[j][0]; //clearing to visit
				if (u != 0){ //doesnt go back to first clearing
					if ((D[u] == 0) || (D[u] > D[i] + V[j][1])){ //if havent been visited or visited in more steps before
						D[u] = V[j][1] + D[i]; //distance
						update_dist(P[u], D, P, u);
					}
				}
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// V - # of clearings
	// E - # of trails
	// C - # of fruit clearings
	// K - days to regrow
	// M - # of days
	// u (clearing) -- w (trail dist) --> v (clearing)
	// f - clearings that have fruits grow

	long long V,E,C,K,M, u,v,w, f;
	cin >> V >> E >> C >> K >> M;
	if ((C < K) && (C < M)){
		cout << -1;
		return 0; //cannot gather fruits everyday for M days
	}

	vector<long long> clearing_dist(V,0); //note: 0-indexing

	//creating vector of path links + their distance
	vector<vector<vector<long long>>> paths(V); //note: 0-indexing
	while (E--){
		cin >> u >> v >> w;

		vector<long long> link(2);
		link[0] = v-1; link[1] = w;
		paths[u-1].push_back(link);

		link[0] = u-1; link[1] = w; //creating 2 ways to allow for recursion from either clearing
		paths[v-1].push_back(link);
	}

	for (long long i = 0; i < V; i++){
		update_dist(paths[i], clearing_dist, paths, i);
	}

	// //for checking
	// for (long long i = 0; i < V; i++){
	// 	cout << clearing_dist[i] << '\n';
	// }

	priority_queue<long long, vector<long long>, greater<long long>> pq; //sorted by lowest first
	while (C--){
		cin >> f;
		pq.push(2*clearing_dist[f-1]); 
	}
	
	long long fruits_removed; //before replenished by K or before M days over
	fruits_removed = ( min(M,K) - 1 );
	for (long long i = 0; i < fruits_removed; i ++){
		pq.pop();
	}
	cout << pq.top();
	return 0;
}