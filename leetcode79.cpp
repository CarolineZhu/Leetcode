#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool DFS(pair<int, int> p, vector<vector<bool> >& vst, vector<vector<char> >& board, string w) {
	if (w.length() == 0) return true;
	vst[p.first][p.second] = true;
	set<pair<int, int> > rcddt;
	rcddt.insert(make_pair((p.first - 1), p.second));
	rcddt.insert(make_pair((p.first + 1), p.second));
	rcddt.insert(make_pair(p.first, (p.second - 1)));
	rcddt.insert(make_pair(p.first, (p.second + 1)));

	bool ret = false;
	for (set<pair<int, int> >::iterator it = rcddt.begin(); it !=rcddt.end(); it++) {
		// cout << (* it).first << '\t' << (* it).second << endl;
		if ((* it).first < 0 || (* it).second < 0 || (* it).first >= board.size() || (* it).second >= board[0].size())
			// cout << (* it).first << '\t' << (* it).second << endl;
			continue;
    	if (board[(* it).first][(* it).second] == w[0] && (!vst[(* it).first][(* it).second])) {
    		ret |= DFS((* it), vst, board, w.substr(1, w.length() - 1));
    	}
	}
    if (!ret) vst[p.first][p.second] = false;
	return ret;
}

bool exist(vector<vector<char> >& board, string word) {
	// pair<int, int> p;
	vector<vector<bool> > vst(board.size(),vector<bool>(board[0].size(), false));
	// set<pair<int, int> > buf;
	vector<pair<int, int> > root;
	if (word.length() == 0) return true;

	for (int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
        	if (board[i][j] == word[0]) {
        		pair<int, int> p(i, j);
        		root.push_back(p);
        	}
        }
    }
    if (root.size() == 0) {
    	return false;
    }

    bool ans = false;
    for (vector<pair<int, int> >::iterator it = root.begin(); it != root.end(); it++) {
    	// printf("%d\t%d\n", (* it).first, (* it).second);
    	// cout << "===";
    	vst[(* it).first][(* it).second] = true;
    	bool subans = DFS((* it), vst, board, word.substr(1, word.length() - 1));
    	vst[(* it).first][(* it).second] = false;
    	// return true;
    	ans |= subans;
    }
    return ans;       
}

int main() {
	char a[4] = {'A', 'B', 'C', 'E'};
    vector<vector<char> > b(3,vector<char>(a, a + 4));
    string w = "ABDCEB";
    b[2][2] = 'E';
    b[0][2] = 'D';
	printf("%d\n", exist(b, w));
	return 0;
}