#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	int sum, pos;
	sum = 0;
	for (int i = 0; i < gas.size(); ) {
		pos = i;
		while (sum >= 0 && i < gas.size()) {
			sum += gas[i] - cost[i];
			i++;
		}
		if (sum < 0) {
			sum = 0; 
			pos = -1;
		}
	} 
	if (pos == -1) return pos;
	for (int i = 0; i < pos; i++) {
		sum += gas[i] - cost[i];
		if (sum < 0) {
			pos = -1;
			break;
		}
	}
	return pos;
}

int main() {
	return 0;
}