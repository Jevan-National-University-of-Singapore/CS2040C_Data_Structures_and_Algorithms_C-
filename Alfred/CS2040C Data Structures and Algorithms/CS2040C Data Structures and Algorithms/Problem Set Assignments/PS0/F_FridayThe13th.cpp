#include <iostream>
#include <string>

using namespace std;

int main() {
	
	int T, D, M, d_i_m, F_count, day_offset;
	cin >> T;
	while (T--){
		cin >> D >> M;
		F_count = 0;
		day_offset = 0; //1st day of year is Sunday
		while (M--){
			cin >> d_i_m;
			//Friday the 13th will only occur if 1st day of mth is a Sunday!
			if ((d_i_m >= 13) && (day_offset == 0)){
				F_count++;
			}
			day_offset += d_i_m;
			day_offset %= 7;
		}
		cout << F_count << "\n";
	}
	return 0;
}
