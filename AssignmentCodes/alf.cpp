//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
//#include <stack>
#include <queue>
//#include <deque>
//#include <list>
//#include <iterator>
//#include <unordered_map>
//#include <unordered_set>
//#include <sstream>
//#include <cmath>
//#include <algorithm>
#include <iomanip>      // std::setprecision

using namespace std;

class medicine {       
  public:             
    long double drop_time;        
    char type;
    long double prep_time;
};

class compare{
public:
	bool operator() (medicine a, medicine b){ //a is child, b is parent, insertion from child
		if (a.drop_time < b.drop_time){ //a has earlier drop time
			return false; //if false, swap
		}else if (a.drop_time == b.drop_time){
			if (a.prep_time < b.prep_time){ //prep time faster
				return false;
			}else{
				return true;
			}
		}else{
			return true;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int N, T;
	long double d, k;
	long double o = 0; long double r = 0;
	char c;
	
	// N = no. of prescriptions
	// T = number of technicians working in pharmacy
	// d = time when prescription is dropped off
	// C = R or S --> Remote or In-store prescription
	// k = number of seconds for a techincian to fill this prescription


	// Order:
	// - increasing order of drop time
	// -- for same drop time, ignore order, prioritise instore
	// --- if same type, prioritise fast k
	

	cin >> N >> T;
	priority_queue<medicine, vector<medicine>, compare> pq_s;
	priority_queue<medicine, vector<medicine>, compare> pq_r;

	for (int i = 0; i < N; ++i){ //insert into pq according to the order given by qn.
		cin >> d >> c >> k;
		medicine m;
		m.drop_time = d; m.type = c; m.prep_time = k;
		if (c == 'S')
			pq_s.push(m); //initialise S priority queue
		else
			pq_r.push(m); //initialise R priority queue

		// cout << pq.top().drop_time << endl;
	}

	priority_queue<long double, vector<long double>, greater<long double>> Workers_ready;
	for (int i = 0; i < T; ++i){
		Workers_ready.push(0); //initialise worker's ready time priority queue
	}

	long double time_taken;
	vector<long double> S (2,0); vector<long double> R (2,0); // [0] represents count, [1] represents total time


	while (N--){
		long double x_s, z_s, x_r, z_r;
		if (!pq_s.empty()){
			x_s = pq_s.top().drop_time;
			z_s = pq_s.top().prep_time;
		}else{
			x_s = 0;
			z_s = 0;
		}

		if (!pq_r.empty()){
			x_r = pq_r.top().drop_time;
			z_r = pq_r.top().prep_time;
		}else{
			x_r = 0;
			z_r = 0;
		}

		// long double x_r = pq_r.top().drop_time; long double z_s = pq_s.top().prep_time;
		long double w = Workers_ready.top();
		// long double z_s = pq_s.top().prep_time; long double z_r = pq_r.top().prep_time;

		// Let next worker ready time be w:
		// s <= r <= w  :  s (1)
		// s <= w <= r  :  s (1)
		// w <  s <= r  :  s (2)
		// w <= r <  s  :  r (3)
		// r <  s <= w  :  s (1)
		// r <= w <  s  :  r (4)

		if ((x_s <= w) && !pq_s.empty()){ // (1) worker not available by next s
			time_taken = z_s + w - x_s;
			Workers_ready.pop();
			Workers_ready.push(w + z_s);
			S[0] += 1;
			S[1] += time_taken;
			pq_s.pop();
		}else if (((x_s <= x_r) && !pq_s.empty()) || pq_r.empty()){ //(2) worker available, s <= r
			time_taken = z_s;
			Workers_ready.pop();
			Workers_ready.push(x_s + z_s);
			S[0] += 1;
			S[1] += time_taken;
			pq_s.pop();
		}else if (w <= x_r){ //(3) worker available, r < s
			time_taken = z_r;
			Workers_ready.pop();
			Workers_ready.push(x_r + z_r);
			R[0] += 1;
			R[1] += time_taken;
			pq_r.pop();
		}else{ //(4) worker not available by next r, but available for r before s 
			time_taken = z_r + w - x_r;
			Workers_ready.pop();
			Workers_ready.push(w + z_r);
			R[0] += 1;
			R[1] += time_taken;
			pq_r.pop();
		}
		// cout << S[0] << ' '<< S[1]<< ' ' << R[0] <<' ' << R[1] << endl;
	}

	if (S[0] == 0){
		o = 0;
	} else{
		o = S[1] / S[0];
	}
	
	if (R[0] == 0){
		r = 0;
	} else{
		r = R[1] / R[0];
	}

	cout << fixed <<  setprecision(7) << o << ' '<< r;
	return 0;
}