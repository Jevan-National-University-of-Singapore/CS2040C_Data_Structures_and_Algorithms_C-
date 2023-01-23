// there is one character bug in this code, submitting it verbatim will give you Wrong Answer
// and I (think) will know that you did that

// please use these sample AC code for your reference only and recode using your own coding style+understanding
// then you will get the knowledge

#include <bits/stdc++.h>
using namespace std;

class year {
private:
  vector<bool> got_ff;
public:
  year() {
    got_ff.assign(365, false);
  }
  void confirm_got_food(int s, int t) { // 1 <= s, t <= 365
    for (int i = s; i <= t; ++i)
      got_ff[i] = true;
  }
  int count_days_with_food() {
    int ans = 0;
    for (int i = 1; i <= 365; ++i)
      if (got_ff[i])
        ++ans;
    return ans;
  }
};

int main() {
  int N; cin >> N;
  year y;
  while (N--) {
    int s, t; cin >> s >> t;
    y.confirm_got_food(s, t);
  }
  cout << y.count_days_with_food() << "\n";
  return 0;
}
