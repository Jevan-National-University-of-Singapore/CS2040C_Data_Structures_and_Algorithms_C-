// two lines from the live AC version was 'edited' so this will WA/RTE if submitted verbatim (which you shouldn't do)
// try to understand what is happening and recode yourself

// Kindergaten Excursion

#include <iostream>
#include <string>
// at least I avoid bits/stdc++.h and using namespace std;

long long num_swaps = 0; // bad
std::string a, b; // also bad, but it works

// https://visualgo.net/en/sorting?slide=10-2
void merge(int low, int mid, int high) {
  // subarray1 = a[low..mid], subarray2 = a[mid+1..high], both sorted
  int N = high-low+1;
  int left = low, right = mid+1, bIdx = 0;
  while (left <= mid && right <= high) { // the merging
    if (a[left] <= a[right])
      b[bIdx++] = a[left++];
    else { // this is when inversion happens
      b[bIdx++] = a[right++];
      num_swaps += (mid-left+1);
    } 
  }
  while (left <= mid) b[bIdx++] = a[left++]; // leftover, if any
  while (right <= high) b[bIdx++] = a[right++]; // leftover, if any
  for (int k = 0; k < N; k++) a[low+k] = b[k]; // copy back
}

// https://visualgo.net/en/sorting?slide=10-5
void mergeSort(int low, int high) {
  // the array to be sorted is a[low..high]
  if (low < high) { // base case: low >= high (0 or 1 item)
    int mid = (low+high) / 2; 
    mergeSort(low  , mid ); // divide into two halves
    mergeSort(mid+1, high); // then recursively sort them
    merge(low, mid, high); // conquer: the merge routine
  }
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(NULL);
  // freopen("in.txt", "r", stdin);

  std::cin >> a;
  // b = a; // to create at least the same buffer
  // std::cout << a << "\n";
  mergeSort(0, (int)a.length());
  // std::cout << a << "\n";
  std::cout << num_swaps << "\n";

  return 0;
}

// Mjehuric??
// 10210 (input) +1 each -> 21321
// 01210 // swap first two
// 01120 // swap 3rd and 4th
// 01102
// 01012
// 00112 (output)
