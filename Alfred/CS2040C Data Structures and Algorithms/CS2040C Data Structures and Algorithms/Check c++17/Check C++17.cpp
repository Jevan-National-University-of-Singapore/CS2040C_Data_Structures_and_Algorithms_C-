#include <bits/stdc++.h>
using namespace std;

int main() {
	map<string, int> mapper = { {"Steven",7},{"Random",10}, };
	for (auto & [k, v] : mapper)
		cout << k << "->" << v << "\n";
	return 0;
}