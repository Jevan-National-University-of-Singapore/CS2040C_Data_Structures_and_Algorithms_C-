#include <iostream>
#include <stdio.h>
#include <queue>
#include <unordered_set>

using namespace std;

int main(){
    long long N;
    cin >> N;
    pair<long long, long long> start;
    start.first = 0;
    start.second = 0;
    vector<string>map;
    for (long long i = 0; i < N; ++i){
        string row;
        cin >> row;
        map.push_back(row);
        for (long long j = 0; j < N; ++j){
            if (row[j] == 'K'){
                start.first = i;
                start.second = j;
            }
        }
    }
    
    queue<vector<pair<long long, long long>>> paths;
    unordered_set<char>visited;

    while (!paths.empty()){
        vector<pair<long long, long long>> currentPath;

    }


}