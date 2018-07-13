#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> res;
	sort(nums.begin(), nums.end());
	int i, j, k;
	for (i = 0; i < nums.size(); i++) {
		if(i && nums[i] == nums[i - 1]) continue;
		for (j = i + 1, k = nums.size() - 1; j < k; ) {
			if (nums[i] + nums[j] + nums[k] == 0) {
				res.push_back({nums[i], nums[j++], nums[k]});
				while (j < k && nums[j] == nums[j - 1])
					j++;
			} else if (nums[i] + nums[j] + nums[k] < 0) {
				j++;
			} else {
				k--;
			}

		}
	}
	return res;
}

int main() {

	return 0;
}