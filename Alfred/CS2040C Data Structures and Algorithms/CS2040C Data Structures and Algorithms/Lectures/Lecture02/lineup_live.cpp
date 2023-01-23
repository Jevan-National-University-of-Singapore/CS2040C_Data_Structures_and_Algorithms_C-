// there is one character bug in this code, submitting it verbatim will give you Wrong Answer

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<string> names;
  while (N--) {
    string name; cin >> name;
    names.push_back(name);
  }
  vector<string> clone = names;
  sort(clone.begin(), clone.end()); // in the library
  if (clone == names)
    cout << "INCREASING\n";
  else {
    reverse(clone.begin(), clone.end());
    if (clone != names)
      cout << "DECREASING\n";
    else
      cout << "NEITHER\n";
  }
  return 0;
}
