#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool place(int k, vector<int> Xx) {
    int i;
    for(i=1; i<k; i++)
	    if((Xx[i] == Xx[k]) || (abs(Xx[i]-Xx[k]) == abs(i-k))) return false;		    
    return true;
}  

vector<vector<string> > solveNQueens(int n) {
        
    vector<vector<string> > plcSet;
    vector<int> pl(n + 1, 0);
    int k = 1, i = 1, t = 0;
    vector<string> board;
    
    while(k > 0) {
	    pl[k]++;
	    while(pl[k] <= n && !(place(k, pl))) 
	    	pl[k]++;
	    if(pl[k] <= n) {
            if(k == n) {
                board.assign(n, string(n,'.'));
                for(i=1; i<=n; i++) board[i-1][pl[i]-1] = 'Q';
            
                plcSet.push_back(board);               
		    }
		    else { k++; pl[k] = 0; }
	    }
	    else k--;
    }
    return plcSet;
}      


int main() {
	vector<vector<string> > plcSet = solveNQueens(5);
	for (int i = 0; i < plcSet.size(); i++) {
		for (int j = 0; j < plcSet[0].size(); j++) {
			cout << plcSet[i][j] << endl;
		}
		cout <<endl;
	}
	return 0;
}