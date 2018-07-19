#include <iostream>
#include <vector>

using namespace std;

int stringtoInt(string s) {
	int ret = 0;
	for (int i = 0; i < s.length(); i++) {
		ret *= 10;
		ret += s[i] - '0';
	}
	return ret;
}

vector<string> restoreIpAddresses(string s) {
	vector<string> ans;
	int l = s.length();
	if (l < 4) return ans;
	for (int i = 0; i <= 2; i++) {
		if (stringtoInt(s.substr(0, i + 1)) > 255) continue;
		if (i > 0 && s[0] == '0') continue;
		for (int j = i + 1; j <= i + 3; j++) {
			if (stringtoInt(s.substr(i + 1, j - i)) > 255) continue;
			if (j - i > 1 && s[i + 1] == '0') continue;
			if (j > l - 1) break;
			for (int k = j + 1; k <= j + 3; k++) {
				int t = l - 1;
				if (k >= t || k < t - 3) continue;
				if (stringtoInt(s.substr(j + 1, k - j)) > 255) continue;
				if (stringtoInt(s.substr(k + 1, t - k)) > 255) continue;
				if (k - j > 1 && s[j + 1] == '0') continue;
				if (t - k > 1 && s[k + 1] == '0') continue;
				ans.push_back(s.substr(0, i + 1) + "." + s.substr(i + 1, j - i) + "." + s.substr(j + 1, k - j) + "." + s.substr(k + 1, t - k));
			}
		}
	}
	return ans;
}

int main() {
	string s = "";
	vector<string> ans = restoreIpAddresses(s);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	return 0;
}