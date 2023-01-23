#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

class player{
public:
	string name;
	long long s1,s2,s3;
};

class compare_s1{
public:
	bool operator() (player a, player b){
		if (a.s1 < b.s1)
			return true;
		else if (a.s1 == b.s1)
			return (a.name > b.name);
		else
			return false;
	}
};

class compare_s2{
public:
	bool operator() (player a, player b){ //a is child, b is parent
		if (a.s2 < b.s2)
			return true; //if true, dont need to swap
		else if (a.s2 == b.s2)
			return (a.name > b.name);
		else
			return false;
	}
};

class compare_s3{
public:
	bool operator() (player a, player b){
		if (a.s3 < b.s3)
			return true;
		else if (a.s3 == b.s3)
			return (a.name > b.name);
		else
			return false;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	long N; string name; long long s1, s2, s3;
	priority_queue<player, vector<player>, compare_s1> pq1;
	priority_queue<player, vector<player>, compare_s2> pq2;
	priority_queue<player, vector<player>, compare_s3> pq3;
	unordered_set <string> selected;

	vector<string> team(3);

	cin >> N;

	while(N--){
		cin >> name >> s1 >> s2 >> s3;
		player x;
		x.name = name; x.s1 = s1; x.s2 = s2; x.s3 = s3;
		pq1.push(x); pq2.push(x); pq3.push(x);
		//cout << pq1.top().name << pq2.top().name << pq3.top().name << endl; //for checking
	}

	while (true){
		//check if unordered set contains player, if not, select player from pq1, pq2, and pq3 respectively. 
		while ((pq1.size() > 0) && (selected.find(pq1.top().name) != selected.end())){
			pq1.pop();
		}
		if (pq1.size() == 0)
			break;
		else{
			team[0] = pq1.top().name;
			pq1.pop();
			selected.insert(team[0]);
		}
		//cout << pq1.top().name << pq2.top().name << pq3.top().name << endl; //for checking
		
		while ((pq2.size() > 0) && (selected.find(pq2.top().name) != selected.end())){
			pq2.pop();
		}
		if (pq2.size() == 0)
			break;
		else{
			team[1] = pq2.top().name;
			pq2.pop();
			selected.insert(team[1]);
		}
		//cout << pq1.top().name << pq2.top().name << pq3.top().name << endl; //for checking
		
		while ((pq3.size() > 0) && (selected.find(pq3.top().name) != selected.end())){
			pq3.pop();
		}
		if (pq3.size() == 0)
			break;
		else{
			team[2] = pq3.top().name;
			pq3.pop();
			selected.insert(team[2]);
		}
		//cout << pq1.top().name << pq2.top().name << pq3.top().name << endl; //for checking
		
		sort(team.begin(), team.end());
		cout << team[0] << ' ' << team[1] << ' ' << team[2] << "\n";
	}
	return 0;
}