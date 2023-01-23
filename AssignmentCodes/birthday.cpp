//matric number: A0199806L
//name: Goh Kheng Xi, Jevan
//lab group: B04
//lab group TA: Wu Biao
#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Friend{
    string Name;
    long long C;
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    map<string, Friend>friends;
    long long N, C;
    cin >> N;
    string name, B;
    for(long long i = 0; i < N; ++i){
        Friend f;
        cin >> f.Name >> f.C >> B;
        if (friends.find(B)==friends.end()){
            friends.insert({B, f});
        } else if (friends[B].C < f.C){
            friends[B] = f;
        }
    }

    vector<string> names;
    for (auto i = friends.begin(); i != friends.end(); ++i){
        names.push_back(i->second.Name);
    }
    sort(names.begin(), names.end());

    cout << names.size() << "\n";

    for (auto i = names.begin(); i != names.end(); ++i){
        cout << *i << "\n";
    }


}
