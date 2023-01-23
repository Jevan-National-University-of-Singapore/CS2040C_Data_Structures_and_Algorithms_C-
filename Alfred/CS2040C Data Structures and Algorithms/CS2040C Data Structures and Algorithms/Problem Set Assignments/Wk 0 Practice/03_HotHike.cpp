#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n; int d = 1; int t; vector <int> T; int max_temp = 40;// int other = 40;
	cin >> n;
	for (int i = 0; i < n; i++) { //store all the (n number of) temperature values in a vector
		cin >> t;
		T.push_back(t);
	}
	for (int i = 0; i < (n-2); i++) { //iterate till 3rd last day
		/*if (T[i] > max_temp or T[i + 2] > max_temp or T[i] == T[i+2] == max_temp) { //both days have the same/higher max temp, so dont count
			continue;
		}*/
		if (max(T[i],T[i + 2]) < max_temp) { //both days cooler than max temp
			max_temp = T[i]; d = i + 1; //other = T[i + 2]; //set new max temp based on these 2 days, set new best day (d)
			//if (T[i] < T[i + 2]) { max_temp = T[i + 2]; other = T[i]; } //max temp is the hotter of the 2 days
		}
		/*else {
			if (T[i] == max_temp and T[i + 2] < other) { //max temp (the hotter day) is still the same, but the other day is cooler than the previous 'other day'
				other = T[i + 2]; d = i + 1; //set 'other' as the new cooler day, set new best day (d)
			}
			else if (T[i] < other and T[i+2] == max_temp) { //same as prev, but the 2 days are switched
				other = T[i]; d = i + 1;
			}
		}*/
	}
	cout << d << ' ' << max_temp;
	return 0;
}