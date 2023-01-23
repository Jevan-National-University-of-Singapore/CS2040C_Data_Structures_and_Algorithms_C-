#include <iostream>
#include <stdio.h>
#include <set>
#include <map>

using namespace std;

int main(){
    map<long long, set<string>> testing;
    set<string> test;
    test.insert("c");
    test.insert("a");
    test.insert("b");

    testing.insert({1, test});

    auto i = testing.begin() -> second.begin();


    cout << *i;
}