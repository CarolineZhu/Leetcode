#include <iostream>
#include <vector>

using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
	int dir1[] = {1, -1}, dir2[] = {-1, 1};
	int cnt = 0, cur = 0;
	vector<int> ans;
	if (matrix.size() == 0) return ans;
	ans.push_back(matrix[0][0]);
	for (int i = 0, j = 0; cnt < matrix.size() * matrix[0].size(); ) {
		int ti = i + dir1[cur];
		int tj = j + dir2[cur];
		if (ti < 0 || ti >= matrix.size()){
			j++;
			cur = 1 - cur;
		} else if (){

		}
			{
			ans.push_back(matrix[ti][tj]);
			i = ti;
			j = tj;
		} else {

		}
	}
}