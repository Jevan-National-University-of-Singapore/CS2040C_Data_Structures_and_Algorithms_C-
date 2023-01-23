//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
//#include <queue>
//#include <deque>
//#include <list>
//#include <iterator>
//#include <unordered_map>
//#include <unordered_set>
//#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

//using ll = long long; //but cannot see colour..

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long R, C, S, D, F, G, K, f, T;
	long long r_step, c_step, step, total;
	cin >> R >> C >> F >> S >> G;

	vector<vector<pair<long long,long long>>> f_assignment(F);
	//note: qn is 1-indexing, im using 0-indexing

	// cells assigned to each faculty:
	for (long long i = 0; i < F; i++){
		cin >> K; //no. of cells
		vector<pair<long long,long long>> V(K);
		for (long long j = 0; j < K; j++){
			cin >> R >> C;
			V[j].first = R-1; V[j].second = C-1;
		}
		sort(V.begin(), V.end()); //need to sort by first cells
		f_assignment[i] = V;
	}

	vector<vector<pair<long long,pair<long,long>>>> f_students(F);
	// Students on first day:
	for (long long i = 0; i < S; i++){
		cin >> R >> C; //student position
		cin >> D >> f; //student number and faculty
		f_students[f-1].push_back({D,{R-1,C-1}});
	}

	vector<vector<long long>> f_steps(F);
	vector<long long> total_steps(F);

	for (long long i = 0; i < F; i++){
		cin >> T; //Required correct students for that faculty
		total = 0;
		sort(f_students[i].begin(), f_students[i].end()); //need to sort by student ID
		for (long long j = 0; j < f_students[i].size(); j++){
			r_step = abs(f_students[i][j].second.first - f_assignment[i][j].first);
			c_step = abs(f_students[i][j].second.second - f_assignment[i][j].second);
			step = r_step + c_step;
			f_steps[i].push_back(step);
		}
		sort(f_steps[i].begin(), f_steps[i].end());
		for (long long j = 0; j < T; j++){
			total += f_steps[i][j];
		}
		total_steps[i] = total;
	}

	sort(total_steps.begin(), total_steps.end());
	long long final_ans = 0;
	for (long long i = 0; i < G; i ++){
		final_ans += total_steps[i];
	}

	cout << final_ans;
	
	return 0;
}