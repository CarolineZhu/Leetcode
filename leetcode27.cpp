#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
	nums.erase(remove(nums.begin(),nums.end(),val), nums.end());
	return nums.size();
}

int main() {
	return 0;
}