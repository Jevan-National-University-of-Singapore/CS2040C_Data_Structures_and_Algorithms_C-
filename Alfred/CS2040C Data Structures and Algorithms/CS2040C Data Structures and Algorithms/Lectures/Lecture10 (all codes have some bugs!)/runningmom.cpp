// there are A FEW 1 character bugs in this code, submitting it verbatim will be WA

#include <bits/stdc++.h>
using namespace std;

// need these to be global for simpler code... use with caution
// passing these heavy objects as function parameters are not advisable
unordered_map<string, vector<string>> AL; // to make the explanation simple, imagine this AL as Hash Table with Separate Chaining technique
unordered_map<string, int> status; // as now we need to differentiate not just UNVISITED/VISITED, but UNVISITED/EXPLORED/FULLY-VISITED, we need to map the vertex name (string) into an integer status 0/1/2
bool back_edge_found;

// PS: note that there are other (faster) solution... map city names to integer indices [0..V-1], then work with the faster integer indices again

void dfs(string city) {
  if (back_edge_found) return; // good optimization, we stop upon finding the first cycle (no need to explore the entire graph)
  // cout << "MoM at newly EXPLORED city " << city << endl;
  status[city] = 1; // EXPLORED
  for (auto &neighbor : AL[city]) {
    // cout << "MoM trying to go to city " << neighbor << endl;
    if (status[neighbor] == 0) // going to an unvisited neighbor
      dfs(neighbor);
    else if (status[neighbor] == 1) { // going to an EXPLORED neighbor!!!
      // cout << city << " -> " << neighbor << " is part of a cycle, MoM is safe as he/she can cycle forever" << endl;
      back_edge_found = true;
      break;
    }
  }
  // cout << "MoM finished VISITING city " << city << " fully" << endl;
  status[city] = 1; // DONE/fully visited
}

int main() {
  // freopen("in_runningmom.txt", "r", stdin);
  int n;
  string origin, destination;
  cin >> n; cin.get(); // read n then ignore the newline
  while (n--) {
    cin >> origin >> destination;
    AL[origin].push_back(destination); // directed edge this time
  }
  while (cin >> origin, !cin.eof()) {
    back_edge_found = false;
    status.clear(); // clear visited flag for every test case
    dfs(origin);
    cout << origin;
    cout << (!back_edge_found ? " safe\n" : " trapped\n"); // if can reach a cycle (back_edge_found) starting from origin, MoM is safe
  }
  return 0;
}
