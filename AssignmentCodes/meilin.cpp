#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;
int main (){
    ios::sync_with_stdio(false); cin.tie(NULL);
    long long N;
    cin >> N;
    map <long long, set<string> > S1_map;
    map <long long, set<string> > S2_map;
    map <long long, set<string> > S3_map;
    map <string, vector<long long>> all_nammes_and_skills;
    //3 maps of key_S_value_set
    for (long long i = 0; i<N; i++){
        string name;
        cin >> name;
        long long s1,s2,s3;
        cin >> s1 >> s2 >> s3;

        if (S1_map.find(s1) == S1_map.end()){
            set<string> s1_set;
            s1_set.insert(name);
            S1_map.insert({s1, s1_set});
        } else {
            S1_map[s1].insert(name);
        }

        if (S2_map.find(s2) == S2_map.end()){
            set<string> s2_set;
            s2_set.insert(name);
            S2_map.insert({s2, s2_set});
        } else {
            S2_map[s2].insert(name);
        }

        if (S3_map.find(s3) == S3_map.end()){
            set<string> s3_set;
            s3_set.insert(name);
            S3_map.insert({s3, s3_set});
        } else {
            S3_map[s3].insert(name);
        }

        vector<long long>skills;
        skills.push_back(s1);
        skills.push_back(s2);
        skills.push_back(s3);
        all_nammes_and_skills.insert({name, skills});
    }
    //print out the teams
    for (long long i =0; i<N/3 ; i++){
        vector<string>raid_team;
        auto name_pointer = S1_map.rbegin() -> second.begin();
        string name_1 = *name_pointer;
        raid_team.push_back(name_1);

        auto s_2 = all_nammes_and_skills[name_1][1];
        auto s_3 = all_nammes_and_skills[name_1][2];
        S2_map[s_2].erase(name_1);
        if (S2_map[s_2].empty()){
            S2_map.erase(s_2);
        }
        S3_map[s_3].erase(name_1);
        if (S3_map[s_3].empty()){
            S3_map.erase(s_3);
        }
        
        S1_map.rbegin()-> second.erase(name_1);

        if (S1_map.rbegin()-> second.empty()){
            S1_map.erase(S1_map.rbegin()-> first);
        }


        
        auto name_pointer_2 = S2_map.rbegin()->second.begin();
        string name_2 = *name_pointer_2;
        raid_team.push_back(name_2);
        auto s_1 = all_nammes_and_skills[name_2][0];
        s_3 = all_nammes_and_skills[name_2][2];
        S1_map[s_1].erase(name_2);
        if (S1_map[s_1].empty()){
            S1_map.erase(s_1);
        }
        S3_map[s_3].erase(name_2);
        if (S3_map[s_3].empty()){
            S3_map.erase(s_3);
        }

        S2_map.rbegin()-> second.erase(name_2);
        if (S2_map.rbegin()-> second.empty()){
            S2_map.erase(S2_map.rbegin()-> first);
        }





        auto name_pointer_3 = S3_map.rbegin()->second.begin();
        string name_3 = *name_pointer_3;
        raid_team.push_back(name_3);
        
        s_1 = all_nammes_and_skills[name_3][0];
        s_2 = all_nammes_and_skills[name_3][1];
        S1_map[s_1].erase(name_3);
        if (S1_map[s_1].empty()){
            S1_map.erase(s_1);
        }   
        S2_map[s_2].erase(name_3);
        if (S2_map[s_2].empty()){
            S2_map.erase(s_2);
        }
        
        S3_map.rbegin()-> second.erase(name_3);
        
        if (S3_map.rbegin()-> second.empty()){
            S3_map.erase(S3_map.rbegin()-> first);
        }


        sort(raid_team.begin(), raid_team.end());

        for (int i = 0; i < 3; ++i){
            cout << raid_team[i] << " ";
        }
        cout << "\n";
        
    }
}