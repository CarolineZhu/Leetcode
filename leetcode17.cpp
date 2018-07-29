#include <iostream>
#include <vector>

using namespace std;

vector<string> combine(vector<string> a, string b) {
	vector<string>ret;
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.length(); j++) {
			ret.push_back(a[i] + b[j]);
		}
	}
	return ret;
}

vector<string> letterCombinations(string digits) {
	vector<string> numtoLetter;
	vector<string> ret, tmp;
	for (int i = 0; i < digits.size(); i++) {
		string l;
		switch (digits[i]) {
			case '2': l = "abc"; break;
			case '3': l = "def"; break;
			case '4': l = "ghi"; break;
			case '5': l = "jkl"; break;
			case '6': l = "mno"; break;
			case '7': l = "pqrs"; break;
			case '8': l = "tuv"; break;
			case '9': l = "wxyz"; break;
		}
		numtoLetter.push_back(l);
	}
	for (int i = 0 ; i < numtoLetter.size(); i++) {
		if (ret.size() == 0) 
			for (int j = 0; j < numtoLetter[i].length(); j++) {
				tmp.push_back(string(1, numtoLetter[i][j]));
			}
		else {
			tmp = combine(ret, numtoLetter[i]);
		}
		ret.assign(tmp.begin(), tmp.end());
		tmp.clear();
	}
	return ret;
}

int main() {
	vector<string>ans = letterCombinations("237");
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	return 0;
}