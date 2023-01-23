// submitting this code verbatim will give you TLE

// Competitive Arcade Basketball
// Hash Table example
// code 15:17pm, submit 15:22pm (5m, AC)
// recode using HashTableDemo :)
// submit again 15:33pm (16m, RTE)
// fixed at 16:30pm :O (73m, AC :O) --- silly bug involving hash_function pre-condition

#include <bits/stdc++.h>
using namespace std;

// experiment with different value of M... too low -> then N (up to 200K)/M is too high -> TLE; too high -> then N (up to 200K)/M (large) is low, but if M exceeds the memory limit, you will get MLE instead...
const int M = 13; // M = table size is a prime number, rather small, for illustration purpose only, generally make load factor alpha = N/M < 7 (just a small number) where N is the maximum number of keys that you will likely need for your application

class hash_table { // this is an attempt to emulate unordered_map<string, int> mapper;
// the 'easiest' and most robust Hash Table is actually the one with Separate Chaining collision resolution technique
private:
  // interesting (new) technique, we can create an array (or vector) of another STLs, here we have an array of std::list (of pair of (string, int))
  list<pair<string, int>> underlying_table[M]; // you can change list to vector :O

  // MODIFICATIONS from https://visualgo.net/en/hashtable?slide=4-7
  int hash_function(string v) { // for Kattis - competitivearcadebasketball, there are alphaNUMERIC strings, so there can be ['0'..'9'] in the names
    int sum = 0;
    for (auto &c : v) // for each character c in v
      sum = ((sum*255)%M + c)%M; // M is table size, so I am using base 255 here :O, instead of base 26, otherwise you will get accidental negative hash value (other ways exist as long as you can handle alphanumeric)
    return sum;
  }

public:
  hash_table() {
    for (int i = 0; i < M; ++i)
      underlying_table[i].clear(); // clear the linked list
  }

  void insert(string key, int value) { // to emulate mapper[key] = value
    bool contains_key = false;
    // cout << key << " hashed to " << hash_function(key) << " -> " << value << "\n";
    for (auto &[k, v] : underlying_table[hash_function(key)])
      if (k == key) { // if there is an existing key
        contains_key = true;
        v = value; // update the satellite data, notice that we use pass by reference '&' above
      }
 
    if (!contains_key) // no previous key before
      underlying_table[hash_function(key)].emplace_back(key, value); // just append at the back
  }

  int search(string key) { // to emulate mapper[key]
    for (auto &[k, v] : underlying_table[hash_function(key)]) // O(k), k is the length of this list, but with careful setup, k can be O(1)
      if (k == key) // if there is an existing key
        return v; // return this satellite data
 
    // if there is no previous key before (return v above is never executed)
    return 0; // we return a special symbol to say such key does not exist
  }

  void remove(string key) { // to emulate mapper.erase(key)
    auto &row = underlying_table[hash_function(key)]; // get the reference of the row, notice that we use pass by reference '&' (VERY IMPORTANT)

    for (auto it = row.begin(); it != row.end(); ++it)
      if (it->first == key) { // if there is an existing key
        row.erase(it); // erase this (key, value) pair from this vector
        break; // do not do anything else
      }

    // we do nothing if key is not actually found
  }

  bool is_empty() {
    int total = 0;
    for (int i = 0; i < M; ++i)
      total += (int)underlying_table[i].size();
    return (total == 0);
  }
};

int main() {
  // freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(NULL);
  int n, p, m; cin >> n >> p >> m;
  for (int i = 0; i < n; ++i) { // actually extra data
    string name; cin >> name; // just read but don't store
  }
  // unordered_map<string, int> points; // C++ STL way
  hash_table points;
  bool no_winner = true;
  while (m--) {
    string name; int pt; cin >> name >> pt;
    // points[name] += pt; // C++ STL way
    points.insert(name, points.search(name) + pt);
    // if (points[name] >= p) { // C++ STL way
    if (points.search(name) >= p) {
      cout << name << " wins!\n";
      no_winner = false;
      // points[name] = -1e9; // C++ STL way
      points.insert(name, -1e9); // set a large negative so that he/she doesn't accidentally printed as winning again (if got more points later on)
    }
  }
  if (no_winner)
    cout << "No winner!\n";
  return 0;
}
