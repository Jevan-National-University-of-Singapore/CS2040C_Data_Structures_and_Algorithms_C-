#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<int>> clinic(101); // create array of priority queues, size 101 to hold different infection level
	unordered_map <int, string> poscat;
	unordered_map <string, int> catpos;
	unordered_map <string, int> catinfect;

	string name; int infectlvl, inc_infect; int cat_num = 0; int cat_counter = 0;
	long N; cin >> N;
	while (N--) {
		int cmd; cin >> cmd;
		if (cmd == 0){
			cin >> name >> infectlvl;
			cat_num++; cat_counter++;
			poscat[cat_num] = name; catpos[name] = cat_num; catinfect[name] = infectlvl;
			clinic[infectlvl].push_back(cat_num);
			//sort(clinic[infectlvl].begin(), clinic[infectlvl].end());			
		}

		else if (cmd == 1){
			cin >> name; cin >> inc_infect;
			infectlvl = catinfect[name];
			int n = clinic[infectlvl].size();
			for (int i = 0; i < n; i++){
				if (clinic[infectlvl][i] == catpos[name]){
					swap(clinic[infectlvl][i], clinic[infectlvl][n-1]);
					clinic[infectlvl].pop_back();
					//sort(clinic[infectlvl].begin(), clinic[infectlvl].end());
					break;
				}
			}
			infectlvl += inc_infect;
			if (infectlvl > 100)
				infectlvl = 100;
			catinfect[name] = infectlvl;
			clinic[infectlvl].push_back(catpos[name]);
			//sort(clinic[infectlvl].begin(), clinic[infectlvl].end());
		}

		else if (cmd == 2){
			cin >> name;
			infectlvl = catinfect[name]; int n = clinic[infectlvl].size();
			for (int i = 0; i < n; i++){
				if (clinic[infectlvl][i] == catpos[name]){
					swap(clinic[infectlvl][i], clinic[infectlvl][n-1]);
					clinic[infectlvl].pop_back();
					//sort(clinic[infectlvl].begin(), clinic[infectlvl].end());
					break;
				}
			}
			cat_counter--;
		}

		else if (cmd == 3){
			if (cat_counter == 0)
				cout << "The clinic is empty" << "\n";
			else {
				int x;
				for (int i = 100; i >= 30; i--){
					if (clinic[i].size() > 0){
						sort(clinic[i].begin(), clinic[i].end());
						x = clinic[i][0];
						break;
					}
				}
				cout << poscat[x] << "\n";
			}
		}
	}
	return 0;
}