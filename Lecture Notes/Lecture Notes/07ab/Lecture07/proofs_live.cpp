// there are TWO subtle bugs from this AC code, study the recording and do *NOT* copy paste verbatim

#include <bits/stdc++.h>
using namespace std;

template <typename T1, typename T2>
class hash_table { // this is an attempt to emulate unordered_map<string, int> ht_stl;
// the 'easiest' and most robust Hash Table is actually the one with Separate Chaining collision resolution technique
private:
  // interesting (new) technique, we can create an array (or vector) of another STLs, here we have a vector of std::list (of pair of (string, int))
  vector<list<pair<T1, T2>>> underlying_table;
  int total;
  int M = 13; // M = table size is a prime number, generally make load factor alpha = N/M < 7 (just a small number) where N is the maximum number of keys that you will likely need for your application

  // from https://visualgo.net/en/hashtable?slide=4-7
  int hash_function(string v) { // assumption 1: v uses ['A'..'Z'] only (be careful if this assumption is not true); assumption 2: v is a short string
    int sum = 0;
    for (auto& c : v) { // for each character c in v
      sum = ((sum*26)%M + (c-'A'+1))%M; // M is table size
    }
    return sum;
  }

public:
  hash_table() { // O(M)
    underlying_table.assign(M, list<pair<T1, T2>>()); // create M empty std::lists
    total = 0;
  }

  hash_table(int _M) : M(_M) { // O(M), this time we can control the hash-table size
    underlying_table.assign(13, list<pair<T1, T2>>()); // create M empty std::lists
    total = 0;
  }

  ~hash_table() { // O(M)
    for (int i = 0; i < M; ++i)
      underlying_table[i].clear();
  }

  void insert(pair<T1, T2> key_value) { // O(1+alpha), to emulate ht_stl[key] = value or ht_stl.insert({key, value})
    auto& [key, value] = key_value; // decompose into key and value
    bool contains_key = false;
    for (auto& [k, v] : underlying_table[hash_function(key)])
      if (k == key) { // if there is an existing key
        contains_key = true;
        v = value; // update the satellite data, notice that we use pass by reference '&' above
      }
 
    if (!contains_key) { // no previous key before
      underlying_table[hash_function(key)].emplace_back(key, value); // just append at the back
      ++total;
    }
  }

  T2 find(T1 key) { // O(1+alpha), to emulate ht_stl[key] or ht_stl.find(key)
    for (auto& [k, v] : underlying_table[hash_function(key)]) // O(k), k is the length of this list, but with careful setup, k can be O(1)
      if (k == key) // if there is an existing key
        return v; // return this satellite data
 
    // if there is no previous key before (return v above is never executed)
    return -1; // we return a special symbol to say such key does not exist
  }

  void erase(T1 key) { // O(1+alpha), to emulate ht_stl.erase(key)
    auto& row = underlying_table[hash_function(key)]; // get the reference of the row, notice that we use pass by reference '&' (VERY IMPORTANT)

    for (auto it = row.begin(); it != row.end(); ++it)
      if (it->first == key) { // if there is an existing key
        row.erase(it); // erase this (key, value) pair from this vector
        --total;
        break; // do not do anything else
      }

    // we do nothing if key is not actually found
  }

  bool empty() {
    return total == 0;
  }
};

int main() {
  // freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(NULL); // n < 400K, big leh
  int n; cin >> n; cin.ignore(); // to skip newline
  // unordered_set<string> past_conclusions;
  hash_table<string, int> past_conclusions(9997); // n < 400k, 40, table of size ... ~10000
  // 9997 is unfortunately not a prime number (I just checked) - so not that 'optimal', maybe you can use 9973 (prime) or even ~10x larger = 99989 (use more memory but should be faster, experiment?)
  for (int lineNo = 1; lineNo <= n; ++lineNo) {
    string line; getline(cin, line);
    istringstream iss(line);
    string token;
    // cout << "this line is '" << line << "'\n";
    bool seen_the_arrow = false;
    while (iss >> token) {
      // cout << "  its tokens = '" << token << "'\n";
      if (token == "<-")
        seen_the_arrow = true;
      else {
        if (!seen_the_arrow) { // the a (0 <= a <= 5) assumptions (before "=>")
          // if (past_conclusions.find(token) == past_conclusions.end()) { // where got that conclusion before?
          if (past_conclusions.find(token) == -1) { // where got that conclusion before?
            cout << lineNo << '\n';
            return 0; // stop here
          }
        }
        else { // the single conclusion
          // cout << "inserting '" << token << "' into hash table of past conclusions\n";
          // past_conclusions.insert(token); // remember this as a "proven" conclusion
          past_conclusions.insert({token, 1}); // remember this as a "proven" conclusion
        }
      }
    }
  }
  cout << "correct\n"; // if can reach this line means the proofs are ok
  return 0;
}
