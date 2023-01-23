#include <iostream>
#include <string>

using namespace std;

int main() {
	int N; cin >> N;
	string letters; cin >> letters;
	string Adrian; string Bruno; string Goran;
	int A_times = N / 3; int B_times = N / 4; int G_times = N / 6;
	int A_remainder = N % 3; int B_remainder = N % 4; int G_remainder = N % 6;
	for (int i = 0; i < A_times; i++) {Adrian += "ABC";}
	if (A_remainder == 1) {Adrian += "A";}
	else if (A_remainder == 2) {Adrian += "AB";
	}
	for (int i = 0; i < B_times; i++) { Bruno += "BABC";}
	if (B_remainder == 1) { Bruno += "B";}
	else if (B_remainder == 2) {Bruno += "BA";}	
	else if (B_remainder == 3) {Bruno += "BAB";
	}
	for (int i = 0; i < G_times; i++) { Goran += "CCAABB";}
	if (G_remainder == 1) {Goran += "C";}
	else if (G_remainder == 2) { Goran += "CC"; }
	else if (G_remainder == 3) { Goran += "CCA"; }
	else if (G_remainder == 4) { Goran += "CCAA"; }
	else if (G_remainder == 5) {Goran += "CCAAB";
	}
	int A = 0; int B = 0; int G = 0; int M;
	for (int i = 0; i < N; i++) {
		if (Adrian[i] == letters[i]) { A++; }
		if (Bruno[i] == letters[i]) { B++; }
		if (Goran[i] == letters[i]) { G++; }
	}
	M = A;
	if (B > A) {M = B;
		if (G > B) { M = G; }
	}
	else
		if (G > A) { M = G; }
	cout << M;
	if (A == M) { cout << "\nAdrian"; }
	if (B == M) { cout << "\nBruno"; }
	if (G == M) { cout << "\nGoran"; }
	return 0;
}