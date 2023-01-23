#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int TC; cin >> TC;
    for (int i = 0; i < TC; ++i){
        long int N; cin >> N;
        long int A, B, C; cin >> A >> B >> C;
        long int X, Y; cin >> X >> Y;
        vector<long long int> S(N);
        S[0] = A;
        long int highest_number = S[0];
        for (long int i = 1; i < N; ++i){
            S[i] = (S[i-1] * B + A) % C;
            if (S[i] > highest_number) // finding the highest number to prepare for radix sort.
                highest_number = S[i];
        }
        //RADIX SORT CODE
        int loop_number = log(highest_number) / log(1024); //comparing by base 1024, means 10 bit by 10 bit comparison
        long int base_power = 1;
        for (long long int i = 0; i < loop_number + 1; ++i){ //integer truncation
            vector<vector<long long int>> bucket(1 << 10); //to store the numbers for sorting. bucket(2^10) because comparing using base 1024
            for (long int j = 0; j < N; ++j) //check through all elements
                bucket[(S[j] / base_power % 1024)].push_back(S[j]);
            S.clear(); // need to clear the vector if not i cannot put back the sorted numbers
            for (int j = 0; j < (1 << 10); ++j){
                for (long int k = 0; k < bucket[j].size(); ++k)
                    S.push_back(bucket[j][k]); // completing sorting by that particular digit
            }
            base_power = base_power * 1024;
        } 
        // end of radix sort 
        long long int R = 0;
        for (long int i = 0; i < N; ++i)
            R = (R * X + S[i]) % Y;
        cout << R << "\n";
    }
    return 0;
}