#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    map<vector<long long>, long long>frosh;
    long long n;
    cin >> n;

    for (long long i = 0; i < n; ++i){
        vector<long long>courses;
        for (long long c = 0; c < 5; ++c){
            long long course;
            cin >> course;
            courses.push_back(course);
        }
        sort(courses.begin(), courses.end());
        if (frosh.find(courses) == frosh.end()){
            frosh.insert({courses, 1});
        } else {
            frosh[courses]++;
        }       

    }

    long long max = 0;
    long long counter = 0;
    for (auto i: frosh){
        if (i.second > max){
            max = i.second;
            counter = 1;
        } else if (i.second == max){
            counter++;
        }
    }

    cout << max * counter;
    

}