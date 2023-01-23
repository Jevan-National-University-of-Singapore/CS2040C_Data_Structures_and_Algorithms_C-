// submitting this code verbatim will give you WA

// Dyslectionary

#include <bits/stdc++.h>
using namespace std;

// typedef pair<string, string> ss;

int main() {
  // freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(NULL);
  bool FirstTC = true;
  while (!cin.eof()) { // for each test case
    vector<string> words;
    int max_word_length = 0;
    while (1) { // keep reading the word of each test case until you hit "" (blank line) or EOF (for last group)
      string line; getline(cin, line); // cannot use cin >> line; because it canNOT read blank line!!!
      if ((line == "") || cin.eof()) break;
      string rev_line = line;
      reverse(rev_line.begin(), rev_line.end());
      // words.emplace_back(rev_line, line);
      // words.push_back(make_pair(rev_line, line));
      // words.push_back(ss(rev_line, line));
      // words.push_back({rev_line, line});
      words.push_back(rev_line);
      max_word_length = max(max_word_length, (int)line.length());
    }
    sort(words.begin(), words.end());
    // sort(words.begin(), words.end(), [](string a, string b) {
    //   string ra = a; reverse(ra.begin(), ra.end());
    //   string rb = b; reverse(rb.begin(), rb.end());
    //   return ra < rb;
    // });
    if (!FirstTC) cout << "\n";
    FirstTC = false;
    // for (auto &[rev, org] : words) {
    for (auto &rev : words) {
      for (int i = 0; i < max_word_length-(int)rev.length(); ++i)
        cout << "x";
      for (int i = (int)rev.length()-1; i >= 0; --i)
        cout << rev[i];
      cout << "\n";
    }
  }
  return 0; 
}
