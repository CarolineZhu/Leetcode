#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
	map<int, vector<int> > cal;
	for (int i = 0; i < nums.size(); i++) {
		if (cal.find(nums[i]) == cal.end()) {
			cal.insert(pair<int, vector<int> >(nums[i], vector<int>(1,i)));
		} else {
			cal[nums[i]].push_back(i);
		}
	}
	for (map<int, vector<int> >::iterator it = cal.begin(); it != cal.end(); it++) {
		for (int j = 1; j < (*it).second.size(); j++) {
			if ((*it).second[j] - (*it).second[j - 1] <= k) 
				return true;
		}
	}
	return false;
}

int main() {
	int arr[] = {1,2,3,1};
	vector<int> a(arr, arr + 4);
	cout << containsNearbyDuplicate(a, 3);
	return 0;
}