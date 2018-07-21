#include <iostream>
#include <vector>

using namespace std;

bool isAnagram(string a, string b) {
	if (a.length() != b.length()) return false;
	vector<int>acnt(26, 0);
	vector<int>bcnt(26, 0);
	for (int i = 0; i < a.length(); i++) {
		acnt[a[i] - 'a']++;
		bcnt[b[i] - 'a']++;
	}
	for (int i = 0; i < 26: i++)
		if (acnt[i] != bcnt[i]) return false;
	return true;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector<vector<string> >ret;
	vector<bool> used(strs.size(), false);
	for (int i = 0; i < strs.size(); i++) {
		if (!used[i]) {
			ret.push_back(vector<string>(1, strs[i]));
			for (int j = i + 1; j < strs.size(); j++) {
				if (!used[j] && isAnagram(strs[i], strs[j])) {
					ret[ret.size() - 1].push_back(strs[j]);
					used[j] = true;
				}
			}
			used[i] = true;
		}
	}
	return ret;
}

int main() {
	return 0;
}