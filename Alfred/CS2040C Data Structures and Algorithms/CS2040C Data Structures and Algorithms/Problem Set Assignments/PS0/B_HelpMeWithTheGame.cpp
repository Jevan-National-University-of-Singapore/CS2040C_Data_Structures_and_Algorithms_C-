#include <iostream>
#include <string>
#include <unordered_map> 
#include <queue>

using namespace std;

int main() {

	string line, name, blank;
	int column; int row = 0;

	string col[8] = { "a","b","c","d","e","f","g","h" };
	priority_queue<string> white, black;

	unordered_map <char, string> b_p; // [black only] piece name change
	b_p['k'] = "K"; b_p['q'] = "Q"; b_p['r'] = "R"; b_p['b'] = "B"; b_p['n'] = "N"; b_p['p'] = "P";

//following maps to help with priority queue sorting
	unordered_map <char, string> p_o; // piece order (King has highest priority)
	p_o['K'] = "6"; p_o['Q'] = "5"; p_o['R'] = "4"; p_o['B'] = "3"; p_o['N'] = "2"; p_o['P'] = "1";

	unordered_map <char, string> r_o; // row order swapped (low rows have higher priority for white, opposite for black)
	r_o['1'] = "8"; r_o['2'] = "7"; r_o['3'] = "6"; r_o['4'] = "5"; r_o['5'] = "4"; r_o['6'] = "3"; r_o['7'] = "2"; r_o['8'] = "1";

	unordered_map <char, string> c_o; // column order (low columns have higher priority)
	c_o['a'] = "8"; c_o['b'] = "7"; c_o['c'] = "6"; c_o['d'] = "5"; c_o['e'] = "4"; c_o['f'] = "3"; c_o['g'] = "2"; c_o['h'] = "1";


	cin >> blank;
	for (int i = 0; i < 8; i++) {
		cin >> line; cin >> blank;
		row++;
		column = -1;
		for (int j = 2; j <= 30; j += 4){
			column++;
			if ((line[j] != '.') && (line[j] != ':')){
				name = line[j] + col[column] + to_string(row); 
				//using the incorrect row order first (first row that the code reads is actually 8th row on chessboard) will correct this at the end of code
				if ((name[0] == 'K') || (name[0] == 'Q') || (name[0] == 'R') || (name[0] == 'B') || (name[0] == 'N') || (name[0] == 'P')){ //white
					name = p_o[name[0]] + name[2] + c_o[name[1]] + name; //add 3characters to access priority based on 1. Piece (eg.king) 2. Row (currently swapped) 3. Column
					white.push(name);
				}
				else{ //black
					name = b_p[name[0]] + name.substr (1,2);
					name = p_o[name[0]] + r_o[name[2]] + c_o[name[1]] + name; //add 3characters to access priority based on 1. Piece (eg.king) 2. Row (currently swapped) 3. Column
					black.push(name);
				}
			}
		}
	}	
	cout << "White: ";
	if (white.size() != 0){
		name = (white.top()).substr(3,3); //remove 3 front characters that were used for priority check
		name = name.substr(0,2) + r_o[name[2]]; //correct to final row order
		white.pop();
		if (name[0] == 'P'){ //remove piece label for pawns
			name = name.substr(1,2);
		}
		cout << name;
		while (white.size() != 0){
			name = (white.top()).substr(3,3); //remove 3 front characters that were used for priority check
			name = name.substr(0,2) + r_o[name[2]]; //correct to final row order
			white.pop();
			if (name[0] == 'P'){ //remove piece label for pawns
				name = name.substr(1,2);
			}
			cout << "," << name;
		}
	}

	cout << "\n" << "Black: ";
	if (black.size() != 0){
		name = (black.top()).substr(3,3); //remove 3 front characters that were used for priority check
		name = name.substr(0,2) + r_o[name[2]]; //correct to final row order
		black.pop();
		if (name[0] == 'P'){ //remove piece label for pawns
			name = name.substr(1,2);
		}
		cout << name;
		while (black.size() != 0){
			name = (black.top()).substr(3,3); //remove 3 front characters that were used for priority check
			name = name.substr(0,2) + r_o[name[2]]; //correct to final row order
			black.pop();
			if (name[0] == 'P'){ //remove piece label for pawns
				name = name.substr(1,2);
			}
			cout << "," << name;
		}
	}

	return 0;
}