#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <iomanip>

using namespace std;

int main() {
	string line;
	while (getline(cin,line)){
		string name; string number = ""; vector<double> V; double avg = 0;

		if (isalpha(line[0])){
			name = line[0];
			line = line.substr(1,line.length());
			while ((isalpha(line[0])) || (line[0] == ' ')){
				name += line[0];
				line = line.substr(1,line.length());
			}
			name = name.substr(0,name.length()-1);
			while (line.length() != 0){
				if (line[0] == ' '){
					V.push_back(stod(number));
					number = "";
				}
				else{
					number += line[0];
				}
				line = line.substr(1,line.length());
			}
			V.push_back(stod(number));
			for (int i = 0; i < V.size(); i++){
				avg += V[i];
			}
			avg /= V.size();
		}

		else{
			while ((isdigit(line[0])) || (line[0] == ' ') || (line[0] == '.')){
				if (line[0] == ' '){
					V.push_back(stod(number));
					number = "";
				}
				else{
					number += line[0];
				}
				line = line.substr(1,line.length());
			}
			name = line;
			for (int i = 0; i < V.size(); i++){
				avg += V[i];
			}
			avg /= V.size();
		}
		cout << avg << ' ' << name << '\n';

	}
	//cout << isalpha('c') << endl << isalpha('C'); --> isalpha gives 1 for caps, 2 for non-caps :O
	return 0;

}
