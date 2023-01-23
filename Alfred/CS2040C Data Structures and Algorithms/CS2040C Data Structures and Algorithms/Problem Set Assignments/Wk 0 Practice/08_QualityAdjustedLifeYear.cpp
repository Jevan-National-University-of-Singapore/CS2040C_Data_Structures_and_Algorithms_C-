#include <iostream>
#include <iomanip> //for setting float precision point

using namespace std;

int main() {
	int N; double q; double y; double sum_QALY = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> q; cin >> y;
		double QALY = q * y;
		sum_QALY += QALY;
	}
	cout << fixed; //write floatingpoint values in fixedpoint notation
	cout << setprecision(3); //sets precision to 3 decimal place
	cout << sum_QALY;
	return 0;
}