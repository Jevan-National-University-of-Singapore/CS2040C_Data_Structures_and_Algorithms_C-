// matric number: A0199806L
// name: Goh Kheng Xi, Jevan
// lab group: B04
// lab group TA: Wu Biao
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <vector>
#include <unordered_map>

using namespace std;

struct Comparator{
    public:
        bool operator()(vector<long long> a, vector<long long> b){
            if (a[0] > b[0]){
                return true;
            }
            return false;
        }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    long long n, m;
    unordered_map<long long, vector<pair<long long, int>>> AM;
    unordered_set<long long> visited;
    cin >> n >> m;
    for (long long i = 0; i < m; ++i){
        long long a, b, c;
        cin >> a >> b >> c;
        pair<long long, int> bridge_type;
        bridge_type.first = b;
        bridge_type.second = c;
        if (AM.find(a) == AM.end()){
            vector<pair<long long, int>> neighbours;
            neighbours.push_back(bridge_type);
            AM.insert({a, neighbours});
        } else {
            AM[a].push_back(bridge_type);
        }
        pair<long long, int> reverse_bridge_type;
        reverse_bridge_type.first = a;
        reverse_bridge_type.second = c;
        if (AM.find(b) == AM.end()){
            vector<pair<long long, int>> neighbours;
            neighbours.push_back(reverse_bridge_type);
            AM.insert({b, neighbours});
        } else {
            AM[b].push_back(reverse_bridge_type);
        }
    }
    
    priority_queue<vector<long long>, vector<vector<long long>>, Comparator> all_paths;
    vector<long long>initial_path;
    initial_path.push_back(0);
    initial_path.push_back(1);
    visited.insert(1);
    all_paths.push(initial_path);
    while (!all_paths.empty()){
        vector<long long>currentPath = all_paths.top();
        long long cur_pos = all_paths.top()[all_paths.top().size()-1];
        if (cur_pos == n){
            cout << currentPath[0];
            break;
        }
        all_paths.pop();
        for (auto b: AM[cur_pos]){ 
            if (visited.find(b.first) == visited.end()){
                vector<long long>currentPath_copy = currentPath;
                currentPath_copy.push_back(b.first);
                if (b.second == 1){
                    currentPath_copy[0] += 1;
                }
                visited.insert(b.first);
                all_paths.push(currentPath_copy);
            }
            
        }
        

    }
    
    


}