#include <iostream>
#include <vector>

using namespace std;

char findTheDifference(string s, string t) {
	vector<int> scnt(26, 0);
	vector<int> tcnt(26, 0);
	for (int i = 0; i < s.length(); i++) {
		scnt[s[i] - 'a']++;
		tcnt[t[i] - 'a']++;
	}
	tcnt[t[s.length()] - 'a']++;
	for (int i = 0; i < 26; i++) {
		if (tcnt[i] == scnt[i] + 1) {
			return char('a' + i);
		}
	}
	return 'a';
}

int main() {
	cout << findTheDifference("abcd", "abcde");
}