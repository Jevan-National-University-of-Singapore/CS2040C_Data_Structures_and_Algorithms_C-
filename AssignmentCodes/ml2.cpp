#include <iostream>
#include <stdio.h>
#include <queue>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

class Prescription{
    public:
        long long __d;
        long long __k;
        long long __s;
};


class Comparator {
    public:
        bool operator()(Prescription a, Prescription b){
            if (a.__s < b.__s){
                return true;
            } else if (a.__s == b.__s){ 
                if (a.__d < b.__d){
                    return false;
                } 
                if (a.__d == b.__d && a.__k < b.__k){
                    return false;
                } 
                
                return true;
                
            }
            return false;
        }
};

int main(){
    long long n;
    long long t;
    double d;
    double k;
    char s;
    priority_queue<Prescription, vector<Prescription>, Comparator> check;
    priority_queue<long long, vector<long long>, greater<long long>> technicians;

    cin >> n;
    cin >> t;
    queue<Prescription> all_prescriptions;

    for (long long i = 0; i < t; ++i){
        technicians.push(0);
    }

    for (long long i = 0; i < n; i++){
        cin >> d;
        cin >> s;
        cin >> k;
        Prescription new_prescription;
        new_prescription.__d = d;
        new_prescription.__k = k;
        if (s == 'S'){
            new_prescription.__s = 1;
        } else {
            new_prescription.__s = 0;
        }
        all_prescriptions.push(new_prescription);
    }

    double r = 0;
    double o = 0;
    long long countR = 0;
    long long countO = 0;
    
    double prev_d = -1;
    while (!all_prescriptions.empty()){
        Prescription earliest_prescription = all_prescriptions.front();
        if (!check.empty()){
            if (earliest_prescription.__d != prev_d){
                while (!check.empty() && earliest_prescription.__d > technicians.top()){
                    long long finish_time;
                    if (check.top().__d > technicians.top()){
                        finish_time = check.top().__d + check.top().__k;
                    } else {
                        finish_time = technicians.top() + check.top().__k;
                    }
                    if (check.top().__s == 1){
                        countO++;
                        o += finish_time - check.top().__d;
                    } else {
                        countR++;
                        r += finish_time - check.top().__d;
                    }
                    
                    technicians.pop();
                    technicians.push(finish_time);
                    check.pop();
                }
            }
        }   
        check.push(earliest_prescription);

        prev_d = earliest_prescription.__d;
        all_prescriptions.pop();
        
    }


    

    while (!check.empty()){
        long long finish_time;
        if (check.top().__d > technicians.top()){
            finish_time = check.top().__d + check.top().__k;
        } else {
            finish_time = technicians.top() + check.top().__k;
        }
        if (check.top().__s == 1){
            countO++;
            o += finish_time - check.top().__d;
        } else {
            countR++;
            r += finish_time - check.top().__d;
        }
        
        technicians.pop();
        technicians.push(finish_time);
        check.pop();
    }

    double oAverage;
    double rAverage;

    

    if (countO == 0){
        oAverage = 0;
    } else {
        oAverage = o/countO;
    }


    if (countR == 0){
        rAverage = 0;
    } else {
        rAverage = r/countR;
    }
    cout << fixed << setprecision(6) << oAverage << ' ' << rAverage;
}