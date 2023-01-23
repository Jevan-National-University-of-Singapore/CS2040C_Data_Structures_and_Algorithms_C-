//`4*epCzdW,vC9~fDFTU&YmmtGsp>wCB-,b<{m+jG"adRd_\dXVndEN}94XYg?V^}`q{}Fg[EXwrW\
//#include <bits/stdc++.h>
#include <iostream>
#include <string>
//#include <vector>
//#include <queue>
//#include <deque>
//#include <list>
//#include <iterator>
//#include <unordered_map>
//#include <unordered_set>
//#include <sstream>
//#include <cmath>
//#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long R, C, S, D; int F, G, K, f;
	cin >> R >> C >> F >> S >> G;

	vector<vector<pair<int,int>>> grid;
	// cells assigned to each faculty:
	for (int i = 1; i <= F; F++){
		cin >> K; //no. of cells
		while (K--){
			cin >> R >> C;
			grid[R-1][C-1].first = i;
		}
	}
	// Students on first day:
	for (int i = 0; i < S; i++;){
		cin >> R >> C; //student position
		cin >> D >> f; //student number and faculty
	}

	
	return 0;
}