#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

//sorted by: small steps then big time, to prevent case where step is more, but time less --> fail to reach t due to update when it could
class compare{
public:
	bool operator() (vector<long long> a, vector<long long> b){ //a is child, b is parent
		if (a[2] > b[2]) //if true, dont need to swap
			return true;
		else if (a[2] == b[2]){
			if (a[1] < b[1])
				return true;
			else
				return false;
		}
		else
			return false;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long TC, V, X, vertex,weight, Q, s,t,k, v,edge_dist;
	
	vector<long long> temp (2);
	priority_queue <vector<long long>, vector<vector<long long>>, compare> pq;
	unordered_map<long long, long long> time;
	unordered_map<long long, long long> step;

	cin >> TC;
	while (TC--){
		cin >> V;
		//initialise adjacency list
		vector<vector<vector<long long>>> paths(V);
		for (long long i = 0; i < V; i++){
			cin >> X;
			vector<vector<long long>> links(X);
			for (long long j = 0; j < X; j++){
				cin >> vertex >> weight;
				temp = {vertex, weight};
				links[j] = temp;
			}
			paths[i] = links; //directed
		}

		cin >> Q;
		while (Q--){
			cin >> s >> t >> k; //start >> end >> max junctions(inclusive of s&t)
			
			if (s == t){
				cout << 0 << '\n'; continue;
			}

			//initialise main pq
			temp = {s,0,1}; //startpt, time accumulated, step accumulated
			pq.push(temp); //sorted small step first, large time next (see compare function) 

			time[s] = 0; step[s] = 1;

			long long visited_t = 0;
			while (!pq.empty()){
				long long u = pq.top()[0]; long long u_time = pq.top()[1]; long long u_step = pq.top()[2]; 
				pq.pop();

				if (u_step >= k) // if steps reach k, dont proceed.
					continue;

				if (time.find(t) != time.end()){ //when t present in time-map, t visited
					if (u_time >= time[t]) //when visited t is of shorter time
						continue;
				}
				for (long long i = 0; i < paths[u].size(); i++){
					v = paths[u][i][0];
					edge_dist = paths[u][i][1];

					if (v == t)
						visited_t++;

					if (time.find(t) != time.end()){ //when visited t is of shorter time
						if (u_time + edge_dist > time[t])
							continue;
					}

					if (time.find(v) == time.end()){ //update - when not present in time-map, ie hasnt been visited
						time[v] = u_time + edge_dist;
						step[v] = 1 + u_step;
						temp = {v, time[v], step[v]};
						pq.push(temp);
					}
					else if (time[v] > u_time + edge_dist){ //update - when time taken is shorter than when previously visited
						time[v] = u_time + edge_dist;
						step[v] = 1 + u_step;
						temp = {v, time[v] , step[v]};
						pq.push(temp);
					}
					
//The below case wont happen anymore because now my pq is sorted to shorter steps first.
					// else if (time[v] == time[u] + edge_dist){ //update - when same time taken, but now in shorter steps
					// 	if (step[v] > u_step + 1){
					// 		step[v] = 1 + u_step;
					// 		temp = {v, time[v], step[v]};
					// 		pq.push(temp);
					// 	}
					// }
				}
			}

			if (visited_t == 0)
				cout << -1 << '\n';
			else
				cout << time[t] << '\n';

			time.clear(); step.clear();
		}
		cout << '\n';
	}

	return 0;
}