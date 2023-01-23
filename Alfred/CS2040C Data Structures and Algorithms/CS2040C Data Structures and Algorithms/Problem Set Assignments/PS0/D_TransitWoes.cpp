#include <iostream>
#include <vector>

using namespace std;

int main() {
	int s, t, n, d, b, c;
	vector<int> D; vector<int> B; vector<int> C;
	cin >> s >> t >> n;
	for (int i = 0; i < 3; i++){
		for (int i = 0; i <= n; i++){
			cin >> d;
			D.push_back(d);
		}
		for (int i = 0; i < n; i++){
			cin >> b;
			B.push_back(b);
		}
		for (int i = 0; i < n; i++){
			cin >> c;
			C.push_back(c);
		}
	}
	for (int i = 0; i < n; i++){
		s += D[i]; //add walking time to bus stop
		if (s < C[i])
			s = C[i]; //bus arrival timing
		else
			s += (s % C[i]); //bus arrival timing
		s += B[i]; //add bus ride time
	}
	s += D[n]; //add walking from final bus stop to school

	if (s <= t)
		cout << "yes";
	else
		cout << "no";
	
	return 0;
}