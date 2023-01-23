//get_at_least_subtask1_and_2_for_both_tasks
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;



int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    unordered_map<long long, long long>distances;
    unordered_map<long long, vector<long long>>MST; 
    unordered_map<long long, vector<pair<long long, long long>>> edgeList;
    long long j, b;
    cin >> j >> b;
    for (long long i = 0; i < b ; ++i){
        long long u, v, l;
        cin >> u >> v >> l;
        if (edgeList.find(u) == edgeList.end()){
            vector<pair<long long, long long>> handler;
            pair<long long, long long> handler_pair;
            handler_pair.first = v;
            handler_pair.second = l;
            handler.push_back(handler_pair);
            edgeList.insert({u, handler});
        } else {
            pair<long long, long long> handler_pair;
            handler_pair.first = v;
            handler_pair.second = l;
            edgeList[u].push_back(handler_pair);
        }
        if (distances.find(u) == distances.end()){
            if (u == 0){
                distances.insert({u, 0});
            } else {
                distances.insert({u, (10*10*10*10*10*10)});
            }
        }
    }
    // sort(edgeList.begin(), edgeList.end());


    long long min = distances.begin() -> second;
    long long min_node = distances.begin() ->first;

    for (auto &d: distances){
        if (d.second < min ){
            min = d.second;
            min_node = d.first;
        }
        // if (d.second + edgeList[d.first].l < )
    }
    if (MST.find(min_node) == MST.end()){
        vector<long long> handler;
        MST.insert({min_node, handler});
        for (long long &V: edgeList.find(min_node) -> second){
            distances[V] = edgeList
        }
    }
}
