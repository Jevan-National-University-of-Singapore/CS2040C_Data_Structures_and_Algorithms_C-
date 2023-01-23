// there is one character bug in this code, submitting it verbatim will give you Wrong Answer

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n = 4;
  int A[5];
  for (int i = 0; i < n; i++)
    scanf("%d", &A[i]);
  // simulate bubble sort
  // well, not really O(n^3) but we can say this is O(5^3 = 125) = O(1) actually, as n is a constant 5...
  // most harder problems won't have that kind of 'tiny' n...
  for (int i = 0; i < n; i++)
    for (int j = 1; j < n; j++)
      if (A[j-1] > A[j]) {
        swap(A[j], A[j-1]);
        for (int k = 0; k < n; k++)
          printf("%d ", A[k]); // notice that Kattis allows having extra ' ' (space) at the end of your lines... Mooshak will be strict and won't allow this
        printf("\n");
      }
  return 0;
}
