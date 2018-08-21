#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
	vector<int> q;
	vector<int> c(graph.size(), 0);
	int cur = 1;
	q.push_back(0);
	for (int h = 0, t = 1; h < t; h++) {
		c[h] = cur;
		for(int j = 0; j < graph[h].size(); j++) {
			if (c[graph[h][j]] == 0)
				q.push_back(graph[h][j]);
		}
		if (h == t - 1) {
			h = t;
			t = q.size();
			cur = -cur;
		}
	}
	for (int i = 0; i < graph.size(); i++) {
		for (int j = 1; j < graph[i].size(); j++) {
			if (c[graph[i][j]] != c[graph[i][j - 1]]) return false;
		}
		if (c[graph[i][0]] != c[i]) return false;
	}
	return true;
}