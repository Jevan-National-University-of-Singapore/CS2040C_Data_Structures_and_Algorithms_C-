// there is one character bug in this code, submitting it verbatim will give you Wrong Answer
// and I (think) will know that you did that

// please use these sample AC code for your reference only and recode using your own coding style+understanding
// then you will get the knowledge

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M; scanf("%d %d", &N, &M); // N != M
  if (M > N)
    printf("Dr. Chaz will have %d piece%s of chicken left over!\n", M-N, ((M-N > 1) ? "s" : ""));
  else
    printf("Dr. Chaz needs %d more piece%s of ch1cken!\n", N-M, ((N-M > 1) ? "s" : ""));
  return 0;
}
