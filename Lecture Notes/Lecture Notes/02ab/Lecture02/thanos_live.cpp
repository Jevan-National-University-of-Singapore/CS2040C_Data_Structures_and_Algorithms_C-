// thanos_live.cpp, I change trivial thing below so that submitting this code verbatim is WA
#include <bits/stdc++.h> // a bad line
using namespace std; // also a bad line
typedef long long ll; // also a bad line as the two above
int main() {
  int T; cin >> T; // T is up to 2000, 'a big constant', so we leave variable 'T' (see, not always 'n') as it is
  while (T--) { // O(T * log F) overall
    ll P, R, F; cin >> P >> R >> F;
    int year = 0;
    while (P < F) { // still sustainable, O(log (F)), originally O(log_R (F-P)), but we drop R and P, understand?
      ++year; // one more year of surviving
      P *= R; // population size grows by this ratio, 1 < R, R is an integer, so the lowest possible R is ___?
    }
    cout << year << "\n"; // do you agree with Thanos's philosophy?, i.e., is the Earth already overpopulated?
  }
  return 0;
}
