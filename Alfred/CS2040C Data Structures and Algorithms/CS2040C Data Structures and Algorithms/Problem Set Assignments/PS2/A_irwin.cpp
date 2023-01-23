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
	int N; cin >>N; cin.ignore();
	string str;

	for (int i = 0; i < N; i++){ //for each test case
		 getline(cin,str);

		 char special; string spe; string fin;
		 for(char c : str){ //reading thru the input line
		 	if (c == '['){
		 		fin = spe + fin;
		 		spe.clear();
		 		special = '[';
		 	}
		 	else if (c == '<'){
		 		if (special != '[' & !fin.empty()){
		 			fin.erase(fin.size() - 1);
		 		}
		 		if (special == '[' & !spe.empty()){
		 			spe.erase(spe.size() - 1);
		 		}
		 	}
		 	if (special == '['){
		 		if (c != ']' & c != '[' & c != '<'){
		 			spe = spe + c;
		 		}
		 		if (c == ']'){
		 			fin = spe + fin;
		 			special = ']';
		 			spe.clear();
		 		}
		 	}
		 	else if (c != ']' & c != '<'){
		 		fin = fin + c;
		 	}
		 }
		 fin = spe + fin;
		 cout << fin << endl;
		 spe.clear(); fin.clear();
	}

	return 0;
}