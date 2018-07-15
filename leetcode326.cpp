#include <iostream>

using namespace std;

bool isPowerOfThree(int n) {
	if (n <= 0) return false;
	int ans = 1;
	int cnt = 0;
	while (ans <= n && cnt < 20) {
		if (ans == n) return true;
		ans *= 3;
		cnt++;
	}
	return false;
}
int main() {
	cout << isPowerOfThree(9);
	return 0;
}