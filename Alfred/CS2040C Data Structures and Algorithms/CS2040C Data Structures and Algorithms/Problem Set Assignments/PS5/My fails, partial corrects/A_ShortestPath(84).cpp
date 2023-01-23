#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// class compare{
// public:
//  bool operator() (vector<long long> a, vector<long long> b){ //a is child, b is parent
//      if (a[0] >= b[0]) //if true, dont need to swap
//          return true;
//      else
//          return false;
//  }
// };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long TC, V, X, vertex,weight, Q, s,t,k;
    vector<long long> temp (2);

    //initialise main pq
    queue <vector<long long>> pq;

    cin >> TC;
    while (TC--){
        cin >> V;
        //initialise adjacency list
        vector<vector<vector<long long>>> paths(V);
        for (long long i = 0; i < V; i++){
            cin >> X;
            vector<vector<long long>> links(X);
            for (long long j = 0; j < X; j++){
                cin >> vertex >> weight;
                temp = {vertex, weight};
                links[j] = temp;
            }
            paths[i] = links; //directed
        }

        cin >> Q;
        while (Q--){
            cin >> s >> t >> k; //start >> end >> max junctions(inclusive of s&t)
            
            if (s == t){
                cout << 0 << '\n'; continue;
            }

            unordered_map<long long, long long> time;
            unordered_map<long long, long long> step;

            temp = {s,0};
            time[s] = 0; step[s] = 1;
            pq.push(temp);

            long long visited_t = 0;
            while (!pq.empty()){
                long long u = pq.front()[0]; //long long d = pq.front()[1];
                pq.pop();
                // if (d > time[u])
            //      continue;

                if (step[u] >= k) // if steps reach k, dont proceed.
                    continue;

                if (time.find(t) != time.end()){ //when visited t is of shorter time
                    if (time[u] >= time[t])
                        continue;
                }
                for (long long i = 0; i < paths[u].size(); i++){
                    long long v = paths[u][i][0];
                    long long edge_dist = paths[u][i][1];
                    if (v == t)
                        visited_t++;

                    if (time.find(t) != time.end()){ //when visited t is of shorter time
                        if (time[u] + edge_dist > time[t])
                            continue;
                    }
                    if (time.find(v) == time.end()){ //update - when not present in time-map, ie hasnt been visited
                        time[v] = time[u] + edge_dist;
                        temp = {v,time[v]};
                        step[v] = 1 + step[u];
                        pq.push(temp);
                    }
                    else if (time[v] > time[u] + edge_dist){ //update - when time taken is shorter than when previously visited
                        time[v] = time[u] + edge_dist;
                        temp = {v,time[v]};
                        step[v] = 1 + step[u];
                        pq.push(temp);
                    }
                    else if (time[v] == time[u] + edge_dist){ //update - when same time taken, but now in shorter steps
                        if (step[v] > step[u] + 1){
                            step[v] = 1 + step[u];
                            temp = {v,time[v]};
                            pq.push(temp);
                        }
                    }
                }
            }

            if (visited_t == 0)
                cout << -1 << '\n';
            else
                cout << time[t] << '\n';

            // time.clear(); step.clear();
        }
        cout << '\n';
    }

    return 0;
}
