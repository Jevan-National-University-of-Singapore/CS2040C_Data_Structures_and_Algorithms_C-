// there is one character bug in this code, submitting it verbatim will give you Wrong Answer

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  int P; cin >> P;
  while (P--) { // O(P*n^2), but n is exactly 20 here, so 20^2 = 400, so O(400*P)...
    int K; cin >> K; cout << K << " ";
    int ans = 0;
    int H[30]; // just my habit to declare array about 10 cells larger than necessary
    for (int i = 0; i < 20; ++i) { // insertion sort simulation
      cin >> H[i]; // read next number
      int j = i;
      while ((j > 0) && (H[j] < H[j-1])) { // do (j > 0) check first to prevent crash, then check if we need to swap
        swap(H[j], H[j+1]); // yes, we need to swap these two
        ++ans; // one more swap
        --j; // decrease j
      }
    }
    cout << ans << endl; // number of swaps (steps taken back) needed for this test case
  }
  return 0;
}
