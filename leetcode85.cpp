#include <iostream>
#include <vector>

using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
	if (matrix.size() == 0) return 0;
    int ans = 0, lb, rb;
    vector<int> leftBound(matrix[0].size(), 0),rightBound(matrix[0].size(), matrix[0].size()), height(matrix[0].size(), 0);
    for (int i = 0; i < matrix.size(); i++) {
        lb = 0;
        rb = matrix[0].size();
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == '1')
                height[j]++;
            else
                height[j] = 0;
        }
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == '1') {
                leftBound[j] = max(leftBound[j], lb);
            } else {
                leftBound[j] = 0;
                lb = j + 1;
            }
        }
        for (int j = matrix[0].size() - 1; j >= 0; j--) {
            if (matrix[i][j] == '1') {
                rightBound[j] = min(rightBound[j], rb);
            } else {
                rightBound[j] = matrix[0].size();
                rb = j;
            }
        }
        for (int j = 0; j < matrix[0].size(); j++) {
            if ((rightBound[j] - leftBound[j]) * height[j] > ans)
                ans = (rightBound[j] - leftBound[j]) * height[j];
        }
    }
    return ans;
}