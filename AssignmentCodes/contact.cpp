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
    list<long long> initial;
    set<long long> output;
    long long N, D, C, s, t, init, curr=0;
    cin >> N >> D;
    cin >> C;
    for (long long i = 0; i < C; ++i){
        cin >> init;
        initial.push_back(init);
    }

    initial.sort();
    for (long long j = 0; j < N; ++j){
        Contact contact;
        cin >> contact.s >> contact.t;
        contact.i = j + 1;
        contacts.push_back(contact);
        if (!initial.empty()){
            if (contact.i == initial.front()){
                infected.push_back(contact);
                initial.pop_front();
            }
        }
    }

    sort(contacts.begin(), contacts.end(), Comparator());

    for (long long d = 0; d < D; ++d){
        vector<Contact>infectedCopy = infected;
        for (auto i: infected){
            for (auto p: contacts){
                if (output.find(p.i) == output.end()){
                    if (p.s <= i.t){
                        if (p.s >= i.t){
                            output.insert(p.i);
                            infectedCopy.push_back(p);
                        } else if (p.t >= i.s){
                            output.insert(p.i);
                            infectedCopy.push_back(p);
                        }
                    } else {
                        break;
                    }
                }
            }
        }
        infected = infectedCopy;
    }

    for (auto i : output){
        cout << i << " ";
    }


}