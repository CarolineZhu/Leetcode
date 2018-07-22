#include <iostream>
#include <vector>

using namespace std;

vector<int> singleNumber(vector<int>& nums) {
	int resall = 0;
	vector<int> ret;
	for (int i = 0; i < nums.size(); i++)
		resall ^= nums[i];
	int pos;
	for (pos = 0; resall; pos++) {
		if (resall % 2) break;
		resall >>= 1;
	}
	int m = 0, n = 0;
	for (int i = 0; i < nums.size(); i++) {
		if ((nums[i] >> pos) % 2)
			m ^= nums[i];
		else
			n ^= nums[i];
	}
	ret.push_back(m);
	ret.push_back(n);
	return ret;
}


int main() {
	int arr[] = {1,2,1,3,2,5};
	vector<int> n(arr, arr + sizeof(arr)/sizeof(int));
	vector<int> ans = singleNumber(n);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	return 0;
}