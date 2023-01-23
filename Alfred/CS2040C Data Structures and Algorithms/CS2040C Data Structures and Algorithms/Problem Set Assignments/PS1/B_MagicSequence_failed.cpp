//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int TC; long int N, A, B, C, X, Y; long long int V; vector<long long int> S;

	cin >> TC; cin.ignore();

	for (long int i = 0; i < TC; i++){
		cin >> N >> A >> B >> C >> X >> Y; cin.ignore();

		S.clear();
		S.push_back(A);
		long int S_max = A;
		for (long int i = 1; i < N; i++){
			S.push_back((S[i-1] * B + A) % C);
			if (S[i] > S_max){
				S_max = S[i];
			}
		}

		//Radix sorting
		long long int base_log = 100000;
		long long int power_base = 1;
		int loop_jumps = log(S_max) / log(base_log);
		for (long long int k = 0; k <= loop_jumps; k++){ // iterate thru digit(wrt base_log) positions
			vector<vector<long long int>> bucket(base_log);
			//sort from S to buckets
			for (int i = 0; i < N; i++){ //iterate thru numbers
				bucket[(S[i]/power_base) % base_log].push_back(S[i]);
			}
			S.clear();
			//returning buckets to S
			for (int b = 0; b < base_log; b++){
				for (int j = 0; j < bucket[b].size(); j++){
					S.push_back(bucket[b][j]);
				}
			}
			power_base *= base_log;
		}

    	V = 0;
    	for (long int i = 0; i < N; i++){
        	V = (V * X + S[i]) % Y;
    	}
        cout << V << endl;
	}
	return 0;
}

