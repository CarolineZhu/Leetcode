#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void nextPermutation(vector<int>& nums) {
	bool desc = true;
	int i,j;
	for (i = nums.size() - 1; i > 0; i --) {
		if (nums[i] > nums[i - 1])
		{
			desc = false;
			break;
		}
	}
	if (desc) {
		reverse(nums.begin(), nums.end());
		return;
	}

	for (j = nums.size() - 1; j >= i; j--) {
		if (nums[j] > nums[i - 1]) {
			int tmp = nums[j];
			nums[j] = nums[i - 1];
			nums[i - 1] = tmp;
			break;
		}
	}
	sort(nums.begin() + i, nums.end());
	return;          
}

int main() {
	int arr[3] = {1,3,2};
	vector<int> v(arr, arr + 3);
	nextPermutation(v);
	return 0;
}