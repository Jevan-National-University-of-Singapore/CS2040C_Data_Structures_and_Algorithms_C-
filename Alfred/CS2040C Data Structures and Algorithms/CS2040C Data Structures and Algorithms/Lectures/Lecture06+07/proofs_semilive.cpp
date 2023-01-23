// Proofs
// parsing...
// coded in about 11m
// with post processing

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); // without this line, reading up to 400K lines of input can be "slightly slower"
  int n; cin >> n; cin.get();
  unordered_set<string> conclusions(997); // we can influence the initial bucket size to be reasonably big but not too big so that alpha = N/M is reasonably small
  bool got_error = false;
  for (int lineID = 1; (lineID <= n) && !got_error; ++lineID) { // process line by line
    string proof; getline(cin, proof);
    istringstream iss(proof);
    string token;
    bool hit_arrow = false;
    while (iss >> token) {
      if (token == "->")
        hit_arrow = true;
      else {
        if (!hit_arrow) {
          // cout << " assumption " << token << "\n";
          if (conclusions.find(token) == conclusions.end()) { // not found previously
            cout << lineID << "\n";
            got_error = true;
            break;
          }
        }
        else {
          // cout << " conclusion is " << token << "\n";
          conclusions.insert(token);
        }
      }
    }
  }
  if (!got_error)
    cout << "correct\n";
  return 0;
}
