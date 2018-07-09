#include <iostream>
#include <set>

using namespace std;

int lengthOfLongestSubstring(string s) {
	set<char> rec;
	int mlen, l;
	int i, j;
	for (i = 0, j = 0, mlen = 0, l = 0; j < s.length(); ) {
		if (rec.find(s[j]) == rec.end()) {
			rec.insert(s[j]);
			j++;
			l = j - i;
		}
		else {
			rec.erase(s[i]);
			i++;
		}
		if (l > mlen)
			mlen = l;
	}

	return mlen;
}

int main() {
	string s = "pwwkew";
	printf("%d\n", lengthOfLongestSubstring(s));
	return 0;
}