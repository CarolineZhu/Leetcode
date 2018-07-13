#include <iostream>
#include <vector>
#include <map>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
	vector<int> s(nums.size());
	vector<int> pos;
	int i, cnt = 0;
	for (i = 0; i < nums.size(); i++) {
		if(i == 0) s[i] = nums[i];
		else s[i] = s[i - 1] + nums[i];
	}
	for (i = 0; i < s.size(); i++) {
		if (s[i] == k) cnt++;
		pos.push_back(s[i] + k);
		cout << s[i] + k << " " << i << endl;
	}
	// cout << pos.size() << endl;
	for (i = 0; i < s.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (pos[j] == s[i]) {
				cnt++;
				cout << i << endl;
			}
		}
	}
	return cnt;
}

int main() {
	int arr[] = {-1,-1,1};
	vector<int> nums(arr, arr + 3);
	cout << subarraySum(nums, 1);
	return 0;
}