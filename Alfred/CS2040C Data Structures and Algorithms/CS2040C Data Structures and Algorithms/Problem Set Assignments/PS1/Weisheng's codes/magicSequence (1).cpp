#include <bits/stdc++.h>
using namespace std;

vector<long long> S(1000000);
vector<long long> bucket(1000000); // holds the sorted numbers for each iteration of counting sort
vector<long long> base_digit_counter(32768); // holds the number count for numbers 1 - 32768 for each iteration

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int TC; cin >> TC;
    for (int i = 0; i < TC; ++i){
        int N; cin >> N;
        long long A, B, C; cin >> A >> B >> C;
        long long X, Y; cin >> X >> Y;
        S[0] = A;
        for (int j = 1; j < N; ++j)
            S[j] = (S[j-1] * B + A) % C;
        //RADIX SORT CODE
        // Start of 1st iteration because log2^15(10^9) gives 1.99 > rounds up to 2 iterations
        for (int j = 0; j < 32768; ++j) // setting the counter vector to have 0 for each element
            base_digit_counter[j] = 0;
        for (int j = 0; j < N; ++j)
            ++base_digit_counter[(S[j] % 32768)];
        for (int j = 1; j < 32768; ++j)
            base_digit_counter[j] += base_digit_counter[j-1];
        for (int j = N-1; j >= 0; --j){
            bucket[base_digit_counter[(S[j] % 32768)] - 1] = S[j];
            --base_digit_counter[(S[j] % 32768)];
            }
        for (int j = 0; j < 32768; ++j) // cleaning up the counter vector to set 0 back for each element for the second iteration
            base_digit_counter[j] = 0;
        // Start of 2nd iteration to finish the sorting
        for (int j = 0; j < N; ++j)
            ++base_digit_counter[(bucket[j] / 32768 % 32768)];
        for (int j = 1; j < 32768; ++j)
            base_digit_counter[j] += base_digit_counter[j-1];
        for (int j = N-1; j >= 0; --j){
            S[base_digit_counter[(bucket[j] / 32768 % 32768)] - 1] = bucket[j];
            --base_digit_counter[(bucket[j] / 32768 % 32768)];
        }
        // end of radix sort code
        long long R = 0;
        for (int j = 0; j < N; ++j)
            R = (R * X + S[j]) % Y;
        cout << R << "\n";
    }
    return 0;
}