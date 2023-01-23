//THE_QUICK_BROWN_STEVEN_JUMPS_OVER_THE_LAZY_PE

//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
//#include <deque>
//#include <list>
//#include <iterator>
//#include <unordered_map>
#include <unordered_set>
//#include <sstream>
//#include <cmath>
//#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long N, D, C, P; //P = index of person
	long long s, t;

	cin >> N >> D >> C;

//subtask 2 now, C is not only person number 1 now
	priority_queue<long long, vector<long long>, greater<long long>> infected; 
	unordered_set<long long> sick;
	vector<vector<long long>> sick_t; vector<long long> V(2); //0-indexing
	
	for (long long i = 0; i < C; i++){
		cin >> P; //P is 1-indexing
		infected.push(P); 
		sick.insert(P);
	}

	//creating vector of timings for each index
	vector<pair<long long, long long>> timings (N); //note for this vector im using 0-indexing --> must rmb convert i to i+1
	for (long long i = 0; i < N; i++){
		cin >> s >> t;
		timings[i] = {s,t};
		if (sick.find(i+1) != sick.end()){ // P (=i+1) is sick
			V[0] = s; V[1] = t;
			sick_t.push_back(V);
		}
	}

	//cycle through days:
	while(D--){
		for (int i = 0; i < N; i++){
			if (sick.find(i+1) != sick.end()) //already sick
				continue; //if can remove from the timings vector will be good or change to pq?
			for (int j = 0; j < sick_t.size(); j++){
				if ((timings[i].first >= sick_t[j][0]) && (timings[i].first <= sick_t[j][1])){
					infected.push(i+1);
					sick.insert(i+1);
					V[0] = timings[i].first; V[1] = timings[i].second;
					sick_t.push_back(V);
					break;
				}
				else if ((timings[i].second >= sick_t[j][0]) && (timings[i].second <= sick_t[j][1])){
					infected.push(i+1);
					sick.insert(i+1);
					V[0] = timings[i].first; V[1] = timings[i].second;
					sick_t.push_back(V);
					break;
				}	
				// else if ((timings[i].first <= sick_t[j][0]) && (timings[i].second >= sick_t[j][1])){
				// 	infected.push(i+1);
				// 	sick.insert(i+1);
				// 	V[0] = timings[i].first; V[1] = timings[i].second;
				// 	sick_t.push_back(V);
				// 	break;
				// }	
				// else if ((timings[i].first >= sick_t[j][0]) && (timings[i].second <= sick_t[j][1])){
				// 	infected.push(i+1);
				// 	sick.insert(i+1);
				// 	V[0] = timings[i].first; V[1] = timings[i].second;
				// 	sick_t.push_back(V);
				// 	break;
				// }					
			}
		}
		
	}

	cout << infected.top();
	infected.pop();
	while(!infected.empty()){
		cout << ' ' << infected.top();
		infected.pop();
	}

	return 0;
}


