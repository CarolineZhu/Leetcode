#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(int s, vector<int>& nums) {
	vector<int> sum;
	if (nums.size() == 0) return -1;
	sum.push_back(nums[0]);
	for (int i = 1; i < nums.size(); i++) {
		sum.push_back(nums[i] + sum[i - 1]);
	}
	int res, l, minLen = 9999;
	for (int i = -1, j = 0; j < sum.size();) {
		if (i == -1) {
			res = sum[j];
		}
		else res = sum[j] - sum[i];
		if (res >= s) {
			l = j - i;
			if (l < minLen) minLen = l;
			i++;
		}
		else j++;
	}
	if (minLen == 9999) minLen = -1;
	return minLen;
}
 int main() {
 	int arr[] = {2,3,1,2,4,3};
 	vector<int> n(arr, arr + 6);
 	cout << minSubArrayLen(7, n);
 	return 0;
 }