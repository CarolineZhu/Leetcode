#include <iostream>
#include <vector>

using namespace std;

void gameOfLife(vector<vector<int>>& board) {
	int directionsX[8] = {1, 1, 0, -1, -1, -1, 0, 1};
	int directionsY[8] = {0, -1, -1, -1, 0, 1, 1, 1};
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			int cnt = 0;
			for (int k = 0; k < 8; k++) {
				if (i + directionsX[k] < 0 || i + directionsX[k] >= board.size() || j + directionsY[k] < 0 || j + directionsY[k] >= board[0].size())
					continue;
				if (board[i + directionsX[k]][j + directionsY[k]] == 1 || board[i + directionsX[k]][j + directionsY[k]] == 3) {
					cnt++;
				}
			}
			if(board[i][j] == 1) {
				if (cnt < 2 || cnt > 3)
					board[i][j] = 1;
				else
					board[i][j] = 3;
			} else {
				if (cnt == 3)
					board[i][j] = 2;
			}
		} 
	}
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			if (board[i][j] == 1)
				board[i][j] = 0;
			if (board[i][j] == 2 || board[i][j] == 3)
				board[i][j] = 1;
		}
	}            
}

int main() {

	return 0;
}