// there are A FEW 1 character bugs in this code, submitting it verbatim will be WA

// PE tips:
// 1. start with templates, like this, you are allowed to pre-code stuffs before PE
// 2. read and understand BOTH problems (only 2 tasks next week)
// 3. after you read both problems, decide a game plan, do A first, or B first
//    one of them may be "easier" for you (not necessarily for all)
// 4. strategy for top students (aiming for A+/A): you need to aim for 200/200,
//    i.e., solve all in 2h
//    strategy for B+/A-: use ~1-1.5h to solve 1 in full (100) + whack partial for 2nd task:
//    so around 130-150?
//    strategy for average in class: B, after reading 2 new tasks,
//    do 2 partials each, e.g., ~50+50 = ~100?
//    strategy for the rest... avoid 0+0 >.<
// 5. use freopen and copy sample input(s) into text file(s) for easier debugging later
// 6. use split screen (big/multiple monitors do help) so that you don't have to ALT+TAB
//    to switch between problem statement and your code

#include <bits/stdc++.h>
using namespace std;
int main() {
  // freopen("in_missinggnomes_1.txt", "r", stdin); // comment before submission
  // freopen("in_missinggnomes_2.txt", "r", stdin); // comment before submission
  // freopen("in_missinggnomes_3.txt", "r", stdin); // comment before submission
  ios::sync_with_stdio(false); cin.tie(NULL); // assume input going to be large

  // get ready to code
  int n, m; cin >> n >> m;
  set<int> missing; // this must be sorted, just abuse bbst :), (sorting also work)
  for (int i = 1; i < n; ++i)
    missing.insert(i); // insert [1,2,3...,n] first
  vector<int> remaining(m);
  for (auto &rem : remaining) {
    cin >> rem;
    missing.erase(rem);
  }

  // missing gnomes (if any), must be sorted ascending, for sample 1, the missing  {3, 5}
  // the remaining (at least 1), must be in INPUT order
  // merging the two lists, one is sorted ascending, the other must be kept as it is
  // 1,2,3,4,5
  // 1,2,3,5,4
  // 1,2,4,3,5
  // ...  total 5! = 120 permutations
  // 1,3....
  // [1],3,[4],[2],5 << among the first listed in sorted possible permutations
  // ...
  // 3,1...
  // ...
  // 5,4,3,2,1

  int j = 1;
  for (auto &g : missing) { // for each of the missing gnome, we slot it to the correct pos
    while (j < m && remaining[j] < g)
      cout << remaining[j++] << "\n";
    cout << g << "\n"; // echo this missing gnome
  }
  while (j < m) // the last part of "merge"
    cout << remaining[j++] << "\n";
  return 0;
}
