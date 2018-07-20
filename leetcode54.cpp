#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	// int cnt = 0;
	vector<int> ret;
	if (matrix.size() == 0) return ret;
	int top = 0, left = 0, bottom = matrix.size() - 1, right = matrix[0].size() - 1;
	int i, j;
	for (i = top, j = left; left <= right && top <= bottom;) {
		if (i == top && j < right) {
			ret.push_back(matrix[i][j++]);
		} else if (j == right && i < bottom) {
			ret.push_back(matrix[i++][j]);
		} else if (i != top && i == bottom && j > left) {
			ret.push_back(matrix[i][j--]);
		} else if (j != right && j == left && i > top) {
			ret.push_back(matrix[i--][j]);
		}
		if (i == top && j == left) {
			// cnt++;
			top++; left++; bottom--; right--;
			i = top; j = left;			
		}
	}
	ret.push_back(matrix[i][j]);
	return ret;
}