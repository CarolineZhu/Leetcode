#include <iostream>
#include <vector>

using namespace std;

bool repeatedSubstringPattern(string s) {
	int n = s.length();
	for (int i = 1; i <= n / 2; i++) {
		if (n % i == 0) {
			bool flg = false;
			for (int j = 0; j < n / i; j++) {
				for (int k = 0; k < i; k++) {
					if (s[j * i + k] != s[k]) {
						flg = true;
						break;
					}
				}
				if (flg) break;
			}
			if (!flg) return true;
		}
	}
	return false;
}

int main() {
	cout << repeatedSubstringPattern("abab");
	return 0;
}