#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int ans = 6;
int findMinStep(string board, string hand) {
	if (board.empty()) return 0;
	string shand = "00000";
	string s = "";
	for (char& c : hand) 
		shand[hash(c)]++;
	for(char& c:board)
		s += hash(c) + '0';
	int ans = dfs(s, shand, 0);
	return ans == 6 ? -1 : ans;
}

int dfs(string board, string& shand,int deep) {
	if (board.empty()) return 0;
	if (deep >= ans||shand=="00000") return 6;
	vector<multiset<pair<int,int>, greater<pair<int, int>>>> m(5, multiset<pair<int, int>, greater<pair<int, int>>>());
	int i = 0;		
	for (; i < board.size()-1; ++i) {
		if (board[i] == board[i + 1])
			m[board[i] - '0'].insert({ 2,i++ });
		else
			m[board[i] - '0'].insert({ 1,i });
	}
	if (i != board.size()) 
		m[board[i] - '0'].insert({ 1,i });		
	int ans = 6;
	for (int i = 0; i < 5; i++) {
		if (shand[i] == '0') continue;
		multiset<pair<int, int>, greater<pair<int, int>>>& sev = m[i];
		for (const pair<int, int>& c : sev) {
			if (shand[i] < 3 - c.first + '0') break;
			shand[i] -= 3 - c.first;
			int pre = c.second - 1, post = c.second + c.first, pre1 = pre, post1 = post;
			while (pre >= 0 && post < board.size() && board[pre] == board[post]) {
				while (pre1 > 0 && board[pre1] == board[pre1 - 1]) pre1--;
				while (post1 < board.size() - 1 && board[post1] == board[post1 + 1]) post1++;
				if (pre - pre1 + post1 - post > 0) {
					pre = --pre1;
					post = ++post1;
				}
				else break;
			}	
			string	s = board.substr(0, pre + 1) +(post < board.size() ? board.substr(post) : "");				
			ans = min(ans, 3 - c.first + dfs(s, shand, deep + 3 - c.first));
			shand[i] += 3 - c.first;
		}
	}
	return ans;
}

int hash(char c) {
	if (c == 'R') return 0;
	if (c == 'Y') return 1;
	if (c == 'B') return 2;
	if (c == 'G') return 3;
	if (c == 'W') return 4;
}

int main() {
	return 0;
}