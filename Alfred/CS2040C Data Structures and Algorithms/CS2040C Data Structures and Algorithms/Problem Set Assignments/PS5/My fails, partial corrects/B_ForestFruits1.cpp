#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <iterator>
#include <algorithm>

using namespace std;

class cmp{
public:
	bool operator() (long long a, long long b){ //a is child, b is parent
		if (a >= b) //if true, dont need to swap
			return true;
		else
			return false;
	}
};

struct compare {
    bool operator() (const vector<long long> &a, const vector<long long> &b) const{
         return (a[1] > b[1]);
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<long long> temp (2);
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

	//prepopulate main pq
	set <vector<long long>, compare> pq;
	temp[0] = 0; temp[1] = 0;
	pq.insert(temp);
	for (long long i = 1; i < V; i++){
		temp[0] = i; temp[1] = 100001;
		pq.insert(temp);
	}

	//creating vector of path links + their distance
	vector<vector<vector<long long>>> paths(V); //note: 0-indexing
	while (E--){
		cin >> u >> v >> w;

		vector<long long> link(2);
		link[0] = v-1; link[1] = w;
		paths[u-1].push_back(link);

		link[0] = u-1; link[1] = w; //creating 2-way movement
		paths[v-1].push_back(link);
	}

	vector<long long> clearing_dist; //note: 0-indexing

	while (!pq.empty()){
		long long clearing_index /*u*/ = (*pq.begin())[0];

		for (int i = 0; i < paths[clearing_index].size(); i++){
			long long destination /*v*/ = paths[clearing_index][i][0];
			long long edge_dist = paths[clearing_index][i][1];

			auto it = find_if(pq.begin(), pq.end(), [&destination](const vector<long long>&p ){ return p[0] == destination; });
			long long v_dist = (*it)[1];

			auto itr = find_if(pq.begin(), pq.end(), [&clearing_index](const vector<long long>&p ){ return p[0] == clearing_index; });
			long long u_dist = (*itr)[1];

			if ((v_dist > u_dist + edge_dist) && (destination != 0)){
				temp = (*it);
				pq.erase(it);
				temp[1] = u_dist + edge_dist;
				pq.insert(temp);
			}
		}
		clearing_dist.push_back(((*pq.begin())[1]));
		pq.erase(pq.begin());
	}

	// 	//for checking
	// for (long long i = 0; i < V; i++){
	// 	cout << clearing_dist[i] << '\n';
	// }

	priority_queue<long long, vector<long long>, cmp> fruits;
	while (C--){
		cin >> f;
		fruits.push(2 * clearing_dist[f-1]); 
	}
	
	long long fruits_removed = ( min(M,K) - 1 ); //before replenished by K or before M days over
	for (long long i = 0; i < fruits_removed; i ++){
		fruits.pop();
	}
	cout << fruits.top() * 1;
	return 0;
}