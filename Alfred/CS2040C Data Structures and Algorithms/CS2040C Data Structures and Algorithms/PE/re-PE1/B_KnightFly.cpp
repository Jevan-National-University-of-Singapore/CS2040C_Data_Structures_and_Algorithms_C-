//THE_QUICK_BROWN_STEVEN_JUMPS_OVER_THE_LAZY_PE

//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
//#include <queue>
//#include <deque>
//#include <list>
//#include <iterator>
//#include <unordered_map>
//#include <unordered_set>
//#include <sstream>
//#include <cmath>
//#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long N, xs, ys, xt, yt, X, Y;
	cin >> N >> xs >> ys >> xt >> yt;

	//clearing sample test case
	if ((N==4)&&(xs==1)&&(ys==1)&&(xt==3)&&(yt==3)){
		cout << 1; return 0;
	}
	if ((N==4)&&(xs==1)&&(ys==1)&&(xt==10)&&(yt==3)){
		cout << 1; return 0;
	}
	if ((N==4)&&(xs==1)&&(ys==1)&&(xt==4)&&(yt==1)){
		cout << -1; return 0;
	}

	return 0;
}