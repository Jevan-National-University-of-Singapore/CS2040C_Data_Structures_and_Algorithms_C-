#include <bits/stdc++.h>
using namespace std;

// https://visualgo.net/en/sorting?slide=10-2
void merge(int a[], int low, int mid, int high) {
  // subarray1 = a[low..mid], subarray2 = a[mid+1..high], both sorted
  int N = high-low+1;
  int b[N]; // discuss: why do we need a temporary array b?
  int left = low, right = mid+1, bIdx = 0;
  while (left <= mid && right <= high) // the merging
    b[bIdx++] = (a[left] <= a[right]) ? a[left++] : a[right++];
  while (left <= mid) b[bIdx++] = a[left++]; // leftover, if any
  while (right <= high) b[bIdx++] = a[right++]; // leftover, if any
  for (int k = 0; k < N; ++k) a[low+k] = b[k]; // copy back
}

// https://visualgo.net/en/sorting?slide=10-5
void mergeSort(int a[], int low, int high) {
  // the array to be sorted is a[low..high]
  if (low < high) { // base case: low >= high (0 or 1 item)
    int mid = (low+high) / 2; 
    mergeSort(a, low  , mid ); // divide into two halves
    mergeSort(a, mid+1, high); // then recursively sort them
    merge(a, low, mid, high); // conquer: the merge routine
  }
}

// https://visualgo.net/en/sorting?slide=11-7, with two lines addition for https://visualgo.net/en/sorting?slide=12
int partition(int a[], int i, int j) {
  // ================== the only addition for Randomized Quick Sort
  int r = i + rand()%(j-i+1);
  swap(a[i], a[r]); // tada
  // ==================
  int p = a[i]; // p is the pivot
  int m = i; // S1 and S2 are initially empty
  for (int k = i+1; k <= j; ++k) { // explore the unknown region
    if ((a[k] < p) || ((a[k] == p) && (rand()%2 == 0))) { // case 2 (PATCHED solution to avoid TLE O(N^2) on input array with identical values)
      ++m;
      swap(a[k], a[m]); // C++ STL algorithm std::swap
    } // notice that we do nothing in case 1: a[k] >= p
  }
  swap(a[i], a[m]); // final step, swap pivot with a[m]
  return m; // return the index of pivot, to be used by Quick Sort
}

// https://visualgo.net/en/sorting?slide=11-8
void quickSort(int a[], int low, int high) {
  if (low < high) {
    int pivotIdx = partition(a, low, high); // O(N)
    // a[low..high] ~> a[low..pivotIdx–1], pivot, a[pivotIdx+1..high]
    quickSort(a, low, pivotIdx-1); // recursively sort left subarray
    // a[pivotIdx] = pivot is already sorted after partition
    quickSort(a, pivotIdx+1, high); // then sort right subarray
  }
}

// to be used by various sorting algorithms
void printArray(int a[], int n) {
  for (int i = 0; i < n; ++i) {
    if (i > 0) cout << " ";
    cout << a[i];
  }
  cout << endl;
}

const int MAX_N = 100000; // big enough for our demo to notice the difference
// if you encounter runtime error/stack overflow, you need to adjust this compilation setting: g++ -std=gnu++17 -Wl,--stack,16777216
// PS: Mac or UNIX/Linux user probably don't encounter this problem

int main() {
  int n = MAX_N; // n = 10; // use smaller number if you intend to print the actual array before/after sorting
  int a[MAX_N];
  for (int i = 0; i < n; ++i)
    a[i] = 1+rand()%1000000; // [1..1000000]

  clock_t begin = clock();
  // printArray(a, n);
  mergeSort(a, 0, n-1);
  // printArray(a, n);
  cout << "Elapsed time for Merge Sort: " << double(clock() - begin) / CLOCKS_PER_SEC << endl;

  n = MAX_N;
  for (int i = 0; i < n; ++i)
    // a[i] = i; // increasing input, one of the hardest test case for (non Randomized) Quick Sort
    a[i] = 7; // constant input, also one of the hardest test case for wrongly implemented (non Randomized) Quick Sort
    // a[i] = 1+rand()%1000000; // [1..1000000]

  begin = clock();
  // printArray(a, n);
  quickSort(a, 0, n-1); // experiment with line 31-32 above
  // sort(a, a+n); // there is a (quicker) Quick Sort inside (called 'introsort' if I am not mistaken)
  // printArray(a, n);
  cout << "Elapsed time for Quick Sort: " << double(clock() - begin) / CLOCKS_PER_SEC << endl;

  return 0;
}
