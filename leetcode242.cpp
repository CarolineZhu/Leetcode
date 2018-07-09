#include <iostream>
using namespace std;

bool isAnagram(string s, string t) {
	int a[26], b[26];
	memset(a, 0, sizeof(int) * 26);
	memset(b, 0, sizeof(int) * 26);
	if (s.length() != t.length())
		return false;
	for (int i = 0; i < s.length(); i++) {
		a[s[i] - 'a'] ++;
		b[t[i] - 'a'] ++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}

int main() {
	string s = "rat";
	string t = "car";
	printf("%d\n", isAnagram(s, t));
	return 0;
}