// Gear Changing
// insert all N*M gear ratios into a vector, sort in ascending order, safer using fraction (remove duplicates or not should be no difference)

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii; // we can represent a fraction as a pair of integer (numerator, denominator)

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  int N, M; double P; cin >> N >> M >> P; P /= 100.0; // convert P from percentage to double
  vector<int> v1(N);
  for (int i = 0; i < N; ++i)
    cin >> v1[i];
  vector<int> v2(M);
  for (int i = 0; i < M; ++i)
    cin >> v2[i];

  vector<ii> ratio;
  for (auto &t1 : v1) // for all teeth t1 on each of the gears on the crank
    for (auto &t2 : v2) // for all teeth t2 on each gears on the back wheel
      ratio.push_back({t1, t2}); // insert this ratio (as pair)

  sort(ratio.begin(), ratio.end(), [](ii a, ii b) {
    if (((long long)a.first*b.second) < ((long long)b.first*a.second))
      return true;
    return false;
  }); // sort the ratios from heaviest (hardest to pedal, slowest speed) to lightest (easiest to pedal, fastest speed)

  int i;
  for (i = 1; i < (int)ratio.size(); ++i) // check all pairs of consecutive ratios
    if (ratio[i].first*ratio[i-1].second > (1+P)*ratio[i].second*ratio[i-1].first) // Lucy does NOT want her cadence to be increased by more than P%
      break; // early termination, something is incorrect

  cout << (i == (int)ratio.size() ? "Ride on!" : "Time to change gears!") << endl;
  return 0;
}
