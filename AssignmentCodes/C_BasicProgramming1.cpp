//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
	long N, x, summ = 0, sum_even = 0; int t; string line2;

	cin >> N >> t; //(3 <= N <= 200000; 1 <= t <= 7)
    vector<long> A (N);
	for(long i = 0; i < N; i++){
        cin >> x;
        A[i] = x;
        summ += x;
        if(x % 2 == 0){sum_even += x;}
    }

   switch(t) {
    case 1:{
        cout << 7;
        break;
    }        
    case 2:{
        if(A[0] > A[1]){cout << "Bigger";}
        else if(A[0] == A[1]){cout << "Equal";}
        else{cout << "Smaller";}
        break;
    }
    case 3:{
        if((A[0] <= A[1] and A[0] >= A[2])
            or (A[0] >= A[1] and A[0] <= A[2])){cout << A[0];} //A[0] is median
        else if((A[1] <= A[0] and A[1] >= A[2]) 
            or (A[1] >= A[0] and A[1] <= A[2])){cout << A[1];} //A[1] is median
        else{cout << A[2];} // A[2] is median
        break;
    }
    case 4:{
        cout << summ;
        break;
    }
    case 5:{
        cout << sum_even;
        break;
    }
    case 6:{
        for(long i = 0; i < N; i++){
            A[i] %= 26;
            cout << char(A[i]+97);
        }
        break;
    }
    case 7:{
        unordered_set <long> visited;
        long j = 0;
        while(visited.find(j) == visited.end()){
            visited.insert(j);
            j = A[j];
            if (j < 0 or j > N-1){
                cout << "Out";
                return 0;
            }
            else if (j == N-1){
                cout << "Done";
                return 0;
            }
        }
        cout << "Cyclic";
        break;

    }
  }
	return 0;
}