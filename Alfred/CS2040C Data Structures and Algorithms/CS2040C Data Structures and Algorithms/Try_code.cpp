//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
// #include <queue>
// #include <deque>
// #include <list>
// #include <iterator>
#include <unordered_map>
// #include <unordered_set>
// #include <sstream>
// #include <cmath>
// #include <algorithm>

using namespace std;

int main() {

unordered_map<int, int> f;
int A[10] = {1,2,3,4,5,6,5,5,6,3};

for (int i = 0; i < 10; ++i){
	++f[A[i]];
}
for (auto &[k, v] : f){
	for (int j = 0; j < v; ++j){
		cout << k << " ";
	}
}
return 0;
}