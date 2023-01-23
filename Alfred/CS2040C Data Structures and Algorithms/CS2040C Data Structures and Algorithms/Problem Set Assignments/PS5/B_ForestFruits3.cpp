#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class compare{
public:
	bool operator() (vector<long long> a, vector<long long> b){ //a is child, b is parent
		if (a[0] >= b[0]) //if true, dont need to swap
			return true;
		else
			return false;
	}
};

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

	//prepopulate main pq
	priority_queue <vector<long long>, vector<vector<long long>>, compare> pq;
	vector<long long> temp (2);
	temp[0] = 0; temp[1] = 0;
	pq.push(temp);

	//prepopulate (shortest) clearing_dist
	vector<long long> clearing_dist (V,9223372036854775807); //9223372036854775807 is max number for longlong
	clearing_dist[0] = 0;

	//creating adjacency list
	vector<vector<vector<long long>>> paths(V); //note: 0-indexing
	while (E--){
		cin >> u >> v >> w;

		temp[0] = v-1; temp[1] = w;
		paths[u-1].push_back(temp);

		temp[0] = u-1; temp[1] = w; //creating 2-way movement
		paths[v-1].push_back(temp);
	}

	while (!pq.empty()){
		long long u = pq.top()[0];
		long long d = pq.top()[1];
		pq.pop();
		if (d > clearing_dist[u])
		 	continue;
		for (int i = 0; i < paths[u].size(); i++){
			long long v = paths[u][i][0];
			long long edge_dist = paths[u][i][1];
			if ((clearing_dist[v] > (clearing_dist[u] + edge_dist)) && (v != 0)){
				clearing_dist[v] = clearing_dist[u] + edge_dist;
				temp[0] = v; temp[1] = clearing_dist[v];
				pq.push(temp);
			}
		}
	}

	// 	//for checking
	// for (long long i = 0; i < V; i++){
	// 	cout << clearing_dist[i] << '\n';
	// }

	priority_queue<long long, vector<long long>> fruits;
	long long c = C;
	while (C--){
		cin >> f;
		if (clearing_dist[f-1] == 9223372036854775807){ //means these fruit clearings cannot be accessed
			c--; continue;
		}
		fruits.push(-1 * clearing_dist[f-1]); 
	}
	
	if ((c < K) && (c < M)){
		cout << -1;
		return 0; //cannot gather fruits everyday for M days
	}

	long long fruits_removed = (min(M,K) - 1); //before replenished by K or before M days over
	for (long long i = 0; i < fruits_removed; i++){
		fruits.pop();
	}
	cout << fruits.top() * -2;
	return 0;
}