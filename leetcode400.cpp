#include <iostream>
#include <cmath>

using namespace std;

int findNthDigit(int n) {
	int i;
	for(i = 0; n > 9 * (i + 1) * pow(10, i); i++) {
		n -= 9 * (i + 1) * pow(10, i);
	}
	int num = (n - 1) / (i + 1) + pow(10, i);
	string s = to_string(num);
	int ret = s[(n - 1) % (i + 1)] - '0';
	return ret;
}

int main() {
	cout << findNthDigit(3);
	return 0;
}