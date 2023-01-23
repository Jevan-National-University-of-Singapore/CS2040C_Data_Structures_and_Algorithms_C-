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

// struct Comparator{
//     public:
//         bool operator()(const Contact &A, const Contact &B){
//             if (A.s < B.s){
//                 return true;
//             } else if (A.t < B.t){
//                 return true;
//             }
//             return false;
//         }
// };

struct ComparatorArrival{
    public:
        bool operator()(const Contact &A, const Contact &B){
            if (A.s < B.s){
                return true;
            } else {
                return false;
            }
        }
};

struct ComparatorDepart{
    public:
        bool operator()(const Contact &A, const Contact &B){
            if (A.t < B.t){
                return true;
            } else {
                return false;
            }
        }
};


int main(){
    list<Contact> infected;
    vector<Contact> contactsArrivals;
    vector<Contact> contactsDepart;
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
        contactsArrivals.push_back(contact);
        contactsDepart.push_back(contact);
        if (!initial.empty()){
            if (contact.i == initial.front()){
                infected.push_back(contact);
                initial.pop_front();
            }
        }
    }
    // infected.sort(Comparator());
    sort(contactsArrivals.begin(), contactsArrivals.end(), ComparatorArrival());
    sort(contactsDepart.begin(), contactsDepart.end(), ComparatorDepart());

    for (auto i: infected){
        cout << "test 0" << endl;
        auto lowerArrival = lower_bound(contactsArrivals.begin(), contactsArrivals.end(), i, ComparatorArrival());
        long long holder = i.s;
        i.s = i.t;
        cout << "test 1" << endl;
        auto upperArrival = upper_bound(contactsArrivals.begin(), contactsArrivals.end(), i, ComparatorArrival());
        cout << "test 2" << endl;
        while (lowerArrival != upperArrival){
            if (output.find(lowerArrival->i) == output.end()){
                output.insert(lowerArrival->i);
            }
            lowerArrival++;
        }
        i.s = holder;
        cout << "test 3" << endl;
        auto upperDepart = lower_bound(contactsDepart.begin(), contactsDepart.end(), i, ComparatorDepart());
        upperDepart++;
        i.t = i.s;
        cout << "test 4" << endl;
        auto lowerDepart = upper_bound(contactsDepart.begin(), contactsDepart.end(), i, ComparatorDepart());
        lowerDepart--;
        cout << "test 5" << endl;
        while (lowerDepart != upperDepart){
            if (output.find(lowerDepart->i) == output.end()){
                output.insert(upperDepart->i);
            }
            lowerDepart++;
        }
        cout << "test 6" << endl;
    }

    for (auto i : output){
        cout << i << " ";
    }


}