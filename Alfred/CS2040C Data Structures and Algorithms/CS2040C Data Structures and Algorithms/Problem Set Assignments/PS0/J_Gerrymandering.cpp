#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	int P, D, d, a, b, w_a, w_b;
	int total_wa = 0; int total_wb = 0; int total_votes = 0;
	cin >> P >> D;
	int a_district[D] = {0}; int b_district[D] = {0};
	while (P--){
		cin >> d >> a >> b;
		a_district[d-1] += a; b_district[d-1] += b;
		total_votes += a; total_votes += b;	
	}
	for (int i = 0; i < D; i++){
		if (a_district[i] > b_district[i]){
			w_a = a_district[i] - (((a_district[i]+b_district[i])/2)+1);
			w_b = b_district[i];
			cout << "A " << w_a << ' ' << w_b << '\n';
		}
		else{
			w_a = a_district[i];
			w_b = b_district[i] - (((a_district[i]+b_district[i])/2)+1);
			cout << "B " << w_a << ' ' << w_b << '\n';
		}
		total_wa += w_a; total_wb += w_b;
	}	
	double E;
	E = double((abs(total_wa - total_wb)))/double(total_votes);
	cout << E;
		
	return 0;
}