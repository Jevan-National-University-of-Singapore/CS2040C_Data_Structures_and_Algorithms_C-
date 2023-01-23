#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    string input;
    cin >> input;
    for (long long i = 0; i < input.size(); ++i){
        if (input[i] == ':' || input [i] == ';'){
            if (i + 1 < input.size()){
                if (input[i+1] == ')'){
                    cout << i << "\n";
                } else if (input[i+1] == '-' && i + 2 < input.size()){
                    if (input[i+2] == ')'){
                        cout << i << "\n";
                    }
                }
            }
        }
    }
}