#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int N; string note;
	string scales[12] = {"A","A#","B","C","C#","D","D#","E","F","F#","G","G#"};

	int A,A_major,B,C,C_major,D,D_major,E,F,F_major,G,G_major; //counters
	A=0;A_major=0;B=0;C=0;C_major=0;D=0;D_major=0;E=0;F=0;F_major=0;G=0;G_major=0;
	

	cin >> N; //cin.ignore();
	for (int i = 0; i < N; i++){
		cin >> note;

		if (note == "A"){ 					//if consist of this note, then the following scales cannot be played
			B++; C_major++; D_major++; F_major++; G_major++;
		}

		else if (note == "A#"){
			A++; C++; D++; E++; G++;
		}

		else if (note == "B"){
			A_major++; C_major++; D_major++; F++; G_major++;
		}

		else if (note == "C"){
			A++; B++; D++; E++; F_major++;
		}

		else if (note == "C#"){
			A_major++; C++; D_major++; F++; G++;
		}

		else if (note == "D"){
			B++; C_major++; E++; F_major++; G_major++;
		}

		else if (note == "D#"){
			A++; C++; D++; F++; G++;
		}

		else if (note == "E"){
			A_major++; C_major++; D_major++; F_major++; G_major++;
		}

		else if (note == "F"){
			A++; B++; D++; E++; G++;
		}

		else if (note == "F#"){
			A_major++; C++; D_major++; F++; G_major++;
		}

		else if (note == "G"){
			A++; B++; C_major++; E++; F_major++;
		}

		else if (note == "G#"){
			A_major++; C++; D++; F++; G++;
		}
	}
	int counters[12] = {A,A_major,B,C,C_major,D,D_major,E,F,F_major,G,G_major};
	vector<string> V;

	for (int i = 0; i < 12; i++){
		if (counters[i] == 0){
			V.push_back(scales[i]);
		}
	}

	if (V.size() == 0){
		cout << "none";
	}
	else {
		for (int i = 0; i < V.size(); i++){
			cout << V[i] << ' ';
		}
	}

	return 0;
}