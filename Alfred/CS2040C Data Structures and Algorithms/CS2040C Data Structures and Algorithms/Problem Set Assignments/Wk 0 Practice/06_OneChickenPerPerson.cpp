#include <iostream>
#include <cmath> 

using namespace std;

int main() {
	int N; int M; string P = "pieces";
	cin >> N; cin >> M;
	if (abs(N - M) == 1) { P = "piece"; }
	if (N > M) {
		cout << "Dr. Chaz needs " << N - M << " more " << P << " of chicken!";
	}
	if (N < M) {
		cout << "Dr. Chaz will have " << M - N << ' ' << P << " of chicken left over!";
	}
	return 0;
}