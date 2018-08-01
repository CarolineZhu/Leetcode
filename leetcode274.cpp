#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool decSort(int a, int b) {
	return a > b;
}

int hIndex(vector<int>& citations) {
	sort(citations.begin(), citations.end(), decSort);
	int i;
	for (i = 0; i < citations.size(); i++) {
		if (citations[i] < i + 1) break;
	}
	return i;
}

int main() {
	int arr[] = {3,0,6,1,5};
	vector<int> c(arr, arr + 5);
	cout << hIndex(c);
	return 0;
}