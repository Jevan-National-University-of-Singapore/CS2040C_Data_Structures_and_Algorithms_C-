// submitting this code verbatim will give you WA

// Delimiter Soup

#include <bits/stdc++.h>
using namespace std;

bool is_open_bracket(char ch) {
  return (ch == '(') || (ch == '[') || (ch == '{');
}

bool match(char ch, char top) {
  return ((ch == '(') && (top == ')')) ||
         ((ch == '[') && (top == ']')) ||
         ((ch == '{') && (top == '}'));
}

int main() {
  // freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(NULL);
  int n; cin >> n; cin.get();
  string L; getline(cin, L); // got spaces
  stack<char> s; // to help us do bracket matching, this is classic
  bool ok_so_far = true;
  // for (auto &ch : L) { // grr I need the index
  for (int i = 0; i < (int)L.length(); ++i) {
    // cout << "processing L[" << i << "] = " << L[i] << "\n";
    if (L[i] == ' ')
      continue; // a space, doesn't matter
    else if (is_open_bracket(L[i]))
      s.push(L[i]); // put into a stack
    else { // must be the close bracket
      // cout << L[i] << " vs " << s.top() << "\n";
      if (s.empty() && match(s.top(), L[i]))
        s.pop();
      else { // error
        cout << L[i] << " " << i << "\n";
        ok_so_far = false;
        break; // only need to output first closing delimiter that mismatch
      }
    }
  }
  if (ok_so_far)
    cout << "ok so far\n";
  return 0; 
}
