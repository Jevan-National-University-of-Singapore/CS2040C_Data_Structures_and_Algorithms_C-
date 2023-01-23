#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
    // freopen("joinstrings_1.in", "r", stdin);

    int n; cin >> n;
    vector<list<string>> words;
    for (int i = 0; i < n; i++) {
        string line; cin >> line; // Read strings
        list<string> word = { line };
        words.push_back(word);
    }

    int a, b;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        words[a-1].splice(words[a-1].end(), words[b-1]); // O(1) appending
    }

    for (string &s: words[a-1]) {
        cout << s; // Printing
    }
    cout << '\n';
    return 0;
}
