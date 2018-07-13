#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	map<int, int> fit;
	int i;
	for (i = 0; i < nums.size(); i++)
		fit[target - nums[i]] = i;
	for (i = 0; i < nums.size(); i++) {
		if (fit.find(nums[i]) != fit.end() && fit[nums[i]] != i)
			break;
	}
	int arr[2] = {i, fit[nums[i]]};
	vector<int> ret(arr, arr + 2);
	return ret;
}

int main() {
	int nums[] = {3,2,4};
	int target = 6;
	vector<int> vnums(nums, nums + 3);
	vector<int> ans = twoSum(vnums, target);
	cout << ans[0] << " " << ans[1] << endl;
	return 0;
}