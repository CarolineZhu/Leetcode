#include <iostream>
#include <vector>

using namespace std;

int firstUniqChar(string s) {
	vector<vector<int> >table(26);
	for (int i = 0; i < s.length(); i++) {
		table[s[i] - 'a'].push_back(i);
	}
	int minpos = s.length();
	for (int i = 0; i < table.size(); i++) {
		if (table[i].size() == 1 && table[i][0] < minpos) {
			minpos = table[i][0];
		}
	}
	if (minpos != s.length())
		return minpos;
	else return -1;       
}

int main() {
	cout << firstUniqChar("leetltcodecod");
	return 0;
}