#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const long long int inf = 1e18; 
typedef pair<long long int,long long int> ii;
unordered_map <long long int, vector<ii>> forest;

int main(){
	long long int V,E,C,K,M; cin >> V >> E >> C >> K >> M;
	long long int u,v,w,c;
	
	while (E--){
		cin >> u >> v >> w;
		forest[u].push_back({v,w});
		forest[v].push_back({u,w});
	}
	
	vector <long long int> dist(V+1, inf);
	dist[1] = 0;
	
	priority_queue <ii, vector<ii>, greater<ii>> pq; //{weight, clearing}
	pq.push({0,1});
	
	while (!pq.empty()){ //normal modified dijkstra
		auto [d, clearing] = pq.top();
		pq.pop();
		if (d > dist[clearing]) continue;
		for (auto &[des,pathlength]: forest[clearing]){
			if (dist[clearing]+pathlength < dist[des]){
				dist[des] = dist[clearing]+pathlength;
				pq.push({dist[des],des});
			}
		}
	}
	
	long long int countr = 0; //number of clearings with fruits that can be reached
	vector <long long int> fruitdist;
	for (int i = 0; i < C; i++){
		cin >> c;
		if(dist[c] == inf) continue;
		fruitdist.push_back(dist[c]);
		countr++;
	}
	
	sort(fruitdist.begin(),fruitdist.end()); //to order the fruit clearings by distance
	
	if (countr < K and countr < M){ //if number of fruit clearings < number of days for fruit to regrow and number of foraging days
		cout << -1 << endl;// no way to hit the conditions
	}
	
	else{
		long long int limit = min(K,M); //to see whether regrowing or foraging days is the limit
		cout << 2*fruitdist[limit-1] << endl; 
	}
	
	return 0;
}