#include <iostream>
#include <vector>

using namespace std;

string removeDuplicateLetters(string s) {
	int tot[26], cnt[26];
	bool exs[26];
	vector<int> stk;
	string ret = "";
	memset(tot, 0, sizeof(tot));
	memset(cnt, 0, sizeof(cnt));
	memset(exs, false, sizeof(exs));
	for (int i = 0; i < s.length(); i++)
		tot[s[i] - 'a']++;
	for (int i = 0; i < s.length(); i++) {
		cnt[s[i] - 'a']++;
		if (!exs[s[i] - 'a']) {
			while((stk.size() > 0) && (s[i] - 'a' < stk[stk.size() - 1]) && (cnt[stk[stk.size() - 1]] != tot[stk[stk.size() - 1]])) {
				exs[stk[stk.size() - 1]] = false;
				stk.pop_back();
			}
		
			stk.push_back(s[i] - 'a');
			exs[s[i] - 'a'] = true;
		}
	}
	for (int i = 0; i < stk.size(); i++) {
		ret = ret + (char)(stk[i] + 'a');
	}
	return ret;
}

int main() {
	string s = "acacb";
	cout << removeDuplicateLetters(s) << endl;
	return 0;
}