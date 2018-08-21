#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int numFriendRequests(vector<int>& ages) {
	int cnt = 0;
	sort(ages.begin(), ages.end());
	for (int i = 0, t = 0; i < ages.size(); i++, t = 0) {
		int j = i - 1;
		while (i + 1 < ages.size() && ages[i] == ages[i + 1]) {
			i++;
			t++;
			if (ages[i] > 14)
				cnt += 2 * t;
		}
		for (int k = j; k >= 0; k--) {
			if (ages[k] > 0.5 * ages[i] + 7) {
				cnt += t + 1;
			}
			else break;
		}
	}
	return cnt;
}

int main() {
	int arr[] = {73,39,6,26,15,30,71,35,46,6,60 };
	vector<int>ages(arr, arr + sizeof(arr)/sizeof(int));
	cout << numFriendRequests(ages);
	return 0;
}