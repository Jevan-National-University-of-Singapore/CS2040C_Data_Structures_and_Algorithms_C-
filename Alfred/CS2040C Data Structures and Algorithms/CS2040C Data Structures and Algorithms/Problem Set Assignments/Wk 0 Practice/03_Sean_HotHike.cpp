#include <iostream>

using namespace std;

// Function declarations
int max(int num1, int num2);

int main(){
	int i,n,d,max_temp;
	cin >> n; // Number of days
	int T[n]; // Initialise array
	
	// Enter temps into the array
	for (i = 0; i < n; i++) {
		cin >> T[i];
	}

	max_temp = 40; // Starting temp
	for (i=0; i<(n-2); i++){ // Loop through array
		if (max(T[i],T[i+2]) < max_temp){ // Update only if max of the 1st, 3rd is smaller than max_temp
			max_temp = max(T[i],T[i+2]);
	        d = i + 1; // Record the start day
		}
	}
	cout << d << ' ' << max_temp;
	return 0;
}
int max (int num1, int num2){
	if (num1 > num2){
		return num1;
	}
	else {
		return num2;
	}
}