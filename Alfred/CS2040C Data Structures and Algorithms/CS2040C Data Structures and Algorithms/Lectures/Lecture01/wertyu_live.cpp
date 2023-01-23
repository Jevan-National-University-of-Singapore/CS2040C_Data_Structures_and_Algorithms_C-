// there is one character bug in this code, submitting it verbatim will give you Wrong Answer
// and I (think) will know that you did that

// please use these sample AC code for your reference only and recode using your own coding style+understanding
// then you will get the knowledge

#include <bits/stdc++.h> // #include <iostream> is enough
using namespace std; // this is abusing namespace std;
int main() {
  string MAPPER[4] = { // this simplifies our solution by a lot
    "1234567890-=",
    "QWERTYUIOP[]\\",
    "ASDFGHJKL:'",
    "ZXCVBNM,./"
  };
  while (1) {
    string line; getline(cin, line); // this is just one way to read in one line
    if (cin.eof()) break; // until End of File (EOF) is encountered
    for (auto &ch : line) { // range based for loop, using & (by reference) or not does not really matter here as character is just one byte (small)
      if (ch == ' ')
        cout << ' '; // just echo
      else {
        for (int i = 0; i < 4; ++i) // search the entire keyboard
          for (int j = 0; j < (int)MAPPER[i].length(); ++j) // continued
            if (MAPPER[i][j] == ch) // if found
              cout << MAPPER[i][j-1]; // print the one on its left
      }
    }
    cout << "\n";
  }
  return 0;
}
