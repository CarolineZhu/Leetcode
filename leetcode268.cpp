#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int>& nums) {
	int sum = 0;
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
	}
	int diff = sum - nums.size() * (nums.size() - 1) / 2;
	return nums.size() - diff;
}