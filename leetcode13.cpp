#include <iostream>
#include <vector>

using namespace std;

int romanToInt(string s) {
	if (s.length() == 0) return 0;
	vector<int> mk(s.length());
	int ans = 0;
	for (int i = 1; i < s.length(); i++) {
		if ((s[i - 1] == 'I' && (s[i] == 'V' || s[i] == 'X'))
			|| (s[i - 1] == 'X' && (s[i] == 'L' || s[i] == 'C'))
			|| (s[i - 1] == 'C' && (s[i] == 'D' || s[i] == 'M'))) {
			mk[i - 1] = -1;
		} else
			mk[i - 1] = 1;
	}
	mk[s.length() - 1] = 1;
	for (int i = 0; i < s.length(); i++) {
		switch(s[i]) {
			case 'I': ans += mk[i]; break;
			case 'V': ans += mk[i] * 5; break;
			case 'X': ans += mk[i] * 10; break;
			case 'L': ans += mk[i] * 50; break;
			case 'C': ans += mk[i] * 100; break;
			case 'D': ans += mk[i] * 500; break;
			case 'M': ans += mk[i] * 1000; break;
		}
	}
	return ans;
}

int main() {
	cout << romanToInt("III");
	return 0;
}
