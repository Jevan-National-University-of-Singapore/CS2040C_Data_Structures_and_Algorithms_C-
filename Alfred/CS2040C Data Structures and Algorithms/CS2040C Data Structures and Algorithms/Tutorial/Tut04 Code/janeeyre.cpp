// Jane Eyre
// looks like PQ simulation problem :O
// the input parsing is... grr...
// I think I need about 30+m to do this

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<string, ll> sll;
typedef tuple<ll, string, ll> llsll;

int main() {
//   freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(NULL);

  int n, m; ll k; cin >> n >> m >> k; cin.get();
  priority_queue<sll, vector<sll>, greater<sll>> unread; // min PQ of books (title s in ASCII-order---should be unique, number of pages k)
  while (n--) { // n unread books in Anna's pile
    string line; getline(cin, line);

    int j = line.find("\"", 1); // skip index 0, find j, the position of the second '"'
    string s = line.substr(1, j-1); // this is the book title

    ll k = 0;
    for (j += 2; j < (int)line.length(); ++j) // should be just one space separating s and k
      k = k*10 + (line[j]-'0');

    unread.emplace(s, k);
  }
  unread.emplace("Jane Eyre", k); // Anna also haven't read "Jane Eyre", it has k pages, and this is the target ending

  vector<llsll> toAdd; // vector of books to be added
  for (int i = 0; i < m; ++i) {
    string line; getline(cin, line);

    int j;
    ll t = 0;
    for (j = 0; line[j] != ' '; ++j)
      t = t*10 + (line[j]-'0');

    int e = line.find("\"", j+2); // skip first '"', find e, the position of the second '"'
    string s = line.substr(j+2, e-(j+2)); // this is the book title

    ll k = 0;
    for (j = e+2; j < (int)line.length(); ++j)
      k = k*10 + (line[j]-'0');

    toAdd.emplace_back(t, s, k);
  }
  sort(toAdd.begin(), toAdd.end()); // sort by (time received t from small to large, title s in ASCII order, num of pages k)

  // now the actual PQ simulation
  ll ans = 0; // the minute at which Anna FINISH reading "Jane Eyre"
  int i = 0; // for toAdd books
  while (true) {
    auto [s, k] = unread.top(); unread.pop(); // s = title of the book, k = number of pages it contains
    ans += k; // add this number of pages to total
    if (s == "Jane Eyre") { // ah this book
      cout << ans << endl;
      break;
    }

    // ok Anna finishes reading book s after k minutes, she checkes toAdd pile
    for (; i < m; ++i) { // got something in toAdd pile
      auto [t, s, k] = toAdd[i];
      if (t > ans) break; // stop, coz the problem says "If she receives one or more books at the EXACT same moment as she finishes another book, though, then she will pick her next book among both the books in her existing pile and the newly received books."
      unread.push({s, k}); // add this book to Anna's unread pile
    }
  }

  return 0;
}
