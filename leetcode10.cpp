#include <iostream>
#include <vector>

using namespace std;

bool isMatch(string s, string p) {
	vector<vector<bool> > f(s.length() + 1, vector<bool>(p.length() + 1, false));
	f[0][0] = true;
	for (int i = 0; i <= s.length(); i++) {
		for (int j = 1; j <= p.length(); j++) {
			if (p[j] == '*')
				continue;
			if (p[j - 1] == '*') {
				f[i][j] = f[i][j] | f[i][j - 2];
				if (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.'))
					f[i][j] = f[i][j] | f[i - 1][j];
			} else {
				if(i > 0 && (p[j - 1] == s[i - 1] || p[j - 1] == '.'))
					f[i][j] = f[i][j] | f[i - 1][j - 1];
			}
		}
	}
	return f[s.length()][p.length()];	
}

int main() {
	string s = "aa";
	string p = "a";
	cout << isMatch(s, p) << endl;
	return 0;
}