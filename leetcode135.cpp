#include <iostream>
#include <vector>

using namespace std;

int candy(vector<int>& ratings) {
	vector<int> hleft(ratings.size(), 0);
	vector<int> hright(ratings.size(), 0);
	int ret = 0;
	for (int i = 1; i < ratings.size(); i++) {
		if (ratings[i] > ratings[i - 1]) hleft[i] = hleft[i - 1] + 1;
	}
	for (int i = ratings.size() - 2; i >= 0; i--) {
		if (ratings[i] > ratings[i + 1]) hright[i] = hright[i + 1] + 1;
	}
	for (int i = 0; i < ratings.size(); i++) {
		ret += max(hleft[i], hright[i]) + 1;
	}
	return ret;
}

int main() {
	int arr[] = {1,0,2};
	vector<int>r(arr, arr + 3);
	cout << candy(r);
}