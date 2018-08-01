#include <iostream>
#include <vector>

using namespace std;

string sum(string a, string b) {

}

bool check(string num1, string num2, string num3) {
	if ((num1.length() == 1 && num1[0] = '0') || (num2.length() == 1 && num2[0] == '0')) return false;
	string num4 = sum(num1, num2);
	if (num3 == num4) return true;
	if (num4.length() < num3.length() && num4 == num3.substr(0, num4.size()))
		return check(num2, num4, num3.substr(num4.size()));
	else return false;
}

bool isAdditiveNumber(string num) {
	for (int i = 1; i < num.size(); i++) {
		for (int j = 1; j < num.size(); j++) {
			if (check(num.substr(0, i), substr(i, j), substr(i + j)))
				return true;
		}
	}
	return false;
}

int main() {
	return 0;
}