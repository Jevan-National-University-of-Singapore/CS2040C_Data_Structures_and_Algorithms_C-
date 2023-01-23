//matric number: A0199806L
//name: Goh Kheng Xi, Jevan
//lab group: B04
//lab group TA: Wu Biao
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, K, Q, T, S;
    string name;
    map<long long, map<long long, string>> q;
    map<string, vector<long long>> names;

    cin >> N >> K;
    for (long long i = 0; i < N; ++i){
        cin >> Q;
        switch (Q) {
        case 1:
            {
                cin >> T >> name >> S;
                if (q.find(S) == q.end()){
                    map<long long, string> p_T;
                    p_T.insert({T, name});
                    q.insert({S, p_T});
                } else {
                    q[S].insert({T, name});
                }
                vector<long long> ST = {S, T};
                names.insert({name, ST});
                break;
            }
        case 2:
            {
                cin >> T;
                if (q.empty()){
                    cout << "doctor takes a break\n";
                    break;
                }
                string max_name = q.begin() -> second.begin() -> second;
                long long max_P = q.begin() -> first + K * (T - q.begin() -> second.begin() -> first);
                for (auto it = q.begin(); it != q.end(); ++it){
                    long long curr_s = it -> first + K * (T - it -> second.begin() -> first);
                    if (curr_s > max_P){
                        max_name = it -> second.begin() -> second;
                        max_P = curr_s;
                    } else if (curr_s == max_P && string(it -> second.begin() -> second) < string(max_name)){
                        max_name = it -> second.begin() -> second;
                        max_P = curr_s;
                    }
                }
                cout << max_name << "\n";
                long long max_S = names[max_name][0];
                long long max_T = names[max_name][1];
                q[max_S].erase(max_T);
                if(q[max_S].empty()){
                    q.erase(max_S);
                }
                names.erase(max_name);
                break;
           
            }

        case 3:
            {
                cin >> T >> name;
                if (names.find(name) != names.end()){
                    S = names[name][0];
                    T = names[name][1];
                    q[S].erase(T);
                    if(q[S].empty()){
                        q.erase(S);
                    }
                    names.erase(name);
                }
                break;                
            }
        
        default:
            break;
        }
    }
}