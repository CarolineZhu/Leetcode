#include <iostream>
#include <vector>

using namespace std;

int countSubstrings(string s) {
	int i = 0, j = 0, cnt = 0;
	while (j < s.length()) {
		while (j + 1 < s.length() && s[j] == s[j + 1]) {
			j++;
		}
		int t = j + 1, l = j - i + 1;
		cnt += (l + 1) * l / 2;
		while (i - 1 >= 0 && j + 1 < s.length() && s[i - 1] == s[j + 1]) {
			cnt++;
			i--;
			j++;
		}
		i = t;
		j = t;
	}
	return cnt;
}

int main() {
	cout << countSubstrings("abc");
	return 0;
}