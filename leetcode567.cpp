#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
		int s[26];
		memset(s, 0, sizeof(s));
		for (int i = 0; i < s1.size(); i++)
			s[s1[i]-'a']++;
		for (int i = 0; i < s1.size() && i < s2.size(); i++)
			s[s2[i]-'a']--;
		int cnt = 0;
		for (int i = 0; i < 26; i++)
			cnt += s[i] > 0;
		if (cnt == 0) return true;
		for (int i = s1.size(); i < s2.size(); i++) {
			s[s2[i]-'a']--;
			if (s[s2[i]-'a'] == 0) cnt--;
			s[s2[i-s1.size()]-'a']++;
			if (s[s2[i-s1.size()]-'a'] == 1) cnt++;
			if (cnt == 0) return true;
		}
		return false;
    }
};

int main() {
	Solution a;
	cout << a.checkInclusion("ab", "eidbaooo") << endl;
	cout << a.checkInclusion("ab", "eidboaoo") << endl;
}
