#include <iostream>
#include <vector>

using namespace std;

int winner(vector<int>& nums, int head, int tail) {
	if (head == tail) return nums[head];
	int situ1 = nums[head] - winner(nums, head + 1, tail);
	int situ2 = nums[tail] - winner(nums, head, tail - 1);
	return max(situ1, situ2);
}

bool PredictTheWinner(vector<int>& nums) {
	return winner(nums, 0, nums.size() - 1) >= 0;
}

int main() {
	int arr[] = {3606449,6,5,9,452429,7,9580316,9857582,8514433,9,6,6614512,753594,5474165,4,2697293,8,7,1};
	vector<int>n(arr, arr + sizeof(arr)/sizeof(int));
	cout << PredictTheWinner(n);
	return 0;
}