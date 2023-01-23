// there is one character bug in this code, submitting it verbatim will give you Wrong Answer

#include <bits/stdc++.h>
using namespace std;

int main() {
  int P, D; cin >> P >> D;
  vector<int> vA(D+1, 0), vB(D+1, 0);
  int V = 0;
  while (P--) {
    int d, a, b; cin >> d >> a >> b;
    vA[d] += a;
    vB[d] += b;
    V += (a+b);
  }
  int total_wA = 0, total_wB = 0;
  for (int d = 1; d < D; ++d) {
    int win = (vA[d]+vB[d])/2 + 1;
    int wA, wB;
    if (vA[d] >= win) { // party A wins in district d
      wA = vA[d]-win;
      wB = vB[d];
      cout << "A " << wA << " " << wB << "\n";
    }
    else { // party B wins in district d
      wA = vA[d];
      wB = vB[d]-win;
      cout << "B " << wA << " " << wB << "\n";
    }
    total_wA += wA;
    total_wB += wB;
  }
  cout << fixed << setprecision(12) << (double)abs(total_wA-total_wB) / V << "\n";
  return 0;
}
