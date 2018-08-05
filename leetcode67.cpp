#include <iostream>
#include <vector>

using namespace std;

string addBinary(string a, string b) {
	string l, s, ans;
	int inc = 0, unit;
	if (a.length() > b.length()) {
		l = a;
		s = b;
	} else {
		l = b;
		s = a;
	}
	for (int i = l.length() - 1; i >= 0; i--) {
		if (i >= l.length() - s.length())
			unit = l[i] - '0' + s[i - l.length() + s.length()] - '0' + inc;
		else
			unit = l[i] - '0' + inc;
		inc = unit / 2;
		ans += char('0' + unit % 2);
		cout << inc << endl;
	}
	if (inc)
		ans += '1';
	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {
	cout << addBinary("10", "1");
	return 0;
}