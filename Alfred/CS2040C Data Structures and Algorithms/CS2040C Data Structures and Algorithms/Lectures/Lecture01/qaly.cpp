// there is one character bug in this code, submitting it verbatim will give you Wrong Answer
// and I (think) will know that you did that

// please use these sample AC code for your reference only and recode using your own coding style+understanding
// then you will get the knowledge

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  double ans = 1.0;
  while (N--) {
    double q, y; cin >> q >> y;
    ans += q*y;
  }
  cout << setprecision(10) << ans << endl;
  return 0;
}
