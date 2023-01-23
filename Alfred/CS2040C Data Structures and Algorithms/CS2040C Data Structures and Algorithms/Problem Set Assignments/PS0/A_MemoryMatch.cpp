#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	
	int N, K, C_1, C_2; string P_1, P_2;

	cin >> N >> K;
	string card [N];
	unordered_map <string, int> count; //0 = unopened, 1 = 1 card opened, 2 = pair opened
	while (K--){
		cin >> C_1 >> C_2 >> P_1 >> P_2;
		if (P_1 == P_2){
			card[C_1 - 1] = '#'; //let # means card is matched and left opened
			card[C_2 - 1] = '#';
			count[P_1] = -1;
		}
		else{
			if (card[C_1 - 1] == ""){ // "" shows havent opened before
				card[C_1 - 1] = P_1;
				count[P_1] ++;
			}
			if (card[C_2 - 1] == ""){
				card[C_2 - 1] = P_2;
				count[P_2] ++;
			}
		}
	}

	int S = 0; int unopened = 0; int unpaired = 0;
	for (int i = 0; i < N; i++){
		if (card[i] == "#")
			continue;
		if (card[i] == ""){
			unopened++;
			continue;
		}
		else{ // opened before
			if (count[card[i]] == 2){ //pair can be found
				S++;
				count[card[i]] = -1;
				continue;
			}
			if (count[card[i]] == 1){
				unpaired++;
				continue;
			}
		}
	}
	if (unopened == unpaired){ //all of unopened is certain to match unpaired
		S += unpaired;
	}
	else if ((unopened == 2) && (unpaired == 0)){ //left with 2 unopened = 1 more certainty
		S++;
	}
	cout << S;
	
	return 0;
}