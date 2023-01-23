//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string line1; getline(cin, line1); //get 1st input line (str)
    string abc; getline(cin, abc); //get 2nd input line (str)
    stringstream stream(line1); // breaking input into words using stringstream by looking at the spacing as dividers
    vector<int> number; //create vector to store integers
    while (true) {
        int n;
        stream >> n; //convert words into integers
        if (!stream) //if no more words
            break;
        number.push_back(n); //append n into the vector(number)
    }
    int y = number.size() - 1;
    for (int x = 0; x < y; y--) { //repeat sorting cycle how many times
        for (int i = x; i < number.size() - 1; i++) { //one sorting cycle
            int small = number[i + 1]; int big = number[i];
            if (number[i] > number[i + 1]) {
                number[i] = small; number[i + 1] = big; //sorting process
            }
        }
    }
    vector<int> sorted = number; // number is now sorted
    vector<int> final; // for my output
    for (int i = 0; i < abc.length(); i++) {
        if (abc[i] == 'A') {            //hardcoding here..
            final.push_back(sorted[0]);
        }
        else if (abc[i] == 'B') {
            final.push_back(sorted[1]);
        }
        else {
            final.push_back(sorted[2]);
        }
    }
    cout << final[0] << ' ' << final[1] << ' ' << final[2];
    return 0;
}