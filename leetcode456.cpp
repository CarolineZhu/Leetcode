#include <iostream>
#include <vector>

using namespace std;

bool find132pattern(vector<int>& nums) {
	vector<int> minLeft;
	if (nums.size() < 3) return false;
	minLeft.push_back(nums[0]);
	for (int i = 1; i < nums.size(); i++) {
		minLeft.push_back(min(minLeft[i - 1], nums[i - 1]));
	}
	for (int i = nums.size() - 1, top = nums.size(); i >= 0; i--) {
		if (nums[i] <= minLeft[i]) continue;
		while(top < nums.size() && minLeft[top] <= minLeft[i]) top++;
		if (top < nums.size() && nums[i] > minLeft[top]) return true;
		minLeft[--top] = nums[i];
	}
	return false;
}

int main() {
	int arr[] = {3, 1, 4, 2};
	vector<int> n(arr, arr + 4);
	cout << find132pattern(n);
	return 0;
}