// matric number: A0199806L
// name: Goh Kheng Xi, Jevan
// lab group: B04
// lab group TA: Wu Biao
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include<unordered_set>
#include <list>
#include <set>

using namespace std;

class Contact
{
    public:
        long long s;
        long long t;
        long long i;
};

struct Comparator{
    public:
        bool operator()(const Contact &A, const Contact &B){
            if (A.s < B.s){
                return true;
            } else {
                return false;
            }
        }
};


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    list<Contact>contacts;
    vector<Contact> infected;
    unordered_set<long long> initial;
    vector<long long> output;
    long long N, D, C, s, t, init, curr=0;
    cin >> N >> D;
    cin >> C;
    for (long long i = 0; i < C; ++i){
        cin >> init;
        initial.insert(init);
    }

    // initial.sort();
    for (long long j = 0; j < N; ++j){
        Contact contact;
        cin >> contact.s >> contact.t;
        contact.i = j + 1;
        contacts.push_back(contact);
        if (initial.find(j+1) != initial.end()){
            infected.push_back(contact);
        }
    }
    contacts.sort(Comparator());

    for (long long d = 0; d < D; ++d){

        vector<Contact>infectedCopy = infected;
        for (auto &i: infected){
            long long handler = i.s;
            i.s = i.t;
            auto upperB = upper_bound(contacts.begin(), contacts.end(), i, Comparator());
            i.s = handler;
            list<Contact>::iterator it = contacts.begin();
            while (it != upperB){
                if (it -> t >= i.s){
                    output.push_back(it -> i);
                    infectedCopy.push_back(*it);
                    auto it_copy = it;
                    ++it_copy;
                    contacts.erase(it);
                    it = it_copy;
                } else {
                    ++it;
                }
            }
        }
        infected = infectedCopy;
    }

    sort(output.begin(), output.end());
    for (auto i : output){
        cout << i << " ";
    }



}