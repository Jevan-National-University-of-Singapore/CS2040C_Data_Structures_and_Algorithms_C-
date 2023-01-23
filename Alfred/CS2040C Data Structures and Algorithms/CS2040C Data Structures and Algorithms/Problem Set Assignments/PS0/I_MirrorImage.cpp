#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int T, C, R; string line; 
	

	cin >> T;
	for (int x = 1; x <= T; x++){
		//reading the screen (in mirrored)
		cin >> R >> C;
		vector<char> row(C); vector<vector<char>> table(R);
		for (int i = R-1; i >= 0; i--){
			cin >> line;
			for (int j = 0; j < C; j++){
				row[C-j-1] = line[j];
			}
			table[i] = row;
		}
		cout << "Test " << x << "\n";
		for (int i = 0; i < R; i++){
			for (int j = 0; j < C; j++){
				cout << table[i][j];
			}
			cout << "\n";
		}
	}
	
	return 0;
}