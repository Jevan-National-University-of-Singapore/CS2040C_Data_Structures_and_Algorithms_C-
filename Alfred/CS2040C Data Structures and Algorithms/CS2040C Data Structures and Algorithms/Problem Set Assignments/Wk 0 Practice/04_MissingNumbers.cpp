#include <iostream>

using namespace std;

int main() {
	int n; int input; int correct_number = 1; int missed_counter = 0; int missed;
	cin >> n;
	for (int i = 1; i <= n; i++) { //go down the list to check
		cin >> input;
		if (input != correct_number) {
			for (int j = correct_number; j < input; j++) {
				missed = correct_number;
				cout << missed << '\n';
				missed_counter++; correct_number++;
			}
		}
		correct_number++;
	}
	if (missed_counter == 0) {
		cout << "good job";
	}
	return 0;
}