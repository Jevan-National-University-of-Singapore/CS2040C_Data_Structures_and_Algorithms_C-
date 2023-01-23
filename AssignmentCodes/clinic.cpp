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
#include <queue>
#include <set>

using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, K, Q, T, S;
    string name;
    map<long long, set<string>> q;
    unordered_map<string, long long> names;

    cin >> N >> K;
    for (long long i = 0; i < N; ++i){
        cin >> Q;
        switch (Q){
        case 1:
            {
                cin >> T >> name >> S;
                long long p = S - K * T;
                if (q.find(p) == q.end()){
                    set<string> handler;
                    handler.insert(name);
                    q.insert({p, handler});
                } else {
                    q[p].insert(name);
                }
                names.insert({name, p});
                break;
            }
        case 2:
            {
                cin >> T;
                if (q.empty()){
                    cout << "doctor takes a break\n";
                    break;
                }
                auto handler = q.rbegin()->second.begin();
                string max_name = *handler;
                cout << max_name <<"\n";
                names.erase(max_name);
                q.rbegin() -> second.erase(max_name);
                if (q.rbegin() -> second.empty()){
                    q.erase(q.rbegin()->first);
                }
                break;
           
            }

        case 3:
            {
                cin >> T >> name;
                if (names.find(name) != names.end()){
                    long long p = names[name];
                    q[p].erase(name);
                    if(q[p].empty()){
                        q.erase(p);
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