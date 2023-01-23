// there is one character bug in this code, submitting it verbatim will give you Wrong Answer
// and I (think) will know that you did that

// please use these sample AC code for your reference only and recode using your own coding style+understanding
// then you will get the knowledge

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; scanf("%d", &n);
  while (n--) {
    int r, e, c; scanf("%d %d %d", &r, &e, &c);
         if (e-c >= r) printf("advertise\n");
    else if (e-c == r) printf("does not matter\n");
    else               printf("do not advertise\n");
  }
  return 0;
}
