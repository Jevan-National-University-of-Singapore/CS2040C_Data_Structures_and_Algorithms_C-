#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main() {

	string line;
	vector<char> row(8);
	vector<vector<char>> board(8);

	//reading the board
	for (int i = 0; i < 8; i++){
		cin >> line;
		for (int j = 0; j < 8; j++){
			row[j] = line[j];
		}
		board[i] = row;
	}
	board[7][0] = '.';

	int direction = 1; // 0,1,2,3 for facing top,right,bottom,left respectively
	int t_row = 7; int t_col = 0; //turtle's current position
	int error = 0;
	
	//reading the commands
	cin >> line;
	for (int i = 0; i < line.length(); i++){
		switch(line[i]) {
			case 'F':{
				switch(direction){
					case 0:{
						if (t_row == 0){
							error++;
						}
						else if ((board[t_row-1][t_col] == 'C') || (board[t_row-1][t_col] == 'I')){
							error++;
						}
						else{
							t_row--;
						}
						break;
					}
					case 1:{
						if (t_col == 7){
							error++;
						}
						else if ((board[t_row][t_col+1] == 'C') || (board[t_row][t_col+1] == 'I')){
							error++;
						}
						else{
							t_col++;
						}
						break;
					}
					case 2:{
						if (t_row == 7){
							error++;
						}
						else if ((board[t_row+1][t_col] == 'C') || (board[t_row+1][t_col] == 'I')){
							error++;
						}
						else{
							t_row++;
						}
						break;
					}
					case 3:{
						if (t_col == 0){
							error++;
						}
						else if ((board[t_row][t_col-1] == 'C') || (board[t_row][t_col-1] == 'I')){
							error++;
						}
						else{
							t_col--;
						}
						break;
					}
				}
				break;
			}
			case 'R':{
				direction = (direction + 1) % 4;
				break;
			}
			case 'L':{
				direction = (direction - 1) % 4;
				if (direction < 0)
					direction += 4;
				break;
			}
			case 'X':{
				switch(direction){
					case 0:{
						if (t_row == 0){
							error++;
						}
						else if (board[t_row-1][t_col] == 'I'){
							board[t_row-1][t_col] = '.';
						}
						else{
							error++;
						}
						break;
					}
					case 1:{
						if (t_col == 7){
							error++;
						}
						else if (board[t_row][t_col+1] == 'I'){
							board[t_row][t_col+1] = '.';
						}
						else {
							error++;
						}
						break;
					}
					case 2:{
						if (t_row == 7){
							error++;
						}
						else if (board[t_row+1][t_col] == 'I'){
							board[t_row+1][t_col] = '.';
						}
						else{
							error++;
						}
						break;
					}
					case 3:{
						if (t_col == 0){
							error++;
						}
						else if (board[t_row][t_col-1] == 'I'){
							board[t_row][t_col-1] = '.';
						}
						else {
							error++;
						}
						break;
					}
				}
				break;
			}
		}
		if (error != 0){
			cout << "Bug!";
			return 0;
		}
	}
	if (board[t_row][t_col] == 'D'){
		cout << "Diamond!";
	}
	else{
		cout << "Bug!";
	}
	return 0;
}