#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n) {
	int a, b, ret;
	for (int i = 0; i <= n; i++) {
		if (i == 0) {
			a = 1;
			ret = 1;
		}
		else if (i == 1) {
			b = 1;
			ret = 1;
		}
		else {
			ret = a + b;
			a = b;
			b = ret;
		}
	}
	return ret;
}

int main() {
	cout << climbStairs(4);
	return 0;
}