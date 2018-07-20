#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	if (matrix.size() == 0) return false;
	for (int i = 0, j = matrix[0].size() - 1; i < matrix.size() && j >= 0; ) {
		if (matrix[i][j] == target) return true;
		else if (matrix[i][j] > target) j--;
		else i++;
	}
	return false;
}

int main() {
	return 0;
}