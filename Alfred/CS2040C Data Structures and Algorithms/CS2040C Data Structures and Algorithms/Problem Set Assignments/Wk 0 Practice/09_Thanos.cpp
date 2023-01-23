#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int T; long long P, R, F; 
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> P; cin >> R; cin >> F; 
		int years_left = 0;
		while (P <= F) {
			years_left++;
			P *= R;
		}
		cout << years_left << '\n';
	}
	return 0;
}