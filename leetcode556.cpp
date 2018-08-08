#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int nextGreaterElement(int n) {
	vector<int> input;
	int i, j, mpos, m = 10;
	long long ret = 0;
	while(n > 0) {
		input.push_back(n % 10);
		n /= 10;
	}
	reverse(input.begin(), input.end());
	for (i = input.size() - 1; i > 0; i--) {
		if (input[i - 1] < input[i]) break;
	}
	if (i == 0) return -1;
	for (j = input.size() - 1; j >= i; j--) {
		if (input[j] > input[i - 1] && input[j] < m) {
			mpos = j;
			m = input[j];
		}
	}
	int tmp = input[i - 1];
	input[i - 1] = input[mpos];
	input[mpos] = tmp;
	sort(input.begin() + i, input.end());
	for (int k = 0; k < input.size(); k++) {
		ret *= 10;
		ret += input[k];
	}
	if (ret > INT_MAX) return -1;
	return int(ret);
}

int main() {
	cout << nextGreaterElement(199);
	return 0;
}