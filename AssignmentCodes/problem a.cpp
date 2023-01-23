#include <iostream>
#include <vector>
#include <map>





using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    long long A;
    long long B;
    map<char, long long> n;
    vector<string> nn;

    cin >> A;

    while(A--){


        string name;
        cin >> name;
        if (n.find(name[0]) != n.end()){
            n[name[0]] += 1;

        } else {

            n.insert({n[0], 1});

        }
    }

    cin >> B;




    while (B--){


        char NickName;
        cin >> NickName;
        cout << n[NickName];
        cout << "\n";

    }


}