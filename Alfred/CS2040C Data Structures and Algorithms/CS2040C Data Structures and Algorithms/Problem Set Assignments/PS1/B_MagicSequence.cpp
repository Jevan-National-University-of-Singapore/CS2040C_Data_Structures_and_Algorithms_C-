#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int TC; long int N, A, B, C, X, Y; long long int V; vector<long long int> S;

    cin >> TC; cin.ignore();

    for (long int i = 0; i < TC; i++){
        cin >> N >> A >> B >> C >> X >> Y; cin.ignore();

        S.clear();
        S.push_back(A);
        for (long int i = 1; i < N; i++){
            S.push_back((S[i-1] * B + A) % C);
        }

        long long int base_log = 1024;
        vector<vector<long long int>> bucket(base_log);
        for (long int i = 0; i < N; i++){
            bucket[(S[i]) % base_log].push_back(S[i]);
        }
        S.clear();
        //put back sorted to S
        for (long long int b = 0; b < base_log; b++){
            for (int j = 0; j < bucket[b].size(); j++){
                S.push_back(bucket[b][j]);
            }
        }
        bucket.clear();

        vector<vector<long long int>> bucket_2(base_log);
        for (long int i = 0; i < N; i++){
            bucket_2[(S[i]/base_log) % base_log].push_back(S[i]);
        }
        S.clear();
        //put back sorted to S
        for (long long int b = 0; b < base_log; b++){
            for (int j = 0; j < bucket_2[b].size(); j++){
                S.push_back(bucket_2[b][j]);
            }
        }
        bucket_2.clear();

        vector<vector<long long int>> bucket_3(base_log);
        for (long int i = 0; i < N; i++){
            bucket_3[((S[i]/base_log)/base_log) % base_log].push_back(S[i]);
        }
        S.clear();
        //put back sorted to S
        for (long long int b = 0; b < base_log; b++){
            for (int j = 0; j < bucket_3[b].size(); j++){
                S.push_back(bucket_3[b][j]);
            }
        }
        bucket_3.clear();
        
        V = 0;
        for (long int i = 0; i < N; i++){
            V = (V * X + S[i]) % Y;
        }
        cout << V << endl;
    }
    return 0;
}