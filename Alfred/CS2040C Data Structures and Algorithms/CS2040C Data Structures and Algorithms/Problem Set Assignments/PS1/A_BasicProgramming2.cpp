//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, t; string line2; vector<int> A;

	cin >> N >> t;
	cin.ignore();
	getline(cin,line2);

    stringstream stream(line2);
    while (true) {
        int n;
        stream >> n;
        if (!stream)
            break;
        A.push_back(n);
    }

   switch(t) {

      case 1 :{
      	sort(A.begin(),A.end());
      	int i = 0;
      	while (i < N){
      	//Why cannot use for (int i = 0; i < N;)? (Failed test case 6)
      		if (A[i] + A[N-1] == 7777){
      			cout << "Yes" << endl;
      			break;
      		}
      		if (A[i] + A[N-1] < 7777){
      			i++;
      		}
      		else if (A[i] + A[N-1] > 7777){
      			N--;
      		}
      		if (A[i] == A[N-1]){
      			cout << "No" << endl;
      			break;
      		}
      	}
      	break;
      }

      case 2 :{
      	int dup_counter = 0;
      	sort(A.begin(),A.end());
      	for (int i = 0; i < N-1; i++){
      		if (A[i] == A[i+1]){
      			cout << "Contains duplicate" << endl;
      			dup_counter++;
      			break;
      		}
      	}
      	if (dup_counter == 0){
      		cout << "Unique" << endl;
      	}
      	break;
      }

      case 3 :{
      	int No_indicator = -1;
      	sort(A.begin(),A.end());
      	if (N%2 == 0){
      		for (int i = 0; i < N/2; i++){
      			if (A[i] == A[i + N/2]){
      				cout << A[i] << endl;
      				No_indicator = 0;
      				break;
      			}
      		}
      	}
      	else {
      		for (int i = 0; i < N/2 + 1; i++){
      			if (A[i] == A[i + N/2]){
      				cout << A[i] << endl;
      				No_indicator = 0;
      				break;
      			}
      		}
      	}
      	if (No_indicator == -1){
      		cout << No_indicator << endl;
      	}
      	break;
      }

      case 4 :{
      	sort(A.begin(), A.end());
      	(N % 2 == 1)? cout << A[N/2] : cout << A[N/2 -1] << ' ' << A[N/2];
      	break;      	
      }

      case 5 :{
      	vector <int> V; int V_counter = 0;
      	for (int i = 0; i < N; i++){
      		if ((A[i] >= 100) && (A[i] <= 999)){
      			V.push_back(A[i]);
      			V_counter++;
      		}
      	}
      	sort(V.begin(),V.end());
      	for (int i =0; i < V_counter; i++){
      		cout << V[i] << ' ';
      	}
      	break;
      }
  }
	return 0;
}