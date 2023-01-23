#include <iostream>
#include <stdio.h>

int main(){
    long L, H, count = 0;
    int d1, d2, d3, d4, d5, d6;
    std::cin >> L >> H;
    for (int i = L; i <= H; ++i){
        //std::cout << i << std::endl;
        d1 = i/100000;
        d2 = (i%100000)/10000;
        d3 = (i%10000)/1000;
        d4 = (i%1000)/100;
        d5 = (i%100)/10;
        d6 = i%10;

        if (d1 != d2 && d2 != d3 && d3 != d4 && d4 != d5 && d5 != d6){
            if ((i % d1 == 0) && (i % d2 == 0) && (i % d3 == 0) && (i % d4 == 0) && (i % d5 == 0) && (i % d6 == 0) ){
                ++count;
            }
        }
        //std::cout << "count: " << count << std::endl;

    }
    std::cout << count;


}