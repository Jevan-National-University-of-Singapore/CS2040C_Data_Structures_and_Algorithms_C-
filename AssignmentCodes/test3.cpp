//matric number: A0199806L
//name: Goh Kheng Xi, Jevan
//lab group: B04
//lab group TA: Wu Biao

#include <iostream>
#include <stdio.h>
#include <vector>
#include <deque>

using namespace std;
class teque
{
private:
    deque<long long> frontQ;
    deque<long long> backQ;
    
public:
    void pb(long long element){
        backQ.push_back(element);
        if (backQ.size() > frontQ.size()){
            frontQ.push_back(backQ.front());
            backQ.pop_front();
        }
    }

    void pf(long long element){
        frontQ.push_front(element);
        if (frontQ.size()-1 > backQ.size()){
            backQ.push_front(frontQ.back());
            frontQ.pop_back();
        }
    }

    void pm(long long element){
        if (backQ.size() == 0){
            frontQ.push_front(element);
        } else{
            frontQ.push_back(element);
        }
        if (frontQ.size()-1 > backQ.size()){
            backQ.push_front(frontQ.back());
            frontQ.pop_back();
        }
    }
    long long get(long long index){
        if (index >= frontQ.size()){
            index -= frontQ.size();
            return backQ[index];
        } else {
            return frontQ[index];
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long N;
    cin >> N;
    string op;
    long long num;
    teque myTeque;
    for (long long i = 0; i < N; ++i){
        cin >> op >> num;
        if (op == "push_front"){
            myTeque.pf(num);
        } else if (op == "push_back"){
            myTeque.pb(num);
        } else if (op == "push_middle"){
            myTeque.pm(num);
        } else {
            cout << myTeque.get(num) << endl;
        }
    }
}