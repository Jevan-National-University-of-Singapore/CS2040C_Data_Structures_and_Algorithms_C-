// matric number: A0199806L
// name: Goh Kheng Xi, Jevan
// lab group: B04
// lab group TA: Wu Biao
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include<unordered_set>
#include <list>
#include <set>

using namespace std;

// class Contact
// {
//     public:
//         long long s;
//         long long t;
//         long long i;
//         bool operator()(const long long &A, const long &B){
//                 return A < B;
//             }
// };

// struct Comparator{
//     public:
//         bool operator()(const long long &A, const long &B){
//             return A < B;
//         }
// };



int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    unordered_set<long long> initial;
    vector<long long> output;
    vector<pair<long long, long long>> infected;
    list<vector<long long>> contacts;
    long long N, D, C;
    cin >> N >> D;
    cin >> C;
    for (long long i = 0; i < C; ++i) {
        long long ini;
        cin >> ini;
        initial.insert(ini);
    }
    for (long long i = 0; i < N; ++i){
        long long s, t;
        vector<long long> handler;
        cin >> s >> t;
        handler.push_back(s);
        handler.push_back(t);
        handler.push_back(i+1);
        contacts.push_back(handler);
        if (initial.find(i + 1) != initial.end()){
            bool merge = false;
            for (auto &inf: infected){
                if (handler[0] <= inf.second && handler[1] >= inf.first){
                    if (handler[0] < inf.first){
                        inf.first = handler[0];
                    }
                    if (handler[0] > inf.second){
                        inf.second = handler[1];
                    }
                    merge = true;
                    break;
                }
            }
            if (!merge){
                pair<long long, long long> infect = {handler[0], handler[1]};
                infected.push_back(infect);
            }
            
            
        }
    }
    // cout << "===================\n";
    // for (auto i: infected){
    //     cout << i.first << " " << i.second << endl;
    // }
    // cout << "==================\n";

    for (long long d = 0; d < D; ++d){
        vector<pair<long long, long long>>inf_cur = infected;
        // cout << "============ Day " << d + 1 << " ===============\n";
        // cout << "test0\n";
        
        for (long long i = 0; i < infected.size(); ++i){
            list<vector<long long>>contacts_curr;
            // cout << "test1\n";
            while (!contacts.empty()){
                // cout << "test2\n";
                // cout << contacts.front().i << endl;
                // cout << "contact front s: " << contacts.front().s << "      contact front t: " << contacts.front().t << endl;
                // cout << "inf s: " << inf_cur[i].first << " inf t: " << inf_cur[i].second << endl;
                
                if (contacts.front()[0] <= inf_cur[i].second && contacts.front()[1] >= inf_cur[i].first){
                    // cout << "test3a\n";
                    if (contacts.front()[0] < infected[i].first){
                        // cout << "test4a\n";
                        infected[i].first = contacts.front()[0];
                    }
                    if (contacts.front()[1] > infected[i].second){
                        // cout << "test4b\n";
                        infected[i].second = contacts.front()[1];
                    }
                    output.push_back(contacts.front()[2]);
                    // cout << "test5a\n";
                } else {
                    // cout << "test3b\n";
                    contacts_curr.push_back(contacts.front());
                    // cout << "test5b\n";
                }
                contacts.pop_front();


            }
            // cout << "size" << contacts.size();
            // cout << "test7\n";
            for (auto con: contacts_curr){
                contacts.push_back(con);
            }
            // contacts = contacts_curr;
            // cout << "test8\n";
        }
        

    }
    

    
    sort (output.begin(), output.end());

    for (auto i : output){
        cout << i << " ";
    }


}