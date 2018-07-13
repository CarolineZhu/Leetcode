#include <iostream>
#include <vector>
#include <map>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
	vector<int> s(nums.size());
	map<int, int> pos;
	int i, cnt = 0;
	for (i = 0; i < nums.size(); i++) {
		if(i == 0) s[i] = nums[i];
		else s[i] = s[i - 1] + nums[i];
	}
	for (i = 0; i < s.size(); i++) {
		if (s[i] == k) cnt++;
		pos.insert(make_pair(s[i] + k, i));
		// cout << s[i] + k << " " << i << endl;
	}
	// cout << endl;
	for (i = 0; i < s.size(); i++) {
		if (pos.find(s[i]) != pos.end())
			cnt++;
	}
	// cout << i << " " << pos[s[i]] << endl;
	return cnt;
}

int main() {
	int arr[] = {1,1,1};
	vector<int> nums(arr, arr + 3);
	cout << subarraySum(nums, 2);
	return 0;
}