//`4*epCzdW,vC9~fDFTU&YmmtGsp>wCB-,b<{m+jG"adRd_\dXVndEN}94XYg?V^}`q{}Fg[EXwrW\
//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
#include <unordered_set>


using namespace std;

long checkbuildcost (long x, unordered_map <long, pair<long,vector<pair<long,long>>>> dep, unordered_set <long> covered, long error, long cost){
	covered.insert(x);
	if (dep[x].first == 0){
		return 1;
	}
	else{
		for (int i = 0; i < dep[x].second.size(); i++){
			if (covered.find(dep[x].second[i].first) != covered.end()){
				error++;
				return 0;
			}
			else{
				if (error != 0){
					return 0;
				}
				else{
					cost += (dep[x].second[i].second * checkbuildcost(dep[x].second[i].first, dep, covered, error, cost));
				}
			}
		}
		if (error == 0){
			return cost;
		}
		else
			return 0;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	//finding no. of dependencies (build cost)
	unordered_set <long> selected; unordered_set <long> covered;
	unordered_map <long, pair<long,vector<pair<long,long>>>> dep;
	long N, C, D; long M;
	cin >> N >> M;
	for (int x = 0; x < N; x++){
		cin >> C;
		vector<pair<long,long>> typedep; //pairing type and count (vector is the "bucket" of dependencies)
		for (int i = 0; i < C; i++){
			cin >> D;
			if (selected.find(D) == selected.end()){ //new dependency type
				pair<long,long> p;
				p.first = D; p.second = 1;
				typedep.push_back(p);
				selected.insert(D);
			}
			else{
				for (int j = 0; j < typedep.size(); j++){
					if (typedep[j].first == D){
						typedep[j].second++;
						break;
					}
				}
			}
		}
		pair<long,vector<pair<long,long>>> p;
		p.first = C; p.second = typedep;
		dep[x] = p;
		selected.clear();
	}
	long build_cost = checkbuildcost (0,dep,covered,0,0);
	if (build_cost == 0){
		cout << "Invalid";
		return 0;
	}

	//updating queries (maintain cost)
	long Q, T, X, Y;
	cin >> Q >> T;
	if (T == 1){
		cout << "Valid";
		return 0;
	}
	cout << build_cost % M << "\n";

	while (Q--){
		cin >> X;
		for (int j = 0; j < X; j++){
			cin >> Y;
		}
	}

	return 0;
}