#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
	int sum = 0;
	int curmod, premod = 0;
	set<int> modk;
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
		if (k)
			curmod = sum % k;
		else
			curmod = sum;
		if (modk.find(curmod) != modk.end()) return true;
		else {
			modk.insert(premod);
			premod = curmod;
		}
	}
	return false;
}

int main() {
	int arr[] = {23, 2, 6, 0, 4};
	vector<int>n(arr, arr + 5);
	cout << checkSubarraySum(n, 11);
	return 0;
}