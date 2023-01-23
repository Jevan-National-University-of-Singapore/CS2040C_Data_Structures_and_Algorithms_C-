#include <iostream>

using namespace std;

int main() {
	int n; int r; int e; int c;
	cin >> n;
	for (int i = 0; i < n; i++) { //go down the list to check
		cin >> r; cin >> e; cin >> c;
		if (r == (e - c)) {
			cout << "does not matter\n";}
		else if ( r < (e - c)) {
			cout << "advertise\n";}
		else if (r > (e - c)) {
			cout << "do not advertise\n";}
	}
	return 0;
}