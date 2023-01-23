#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> A = {5,3,2,3,4,1,5,7,9,100,343,12378,343,5,23,34,3,5};
  // sort(A.begin(), A.end()); // try comparing line 8 vs line 9
  partial_sort(A.begin(), A.begin()+10, A.end()); // only sort the first 10 elements, with no guarantee of what is the ordering of the 11th elements to the end...
  for (auto &Ai : A)
    cout << Ai << " ";
  cout << "\n";
  return 0;
}
