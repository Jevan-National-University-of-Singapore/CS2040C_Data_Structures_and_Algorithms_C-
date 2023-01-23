//matric number: A0199806L
//name: Goh Kheng Xi, Jevan
//lab group: B04
//lab group TA: Wu Biao
#include <iostream>
#include <stdio.h>
#include <queue>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

struct p{
    long long D, K, B, F;
    char S;
};

class Comparator {
    public:
        bool operator()(const p &a, const p &b){
            return a.F > b.F;            
        }
};


class ComparatorHold {
    public:
        bool operator()(const p &a, const p &b){
            if (a.S < b.S){
                return a.S < b.S;
            } else if (a.S == b.S){ 
                if (a.D < b.D){
                    return false;
                } else if (a.D == b.D && a.K < b.K){
                    return false;
                } else {
                    return true;
                }
            }
            return false;
        }
};

int main(){
    /*ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);*/



    long long n, t, d, k, d_check = 0, oCount = 0, rCount = 0;
    char s;
    double o=0, r=0;
    priority_queue<p, vector<p>, Comparator> tech;
    priority_queue<p, vector<p>, ComparatorHold> hold;

    cin >> n >> t;

    /*if (t>n){
        t = n;
    }

    n -= t;*/

    for (long long i = 0; i < t; ++i){
        p presc;
        presc.D = 0;
        presc.B = 0;
        presc.F = 0;
        presc.S = 'S';
        tech.push(presc);
    }

    while (cin >> d >> s >> k){
        p presc;
        presc.D = d; presc.S = s; presc.K = k;

        if (!hold.empty()){
            if (presc.D != d_check){
                while (!hold.empty() && presc.D > tech.top().F){
                    p handler = hold.top();
                    handler.B = handler.D > tech.top().F ? handler.D : tech.top().F;
                    handler.F = handler.B + handler.K;
                    if (tech.top().S == 'S'){
                        o += tech.top().F - tech.top().D;
                        ++oCount;
                    } else {
                        r += tech.top().F - tech.top().D;
                        ++rCount;
                    }
                    tech.pop();
                    tech.push(handler);
                    hold.pop();
                }
            }
        }   
        hold.push(presc);
        d_check = d;
        
    }

    
    

    while (!hold.empty()){
        p handler = hold.top();
        handler.B = handler.D > tech.top().F ? handler.D : tech.top().F;
        handler.F = handler.B + handler.K;
        if (tech.top().S == 'S'){
            o += tech.top().F - tech.top().D;
            ++oCount;
        } else {
            r += tech.top().F - tech.top().D;
            ++rCount;
        }
        tech.pop();
        tech.push(handler);
        hold.pop();
        
    }

    while(!tech.empty()){
        if (tech.top().S == 'S'){
            o += tech.top().F - tech.top().D;
            ++oCount;
        } else {
            r += tech.top().F - tech.top().D;
            ++rCount;
        }
        tech.pop();
    }

    oCount -= t;

    cout << fixed << setprecision(7);
    if (oCount == 0){
        cout << 0.0000000;
    } else {
        cout << o/oCount;
    }


    if (rCount == 0){
        cout << " " << 0.0000000;
    } else {
        cout << " " << r/rCount;
    }
    
}