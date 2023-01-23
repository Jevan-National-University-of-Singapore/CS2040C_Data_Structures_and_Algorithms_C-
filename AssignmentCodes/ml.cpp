#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class Player{
    public:
        string name;
        long long s1;
        long long s2;
        long long s3;

        /*bool operator()(Player a, Player b){
            return string(a.name) < string(b.name);
        }*/
};


class Comparator {
    public:
        bool operator()(const Player &a, const Player &b)const{
            return string(a.name) < string(b.name);
        }
};


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    long long N;
    cin >> N;
    map <long long, set<Player, Comparator> > S1_map;
    map <long long, set<Player, Comparator> > S2_map;
    map <long long, set<Player, Comparator> > S3_map;
    for (long long i = 0; i<N; i++){
        Player p;
        cin >> p.name >> p.s1 >> p.s2 >> p.s3;
        if(S1_map.find(p.s1) == S1_map.end()){
            set<Player, Comparator> s1_set, s2_set, s3_set;
            s1_set.insert(p);
            s2_set.insert(p);
            s3_set.insert(p);
            S1_map.insert({p.s1, s1_set});
            S2_map.insert({p.s2, s2_set});
            S3_map.insert({p.s3, s3_set});
        } else {
            S1_map[p.s1].insert(p);
            S2_map[p.s1].insert(p);
            S3_map[p.s1].insert(p);
        }
    }

    for (long long i = 0; i < N/3 ;i++){
        vector<string> raid_team;
        auto pointer = S1_map.rbegin() -> second.begin();
        auto player = *pointer;
        auto name_1 = player.name;
        auto s_1 = player.s1;
        auto s_2 = player.s2;
        auto s_3 = player.s3;

        raid_team.push_back(name_1);   

        S2_map[s_2].erase(player);
        if (S2_map[s_2].empty()){
            S2_map.erase(s_2);
        }
        
        S3_map[s_3].erase(player);
        if (S3_map[s_3].empty()){
            S3_map.erase(s_3);
        }

        S1_map[s_1].erase(player);
        if (S1_map[s_1].empty()){
            S1_map.erase(s_1);
        }
        



        pointer = S2_map.rbegin() -> second.begin();
        player = *pointer;
        auto name_2 = player.name;
        s_1 = player.s1;
        s_2 = player.s2;
        s_3 = player.s3;

        raid_team.push_back(name_2);   

        S3_map[s_3].erase(player);
        if (S3_map[s_3].empty()){
            S3_map.erase(s_3);
        }

        S1_map[s_1].erase(player);
        if (S1_map[s_1].empty()){
            S1_map.erase(s_1);
        }

        S2_map[s_2].erase(player);
        if (S2_map[s_2].empty()){
            S2_map.erase(s_2);
        }

        pointer = S3_map.rbegin() -> second.begin();
        player = *pointer;
        auto name_3 = player.name;
        s_1 = player.s1;
        s_2 = player.s2;
        s_3 = player.s3;

        raid_team.push_back(name_3);   

        S1_map[s_1].erase(player);
        if (S1_map[s_1].empty()){
            S1_map.erase(s_1);
        }

        S2_map[s_2].erase(player);
        if (S2_map[s_2].empty()){
            S2_map.erase(s_2);
        }

        S3_map[s_3].erase(player);
        if (S3_map[s_3].empty()){
            S3_map.erase(s_3);
        }

        sort(raid_team.begin(), raid_team.end());

        for (int i = 0; i < 3; ++i){
            cout << raid_team[i] << " ";
        }
        cout << "\n";

    

    }



}