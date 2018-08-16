#include <iostream>
#include <vector>

using namespace std;

int countBinarySubstrings(string s) {
	int cnt = 0;
	for (int i = 0; i < s.length() - 1; i++) {
		int j = i, k = i + 1;
		if (s[j] != s[k]) {
			cnt++;
			while (j > 0 && k < s.length() - 1 && s[j] == s[--j] && s[k] == s[++k])
				cnt++;
		}
	}
	return cnt;
}

int main() {
	cout << countBinarySubstrings("10101");
}