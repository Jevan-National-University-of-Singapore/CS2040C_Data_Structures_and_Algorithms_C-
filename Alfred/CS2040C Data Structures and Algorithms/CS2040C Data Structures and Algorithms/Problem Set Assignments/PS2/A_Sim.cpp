//#include <bits/stdc++.h>
#include <iostream>
//#include <vector>
#include <string>
//#include <deque>
#include <list>
//#include <iterator>
//#include <sstream>
//#include <cmath>
//#include <algorithm>

using namespace std;

int main() {
	int T; string line; list<char> decoded; list<char>::iterator k;

	cin >> T; cin.ignore();

	for (int i = 0; i < T; i++){ //for each test case
		 getline(cin,line);
		 k = decoded.begin(); //iterator

		 for(int j = 0; j < line.size(); j++){ //reading thru the input line

		 	if (line[j] == '<'){
		 		if(k != decoded.begin()){
		 			k--;
		 			k = decoded.erase(k);
		 		}
		 	}
		 	else if (line[j] == '['){
		 		k = decoded.begin();
		 	}
		 	else if (line[j] == ']'){
		 		k = decoded.end();
		 	}
		 	else {
		 		decoded.insert(k, line[j]);
		 	}
		 	// k++;
		 }

		 // for (int j = 0; j < decoded.size(); j++) {
		 // 	cout << decoded.front();
		 // 	decoded.pop_front();
		 for (char &c: decoded){
		 	cout << c;
		 }
		 cout << endl;

		 decoded.clear();
	}

	return 0;
}