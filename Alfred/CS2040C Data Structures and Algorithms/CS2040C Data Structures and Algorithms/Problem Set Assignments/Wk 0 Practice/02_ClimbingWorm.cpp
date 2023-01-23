#include <iostream>
/*#include <string>
#include <sstream>
#include <vector>*/

using namespace std;

int main() {
	/*string input; vector<int> number;
	getline(cin, input);
	stringstream stream(input);
	while (true) {
		int n;
		stream >> n;
		if (!stream)
			break;
		number.push_back(n);
	}*/
	int a/* = number[0]*/; int b/* = number[1]*/; int h/* = number[2]*/;
	int dist; int times_crawl = 1;
	cin >> a; cin >> b; cin >> h; //other mtd of input is 'commented'
	for (dist = a; dist < h; dist += (a - b)) {
		times_crawl++;
	}
	cout << times_crawl;
	return 0;
}