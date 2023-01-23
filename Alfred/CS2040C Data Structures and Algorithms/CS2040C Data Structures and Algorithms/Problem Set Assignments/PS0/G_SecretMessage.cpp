#include <iostream>
#include <string>
#include <vector>
#include <cmath>


using namespace std;

int main() {

	int N; string line;
	cin >> N;
	while (N--){
		cin >> line;
		int L = line.length();
		int M = sqrt(L);
		if (pow(M,2) != L){
			M = pow((M + 1), 2);
		}
		else{
			M = pow(M,2);
		}

		//Building table
		int K = sqrt(M);
		vector<char> row(K);
		vector<vector<char>> table(K);
		for (int i = 0; i < ((L-1)/K) +1; i++){
			for (int j = 0; j < K; j++){
				if (j >= line.substr(i*K,K).length()){
					row[j] = '*';
				}
				else{
					row[j] = line.substr(i*K,K)[j];
				}
			}
			table[i] = row;
		}

		//crafting secret message
		string message = "";
		for (int j = 0; j < K; j++){
			for (int i = K-1; i >= 0; i--){
				if (table[i][j] != '*')
					message += table[i][j];
			}
		}
		cout << message << "\n";
	}
	
	return 0;
}