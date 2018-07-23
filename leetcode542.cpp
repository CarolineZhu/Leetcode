#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
	int row = matrix.size();
	int col = matrix[0].size();
	vector<vector<int> >dist(row, vector<int>(col, 999));
	vector<pair<int, int> >q;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, -1, 0, 1};
	int head = 0, tail;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (matrix[i][j] == 0) {
				q.push_back(make_pair(i, j));
				dist[i][j] = 0;
			}
		}
	}
	tail = q.size();
	for(int i = 0; head != tail; i++) {
		for (int j = 0; j < 4; j++) {
			if (q[i].first + dx[j] < row && q[i].second + dy[j] < col && q[i].first + dx[j] >= 0 && q[i].second + dy[j] >= 0 
				&& matrix[q[i].first + dx[j]][q[i].second + dy[j]] 
				&& dist[q[i].first + dx[j]][q[i].second + dy[j]] > dist[q[i].first][q[i].second] + 1) {
				dist[q[i].first + dx[j]][q[i].second + dy[j]] = dist[q[i].first][q[i].second] + 1;
				q.push_back(make_pair(q[i].first + dx[j], q[i].second + dy[j]));
			}
		}
		if (i == tail - 1) {
            head = tail;
            tail = q.size();
        }
	}
	return dist;
}