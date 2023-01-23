#include <bits/stdc++.h>
using namespace std;

const int MAX_BLOCK = 50;

int max_freq = -1;
int block_freq = -1;

string generate() {
    string res = "";
    for (int i = 0; i < 5; i++) {
        res.push_back('A' + rand() % 26);
    }
    return res;
}

// bad hash function
int get_hash(string &str) {
    int res = 0;
    for (auto &x: str) {
        res += (x - 'A');
    }
    return res;
}

int main(){
    srand(time(NULL));
    vector<string> v(10000);
    for (auto &x: v) {
        x = generate();
    }
    map<int, int> freq;
    for (auto &x: v) {
        freq[get_hash(x)]++;
    }
    for (auto &x: freq) {
        max_freq = max(max_freq, x.second);
    }
    block_freq = max(1, max_freq / MAX_BLOCK);
    for (auto &x: freq) {
        cout << x.first << " : ";
        for (int i = 0; i < x.second / block_freq; i++) {
            cout << "X";
        }
        cout << endl;
    }
    return 0;
}