#include <iostream>

using namespace std;

string gs;
bool flg = false;

bool check(int h, int t) {
	if (h == t) return true;
	if (h == t - 1 && gs[h] == gs[t]) return true;
	if (gs[h] != gs[t]) {
		if (!flg) {
			flg = true;
			return check(h + 1, t) || check(h, t - 1);
		} else return false;
	} else return check(h + 1, t - 1);
}


bool validPalindrome(string s) {
	gs = s;
	return check(0, s.length() - 1);
}

int main() {
	cout << validPalindrome("abcda");
	return 0;
}