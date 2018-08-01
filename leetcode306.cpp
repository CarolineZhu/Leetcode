#include <iostream>
#include <vector>

using namespace std;

string sum(string a, string b) {
	string s, l, ans;
	int unit, inc = 0;
	if (a.length() > b.length()) {
		l = a;
		s = b;
	} else {
		l = b;
		s = a;
	}
	int diff = l.length() - s.length();
	for (int i = l.length() - 1; i >= 0; i--) {
		if (i >= diff)
			unit = s[i - diff] - '0' + l[i] - '0' + inc;
		else
			unit = l[i] - '0' + inc;
		ans += unit % 10 + '0';
		inc = unit / 10;
	}	
	if (inc) {
		ans += '1';
	}
	reverse(ans.begin(), ans.end());
	return ans; 
}

bool check(string num1, string num2, string num3) {
	if ((num1.length() > 1 && num1[0] == '0') || (num2.length() > 1 && num2[0] == '0')) return false;
	string num4 = sum(num1, num2);
	if (num3 == num4) return true;
	if (num4.length() < num3.length() && num4 == num3.substr(0, num4.size()))
		return check(num2, num4, num3.substr(num4.size()));
	else return false;
}

bool isAdditiveNumber(string num) {
	for (int i = 1; i <= num.size() / 2; i++) {
		for (int j = 1; j <= (num.size() - i) / 2; j++) {
			if (check(num.substr(0, i), num.substr(i, j), num.substr(i + j)))
				return true;
		}
	}
	return false;
}

int main() {
	// cout << sum("25", "38");
	cout << isAdditiveNumber("101");
	return 0;
}