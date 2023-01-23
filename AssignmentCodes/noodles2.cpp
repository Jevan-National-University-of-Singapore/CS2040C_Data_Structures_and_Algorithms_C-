//get_at_least_subtask1_and_2_for_both_tasks
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Edge{
    public:
        long long u;
        long long v;
        long long l;

};

struct Comparator
{
    bool operator()(const Edge &A, const Edge &B){
            if (A.l < B.l){
                return true;
            }
            return false;
        }
};




int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    unordered_map<long long, long long>distances;
    vector<Edge> edgeList;
    long long j, b;
    cin >> j >> b;
    for (long long i = 0; i < b ; ++i){
        Edge newEdge;
        cin >> newEdge.u >> newEdge.v >> newEdge.l;
        edgeList.push_back(newEdge);
        if (distances.find(newEdge.u) == distances.end()){
            if (newEdge.u == 0){
                distances.insert({newEdge.u, 0});
            } else {
                distances.insert({newEdge.u, (10*10*10*10*10*10)});
            }
        }
    }
    sort(edgeList.begin(), edgeList.end(), Comparator());


    long long min = distances.begin() -> second;
    long long min_node = distances.begin() ->first;

    for (auto &d: distances){
        if (d.second < min ){
            min = d.second;
            min_node = d.first;
        }
        if (d.second + edgeList[d.first])
    }
}
