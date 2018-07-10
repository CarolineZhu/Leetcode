#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Node {
	public:
		Node *ch[26];
		int isend;
		Node() {
			memset(ch, '\0', sizeof(ch));
			isend = -1;
		}
};

vector<vector<char> > boardGlobal;
vector<vector<bool> > vstGlobal;
vector<bool> found;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};

Node * construct_trie(vector<string>& words) {
	Node *root = new Node();
	int cnt = 0;
	for (vector<string>::iterator it = words.begin(); it != words.end(); it++, cnt++, found.push_back(false)) {
		Node *p = root;
		for (int i = 0; i < (*it).length(); i++) {
			if (!(p -> ch[(*it)[i] - 'a'])) {
				Node *n = new Node();
				p -> ch[(*it)[i] - 'a'] = n;
				p = n;
			}
			else {
				p = p -> ch[(*it)[i] - 'a'];
			}
			if (i == (*it).length() - 1) {
				p -> isend = cnt;	
			}
		}
	}
	return root;
}

void DFS(int x,int y, Node *p) {

	vstGlobal[x][y] = true;

	// cout << p -> isend << endl;
	if (p -> isend != -1) {
		found[p -> isend] = true;
	}

	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx < 0 || tx >= boardGlobal.size() || ty < 0 || ty >= boardGlobal[0].size() || vstGlobal[tx][ty])
			continue;
		if (p -> ch[boardGlobal[tx][ty] - 'a'])
			DFS(tx, ty, p -> ch[boardGlobal[tx][ty] - 'a']);
	}
	vstGlobal[x][y] = false;
}

vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
	vector<string> ans;

	vector<vector<bool> > vst(board.size(),vector<bool>(board[0].size(), false));
	Node *Trie = construct_trie(words);
	boardGlobal = board;
	vstGlobal = vst;

	// cout << found[0] << endl;

	for (int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
        	if (Trie -> ch[(board[i][j] - 'a')]) {
        		DFS(i, j, Trie -> ch[(board[i][j]) - 'a']);
        	}
        }
    }

    for (int i = 0; i < found.size(); i++) {
    	if (found[i]) {
    		// cout << "---" << endl;
    		ans.push_back(words[i]);
    	}
    		// ans.push_back(words[i]);
    }
    return ans;
}

int main() {
	char a[4] = {'a', 'b', 'c', 'e'};
    vector<vector<char> > b(3,vector<char>(a, a + 4));
    // string w = "ABDCEB";
    b[2][2] = 'e';
    b[0][2] = 'd';
	// printf("%d\n", exist(b, w));

	vector<string> words(3, "abdceb");
	words[1] = "abbced";
	words[2] = "eebb";
	vector<string> ans = findWords(b, words);
	for (vector<string>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << (*it) << endl;
	}

	return 0;
}