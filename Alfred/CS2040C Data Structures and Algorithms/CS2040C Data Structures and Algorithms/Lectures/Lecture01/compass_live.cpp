// there is one character bug in this code, submitting it verbatim will give you Wrong Answer
// and I (think) will know that you did that

// please use these sample AC code for your reference only and recode using your own coding style+understanding
// then you will get the knowledge

#include <bits/stdc++.h> // #include <iostream> is enough
using namespace std; // this is abusing namespace std;
int main() {
  int n1; cin >> n1; // in proper software engineering, it is not advisable to shorten the lines like this
  int n2; cin >> n2;
  int CW;
  for (CW = 0; CW < 360; ++CW) // you can convert this to a O(1) formula, how? that's the challenge, but technically O(360) = O(1) too
    if ((n1+CW)%360 == n2)
      break;
  int CCW;
  for (CCW = 0; CCW < 360; ++CCW) // you can convert this to a O(1) formula, how? that's the challenge, but technically O(360) = O(1) too
    if ((n1+360-CCW)%360 == n2)
      break;
  cout << (CW < CCW ? CW : -CCW) << "\n";
  return 0;
}
