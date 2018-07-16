#include <iostream>
#include <vector>

using namespace std;

vector<int> findAnagrams(string s, string p) {
	int plen = p.length();
	int cntp[26], cntt[26];
	vector<int> ret;
	memset(cntp, 0, sizeof(cntp));
	memset(cntt, 0, sizeof(cntt));
	if (s.length() < p.length()) return ret;
	for (int i = 0; i < p.length(); i++) {
		cntp[p[i] - 'a']++;
		cntt[s[i] - 'a']++;
	}
	for (int i = 0; i <= s.length() - p.length(); i++) {
		int j;
		if (i > 0) {
			cntt[s[i + p.length() - 1] - 'a']++;
			cntt[s[i - 1] - 'a']--;
		}
		for (j = 0; j < 26; j++) {
			cout << cntt[j] << " ";
			if (cntt[j] != cntp[j]) break;
		}
		cout << endl;
		if (j == 26) {
			ret.push_back(i);
		}
	}
	return ret;       
}

int main() {
	string s = "";
	string p = "a";
	vector<int> ans = findAnagrams(s, p);
	for (int i = 0; i < ans.size(); i++) 
		cout << ans[i] << endl;
	return 0;
}