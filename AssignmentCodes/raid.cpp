//matric number: A0199806L
//name: Goh Kheng Xi, Jevan
//lab group: B04
//lab group TA: Wu Biao

#include <iostream>
#include <stdio.h>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>

using namespace std;


bool Comparator(pair<long long, string> a, pair<long long, string> b){
            if (a.first > b.first){
                return true;
            } else if (a.first == b.first && string(a.second) < string(b.second)){
                return true;
            }
            return false;
        }

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long N, S1, S2, S3;
    string name;
    cin >> N;
    unordered_set<string> removed_names;
    list<pair<long long, string>> s1, s2, s3;

    for (long long i = 0 ; i < N; ++i){
        pair <long long, string> player_s1, player_s2, player_s3;
        cin >> name >> player_s1.first >> player_s2.first >> player_s3.first;
        player_s1.second = name;
        player_s2.second = name;
        player_s3.second = name;
        s1.push_back(player_s1);
        s2.push_back(player_s2);
        s3.push_back(player_s3);
    }

    s1.sort(Comparator);
    s2.sort(Comparator);
    s3.sort(Comparator);

    for (long long i = 0; i < N/3; ++i){
        vector<string> team;
        while (removed_names.find(s1.front().second) != removed_names.end()){
            s1.pop_front();
        }
        team.push_back(s1.front().second);
        removed_names.insert(s1.front().second);
        s1.pop_front();
        

        while (removed_names.find(s2.front().second) != removed_names.end()){
            s2.pop_front();
        }
        team.push_back(s2.front().second);
        removed_names.insert(s2.front().second);
        s2.pop_front();

        while (removed_names.find(s3.front().second) != removed_names.end()){
            s3.pop_front();
        }
        team.push_back(s3.front().second);
        removed_names.insert(s3.front().second);
        s3.pop_front();

        sort (team.begin(), team.end());

        cout << team[0] << " " << team[1] << " " << team[2] << "\n";
        
    }
}