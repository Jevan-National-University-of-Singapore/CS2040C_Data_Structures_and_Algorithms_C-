// there are A FEW 1 character bugs in this code, submitting it verbatim will be WA

// PE tips, start with templates, like this

#include <bits/stdc++.h>
using namespace std;
int m, n;
string dish[110];
int dr[] = {-1,-2, 0, 1, 1, 1, 0,-1}; // N/NE/E/SE/S/SW/W/NW
int dc[] = { 0, 1, 0, 1, 0,-1,-1,-1};
void floodfill(int r, int c) {
  // cout << r << " " << c << "\n";
  dish[r][c] = '.'; // flag it as visited
  for (int d = 0; d < 8; ++d) {
    int nr=r+dr[d], nc=c+dc[d];
    if ((nr < 0) || (nr >= m) || (nc < 0) || (nc >= n)) continue; // outside the dish/grid, skip
    if (dish[nr][nc] == '#') // part of an Amoeba, go there
      floodfill(nr, nc);
  }
}
int main() {
  // freopen("in_amoebas_1.txt", "r", stdin); // comment before submission
   // freopen("in_amoebas_2.txt", "r", stdin); // comment before submission
  ios::sync_with_stdio(false); cin.tie(NULL); // assume input going to be large
  cin >> m >> n; cin.get();
  for (int i = 0; i < m; ++i)
    cin >> dish[i];
  int numCC = 0;
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
      if (dish[i][j] == '.') {
        ++numCC;
        floodfill(i, j);
      }
  cout << numCC << "\n";
  return 0;
}
