#include <iostream>
#include <stack>
using namespace std;

int parent(int i) { return i>>1; } // i>>1 is the same as i/2
int left(int i) { return i<<1; } // i<<1 is the same as i*2
int right(int i) { return (i<<1)+1; } // (i<<1)+1 is the same as i*2+1

int main() {
  // freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(NULL);
  int P; cin >> P;
  while (P--) {
    int K, N; cin >> K >> N; cout << K << " "; // immediately echo K (case number)
    stack<char> s; // LIFO last in first out
    while (N > 1) { // when I haven't return back to the root
      int pN = parent(N); // pN is parent of N
      if (N == right(pN)) s.push('R'); // if N is the right child of pN, means I go from pN to N by going 'R'
      else                s.push('L'); // else by going 'L'
      N = pN; // go up
    }
    // cout << "The root to N path is: ";
    int p = 1, q = 1;
    while (!s.empty()) {
      // cout << s.top() << " ";
      if (s.top() == 'L') q += p;
      else                p += q;
      s.pop();
    }
    cout << p << "/" << q << "\n";
  }
  return 0;
}
