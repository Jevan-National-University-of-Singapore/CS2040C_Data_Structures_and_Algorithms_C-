// Magical Cows
// unordered_map of farm size to frequency; small simulation; the answer won't be larger than long long with the given constraints
// read and then code after a while 1:10pm, submit 1:33m (23m, WA on tc4/9, argh long long issue), submit 1:37pm (27m, AC)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_d = 50; // this will prevent overflow in 64 bit integers

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  int C, N, M; cin >> C >> N >> M;
  unordered_map<int, ll> f; // how many farms have this size on any given day?
  for (int i = 0; i < N; ++i) { // number of cows on the ith of the N farms on Day 0
    int c; cin >> c;
    ++f[c];
  }
  vector<ll> ans(MAX_d+1);
  for (int d = 0; d <= MAX_d; ++d) { // simulate Baxter Scott's process for MAX_d (up to 50) days
    ll num_different_farms = 0;
    for (auto &D_freq : f)
      num_different_farms += D_freq.second;
    ans[d] = num_different_farms; // number of different farms that the Regulator needs to inspect on day d
    // cout << "day " << d << ", number of different farms = " << ans[d] << "\n";
    unordered_map<int, ll> midnight_f;
    for (auto &[D, freq] : f) // the clock strikes midnight, each farm doubles their sizes
      midnight_f[2*D] = freq;
    f.clear(); // reset f
    for (auto &[D, freq] : midnight_f) { // early every morning, Baxter Scott does his adjustment process
      if (D <= C)
        f[D] += freq; // if there are D≤C cows on a farm, he leaves all D cows on the farm
      else {
        f[(D+1)/2] += freq; // he leaves ceil(D/2) cows on the farm 
        f[D/2] += freq; // and takes floor(D/2) cows to a new, empty farm
      }
    }
  }
  while (M--) {
    int d; cin >> d;
    cout << ans[d] << "\n";
  }
  return 0;
}

// PS: upon re-reading the problem constraints, I realize that I overkilled the problem
// please enlarge the constraints so that only Hash Table works, but vector doesn't, e.g., make 1 <= C <= 10^9 (instead of <= 1000)
