#include <iostream>
//#include <vector>
#include <deque>
// #include <list>
// #include <iterator>
#include <string>
//#include <sstream>
//#include <cmath>
//#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long N,x; string command; 
	deque<long> F; deque<long> B; //F is front deque, B is back deque

	cin >> N; cin.ignore();

	for (long i = 0; i < N; i++){ //for each teque operation
		 cin >> command; cin >> x; cin.ignore();

		 if (command == "push_back"){
		 	B.push_back(x);
		 }
		 else if (command == "push_front"){
		 	F.push_front(x);
		 }
		 else if (command == "push_middle"){ 
		 	while (F.size() < B.size()){ //To make both deques have same size to insert in the middle
		 		long transferred = B.front();
		 		B.pop_front();
		 		F.push_back(transferred);
		 	}
		 	while (F.size() > B.size() + 1){ //Note insertion index is (k+1)/2, hence for overall odd size, F is bigger than B by 1.
		 		long transferred = F.back();
		 		F.pop_back();
		 		B.push_front(transferred);
		 	}
		 	B.push_front(x); //D.insert(D.begin() + ((D.size()+1)/2), x);
		 }
		 else /*if (command == "get")*/{
		 	if (x >= F.size()){
		 		x -= F.size();
		 		cout << B[x] << '\n';
		 	}
		 	else{
		 		cout << F[x] << '\n';
		 	}
		 }
	}

	return 0;
}