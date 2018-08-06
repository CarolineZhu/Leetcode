#include <iostream>
#include <vector>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
	vector<int> ret;
    int cur, next;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i]) {
            cur = i;
            next = nums[cur] - 1;
            while (nums[next]) {
                cur = next;
                next = nums[next] - 1;
                nums[cur] = 0;
            }
        }
    }
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
        if (nums[i]) ret.push_back(i + 1);
    }
    return ret;
}