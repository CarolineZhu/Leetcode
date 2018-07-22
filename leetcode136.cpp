#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
	int ret = 0;
	for (int i = 0; i < nums.size(); i++)        
    	ret ^= nums[i];
    return ret;
}

int main() {
	int arr[] = {2,2,1};
	vector<int> n(arr, arr + sizeof(arr)/sizeof(int));
	cout << singleNumber(n);
	return 0;
}