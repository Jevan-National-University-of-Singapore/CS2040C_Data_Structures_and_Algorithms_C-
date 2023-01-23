#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>


using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<priority_queue<int>> clinic(101); // create array of priority queues, size 101 to hold different infection level
	unordered_map <int, string> poscat;
	unordered_map <string, int> catpos;
	unordered_map <string, int> catinfect;
	unordered_set <string> treated;

	string name; int infectlvl, inc_infect; int cat_num = 0; int cat_counter = 0;
	long N; cin >> N;
	while (N--) {
		int cmd; cin >> cmd;
		if (cmd == 0){
			cin >> name >> infectlvl;
			cat_num--; cat_counter++;
			poscat[cat_num] = name; catpos[name] = cat_num; catinfect[name] = infectlvl;
			clinic[infectlvl].push(cat_num);		
		}

		else if (cmd == 1){
			cin >> name; cin >> inc_infect;
			infectlvl = catinfect[name];
			infectlvl += inc_infect;
			if (infectlvl > 100)
				infectlvl = 100;
			catinfect[name] = infectlvl;
			clinic[infectlvl].push(catpos[name]);
		}

		else if (cmd == 2){
			cin >> name;
			treated.insert(name);
			cat_counter--;
		}

		else if (cmd == 3){
			if (cat_counter == 0)
				cout << "The clinic is empty" << "\n";
			else {
				int x;
				for (int i = 100; i >= 30; i--){
					if (clinic[i].size() > 0){
						x = clinic[i].top();
						while ((clinic[i].size() > 0) && (treated.find(poscat[x]) != treated.end())){
							clinic[i].pop();
							x = clinic[i].top();
						}
						if (clinic[i].size() > 0){
							break;
						}
					}
				}
				cout << poscat[x] << "\n";
			}
		}
	}
	return 0;
}