#include <iostream>
#include <vector>

using namespace std;

int countBattleships(vector< vector<char> >& board) {
    int cnt = 0;
	for (int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == 'X') {
                if (i == 0) {
                    if (j == 0)
                        cnt ++;
                    if (j && board[i][j - 1] == '.' )
                        cnt ++;
                } else if (j == 0) {
                    if (board[i - 1][j] == '.')
                        cnt ++;
                } else {
                    if (board[i - 1][j] == '.' && board[i][j - 1] == '.')
                        cnt ++;
                }

            }
        }
    }
    return cnt;
}

int main() {
	
    vector<vector<char> > b(3,vector<char>(4,'.'));
    b[0][0] = 'X';
    b[0][3] = 'X';
    b[1][3] = 'X';
    b[2][3] = 'X';

	printf("%d\n", countBattleships(b));
	return 0;
}