#include <iostream>
#include <vector>

using namespace std;

string multiply(string num1, string num2) {
	string s1, s2;
	int inc, mul, unit, plus;
	string ansu, ptmp, ret;
	vector<string> ans;
	if (num1.length() > num2.length()) {
		s1 = num1;
		s2 = num2;
	} else {
		s1 = num2;
		s2 = num1;
	}
	ret = "";
	for (int i = s2.length() - 1; i >= 0; i--) {
		if (num1 == "0" || num2 == "0")
            return "0";
		inc = 0;
		ansu = "";
		for (int j = s1.length() - 1; j >= 0; j--) {
			mul = (s2[i] - '0') * (s1[j] - '0') + inc;
			inc = mul / 10;
			unit = mul % 10;
			ansu = char(unit + '0') + ansu;
		}
		if (inc > 0)
			ansu = char(inc + '0') + ansu;
		// ans.push_back(ansu);

		string zero(s2.length() - 1 - i, '0');
		ansu = ansu + zero;
		cout << ansu << endl;

		inc = 0;
		ptmp = "";
		for (int j = ansu.length() - 1; j >= 0; j--) {
			if (j >= ansu.length() - ret.length()) {
				plus = (ansu[j] - '0') + (ret[j - ansu.length() + ret.length()] - '0') + inc;
			} else {
				plus = ansu[j] - '0' + inc;
			}
			inc = plus / 10;
			unit = plus % 10;
			ptmp = char(unit + '0') + ptmp;
		}
		ret = ptmp;
		if (inc > 0)
			ret = char(inc + '0') + ret;
	}
	return ret;
}

int main() {
	cout << multiply("100", "10");
	return 0;
}