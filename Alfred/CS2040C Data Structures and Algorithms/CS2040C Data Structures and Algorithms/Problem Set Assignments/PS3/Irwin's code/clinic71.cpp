#include <iostream> 
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <iterator>
#include <queue>
#include <unordered_map>
using namespace std;
class Comparator{
public:
    bool operator()(const pair<long long int,string>& a, const pair<long long int,string>& b) { 
        return a.first < b.first;
    }
}; //give up on trying to use compare here or a.second < b.second or lexi compare gg

int main( ) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int N; long long int K; cin >> N >> K;  // N 1 to 200k , K 0 to 10mil
    unordered_map<string, vector<long long int>> mapper;
    
    for (long long int i = 0; i < N; ++i){
    long long int Q; cin >> Q;
    switch(Q){
        case 1:
        {
            long long int T; string name; long long int S;   cin >> T >> name >> S;
            vector<long long int> stats = {S,T};
            mapper[name] =stats;
            break; //if not will flow down to case 2
        }
        case 2:
        {
            long long int T2; cin >> T2; 
            if (mapper.empty()){
            cout << "doctor takes a break" << endl;
            break;
            }
            else{//calculate priority // construct priority queue
            long long int pval; pair<long long int, string> comp; priority_queue<pair<long long int, string>, vector<pair<long long int, string>>, Comparator> pq;
            for (auto const& p: mapper) 
                {
                pval = p.second[0] + K*(T2-p.second[1]);
                comp.first = pval; comp.second = p.first;
                pq.push(comp);
            }
            vector<string> topdog; long long int topval = pq.top().first;
            while(!pq.empty()){
                if (pq.top().first == topval){
                    topdog.push_back(pq.top().second);
                    pq.pop();
                }
                else{
                    break;
                }
            }
            sort(topdog.begin(),topdog.end());
            string kingdog = topdog[0];
            cout << kingdog << endl;
            if (not mapper.empty()){
            mapper.erase(kingdog);}      
            }
            break;
        }
    case 3:{
        long long int T3; string gone;   cin >> T3 >> gone;
        if (not mapper.empty()){
            mapper.erase(gone);}      
        }
    }
    }
    
    return 0;
} 
