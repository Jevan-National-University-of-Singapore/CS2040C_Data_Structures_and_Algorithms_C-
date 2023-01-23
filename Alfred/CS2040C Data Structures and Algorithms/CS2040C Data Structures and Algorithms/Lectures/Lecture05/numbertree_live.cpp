// submitting this code verbatim will give you WA

#include <bits/stdc++.h>
using namespace std;
int left(int i) { return i<<1; }
int right(int i) { return (i<<1)+1; }
int main() {
  int H; string path; cin >> H >> path;
  int i = 1;
  for (auto &c : path)
    i = (c == 'R') ? left(i) : right(i); // same as line 17-20
  cout << ((1<<(H+1)) - i) << "\n";
  //cout << ((int)pow(2.0, H+1) - i) << "\n"; // line 11 and 12 are the same
  return 0;
}
/*
    if (c == 'L')
      i = left(i);
    else
      i = right(i);
*/
