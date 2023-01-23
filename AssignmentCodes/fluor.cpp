#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    //ios::sync_with_stdio(false); cin.tie(NULL);
    long long n;
    vector<long long> queue;
    cin >> n;

    for (long long i = 0; i < n; ++i){
        long long a;
        cin >> a;
        if (a != 0){
            queue.push_back(a);
        }
    }

    
    long long currentSum = 0;//queue[n-2];
    long long maxSum = 0;//queue[n-2];
    long long maxIndex = n-1;
    for (long long i = n-2; i >= 0; --i){
        currentSum += queue[i];
        if (currentSum > maxSum){
            maxSum = currentSum;
            maxIndex = i;
        }
    }

    long long maxH = 0;
    
    for (long long i = 0; i < n-1; ++i){
        if (i >= maxIndex){
            maxH += queue[i] * (i+2);
        } else {
            maxH += queue[i] * (i+1);
        }
    }

    cout << maxH;

    

    

}