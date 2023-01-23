//matric number: A0199806L
//name: Goh Kheng Xi, Jevan
//lab group: B04
//lab group TA: Wu Biao

#include <iostream>
#include <stdio.h>
#include <vector>
#include <deque>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    long long N;
    cin >> N;
    string op;
    long long num;
    deque<long long> frontQ;
    deque<long long> backQ;
    for (long long i = 0; i < N; ++i){
        cin >> op >> num;
        if (op == "push_front"){
            frontQ.push_front(num);
            if (frontQ.size()-1 > backQ.size()){
                backQ.push_front(frontQ.back());
                frontQ.pop_back();
            }
        } else if (op == "push_back"){
            backQ.push_back(num);
            if (backQ.size() > frontQ.size()){
                frontQ.push_back(backQ.front());
                backQ.pop_front();
            }
        } else if (op == "push_middle"){
            if (backQ.size() == 0){
                frontQ.push_front(num);
            } else{
                frontQ.push_back(num);
            }
            if (frontQ.size()-1 > backQ.size()){
                backQ.push_front(frontQ.back());
                frontQ.pop_back();
            }
        } else {
            if (num >= frontQ.size()){
                num -= frontQ.size();
                cout << backQ[num] << endl;
            } else {
                cout << frontQ[num] << endl;
            }
        }
    }
}