// this code was whacked/edited from the baseline https://www.comp.nus.edu.sg/~stevenha/cs2040c/demos/SpeedTest.cpp
// and Steven goes off-the-script several times :O... play around with it yourself

#include <bits/stdc++.h>
using namespace std;

int main() {
  long long counter = 0;
  clock_t begin = clock();
  int N = 1024*1024*1024; // try adding a few more zero digitS at the back of this variable to make your computer hangs...
  for (int i = 0; i < N; ++i) { // O(c * N*N) = O(cN^2), c is 'small' if you leave line 14 commented, but c is BIG if you uncomment it
    // printf("i = %d\n", i);
    //for (int j = 1; j < N; j*=2) { // O(log N)
    //for (int j = 0; j < N; ++j) { // O(N) inner loop, that will be repeated N times in the outer loop
      ++counter; // this operation is O(1), and fast, let's say 0.0000000001 s
      ++counter; // this operation is O(1), and fast, let's say 0.0000000001 s
      // but if you uncomment the next line, the same algorithm will be noticeably much slower
      // printf(" counter = %d\n", counter); // this I/O operation is 'heavy', let's say 0.01s per statement...
    //}
  }

  for (int i = 0; i < N; ++i) { // O(c * N*N) = O(cN^2), c is 'small' if you leave line 14 commented, but c is BIG if you uncomment it
    ++counter; // this operation is O(1), and fast, let's say 0.0000000001 s
  }

  // O(2*N log N) in line 8-16 ,and then + another O(N) in line 18-20
  // O(2*N log N + N)
  // discard the lower term
  // O(N log N)
  // 20971520*2 + 1048576 = 22020096


  printf("counter = %lld, computed in = %.12fs\n", counter, (double)(clock()-begin)/CLOCKS_PER_SEC);
  return 0;
}

// the default setup of this starting SpeedTest.cpp should be around 2-3s
