#include <iostream>
#include <vector>

using namespace std;

int calculateMinimumHP(vector<vector<int>>& dungeon) {
	int M = dungeon.size();
	int N = dungeon[0].size();
	int cost;

	vector<vector<int> >minHP(M, vector<int>(N));

	for (int i = M - 1; i >= 0; i--) {
		for (int j = N - 1; j >= 0; j--) {
			if (i == M - 1 && j == N - 1) {
				cost = 1 - dungeon[i][j];
			} else if (i == M - 1) {
				cost = minHP[i][j + 1] - dungeon[i][j];
			} else if (j == N - 1) {
				cost = minHP[i + 1][j] - dungeon[i][j];
			} else {
				cost = min(minHP[i + 1][j], minHP[i][j + 1]) - dungeon[i][j];
			}
			if (cost <= 0)
				minHP[i][j] = 1;
			else
				minHP[i][j] = cost;
		}
	}
	return minHP[0][0];
}