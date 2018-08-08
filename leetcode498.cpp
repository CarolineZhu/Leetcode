#include <iostream>
#include <vector>

using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
	int dir1[] = {-1, 1}, dir2[] = {1, -1};
    int cnt = 0, cur = 0;
    vector<int> ans;
    if (matrix.size() == 0) return ans;
    if (matrix.size() == 0) return ans;
    ans.push_back(matrix[0][0]);
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0, j = 0; cnt < m * n - 1; cnt++) {
        int ti = i + dir1[cur];
        int tj = j + dir2[cur];
        if (ti >= m){
            cur = 1 - cur;
            ans.push_back(matrix[i][++j]);
        } else if (tj >= n){
            cur = 1 - cur;
            ans.push_back(matrix[++i][j]);
        } else if (ti < 0) {
            cur = 1 - cur;
            ans.push_back(matrix[i][++j]);
        } else if (tj < 0) {
            cur = 1 - cur;
            ans.push_back(matrix[++i][j]);
        } else {
            ans.push_back(matrix[ti][tj]);
            i = ti;
            j = tj;
        }
    }
    return ans;
}