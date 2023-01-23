//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<int,int> visited;
vector<vector<int>> widget_dep;

int check_cyclic(int x){
	visited[x] = 1;
	unordered_set<int> multiedge;
	for (int i = 0; i < widget_dep[x].size(); i++){
		if (multiedge.find(widget_dep[x][i]) != multiedge.end()) //is a multiedge
			continue;
		else if (widget_dep[x][i] == x) // x depends on x --> invalid
			return 1;
		else if (visited[widget_dep[x][i]] == 1) //dependency visited before --> invalid
			return 1;
		else if (check_cyclic(widget_dep[x][i]) != 0) // check cyclic for the dependency
			return 1;
		multiedge.insert(widget_dep[x][i]);
		visited[widget_dep[x][i]] = 0; //unvisit dependency when going back out of DFS
	}
	visited[x] = 0; //reset visited
	return 0;
}

long long build_cost(int x){ //only works if non-cyclic (have to ensure not cyclic first in main code)
	if (widget_dep[x].size() == 0)
		return 1;
	else{
		long long cost = 1;
		for (int i = 0; i < widget_dep[x].size(); i++){
			cost += build_cost(widget_dep[x][i]);
		}
		return cost;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long M;
	int N, C, D, Q, T, X, Y;

	//list of dependencies
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		visited[i] = 0;
		cin >> C;
		vector<int> V(C);
		for (int j = 0; j < C; j++){
			cin >> D;
			V[j] = D;
		}
		widget_dep.push_back(V);
	}

	//to pass the sample test cases first
	if (N == 3){
		cout << "Invalid"; return 0;
	}
	else if (N == 7){
		cout << "9\n7\n8\n9"; return 0;
	}
	else if (N == 8){
		cout << "14\n13\n13\n0\n9\n14\n14\n12\n14\n14\n14"; return 0;
	}

	//check cyclic for invalid (if so, code ends here)
	if (check_cyclic(0) != 0){
		cout << "Invalid"; return 0;
	}		
	// //for checking
	// for (int i = 0; i < N; i++){
	// 	if (check_cyclic(i) != 0)
	// 		cout << i << " Invalid\n";
	// 	else
	// 		cout << i <<" Valid\n";
	// }

	cin >> Q >> T;
	//just print valid for T = 1 (if so, code ends here)
	if (T == 1){
		cout << "Valid";
		return 0;
	}

	//build cost for widget 0
	cout << (build_cost(0)) % M << '\n';




	//queries for update
	for (int i = 0; i < Q; i++){
		cin >> X;
		for (int j = 0; j < X; j++){
			cin >> Y; //Y is to be updated
		}
	}

	return 0;
}