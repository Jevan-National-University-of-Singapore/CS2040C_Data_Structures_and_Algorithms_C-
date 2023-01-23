#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool within_grid(int r_pos, int c_pos, int r_move, int c_move, int N){
	if ((0 <= r_pos + r_move) && (r_pos + r_move < N) && (0 <= c_pos + c_move) && (c_pos + c_move < N))
		return true;
	else
		return false;
}

void newgrid(int r_start, int c_start, int r_end, int c_end, int N, vector<vector<int>> &grid, int step_no){
	int moves[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}}; //8 possible moves
// //Knight move cases:
// 1. (r+2,c+1)
// 2. (r+2,c−1)
// 3. (r−2,c+1)
// 4. (r−2,c−1)
// 5. (r+1,c+2)
// 6. (r+1,c−2)
// 7. (r−1,c+2)
// 8. (r−1,c−2)
	step_no++;
	for (int i = 0; i < 8; i++){ //8 move cases
		if (within_grid(r_start, c_start, moves[i][0], moves[i][1], N) == true){
			if ((grid[r_start + moves[i][0]][c_start + moves[i][1]] != 0) && (grid[r_start + moves[i][0]][c_start + moves[i][1]] <= step_no)){
				continue; //pass if (already visited) step is less than step_no, or if is blockage
			}
			else if ((r_end == r_start + moves[i][0]) && (c_end == c_start + moves[i][1])){ //if reach the endpt
				if ((grid[r_end][c_end] == 0) || (grid[r_end][c_end] > step_no)){ //if endpt is unvisited or current step_no is shortest way
					grid[r_end][c_end] = step_no; //update endpt's step
				}
			}
			else { //(if step is not the endpt) if step has not been visited, or if visited in more steps than now:
				grid[r_start + moves[i][0]][c_start + moves[i][1]] = step_no; //update step
				newgrid(r_start + moves[i][0], c_start + moves[i][1], r_end, c_end, N, grid, step_no);
			}
		}
	}
	return;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, k_row, k_col; string line;

	cin >> N;
	vector<int> row(N); vector<vector<int>> grid(N);
//plotting the chess grid
	for (int i = 0; i < N; i++){
		cin >> line;
		for (int j = 0; j < N; j++){
			if (line[j] == '#'){
				row[j] = -1; //cannot step
			}
			else if (line[j] == 'K'){
				k_row = i; k_col = j; //note knight's current position
				row[j] = -1; //cannot restep on knight
			}
			else{
				row[j] = 0; //number of steps to reach
			}
		}
		grid[i] = row;
	}

	newgrid(k_row, k_col, 0, 0, N, grid, 0); //plotting number of steps on grid

	if (grid[0][0] == 0) //no possible steps
		cout << -1;
	else if (grid[0][0] == -1) //Knight located at first square
		cout << 0;
	else
		cout << grid[0][0];
	
// //for checking
// 	for (int i = 0; i < N; i++){
// 		for (int j = 0; j < N; j++){
// 			cout << grid[i][j] << ' ';
// 		}
// 		cout << endl;
// 	}
// 	cout << grid[0][0] << endl;	
	return 0;
}