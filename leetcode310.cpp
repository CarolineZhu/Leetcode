#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool> >g;
vector<int> dist;

void dfs(int i, int d, int n, int parent) {
	dist[i] = d;
	for (int j = 0; j < n; j++) {
		if (g[i][j] && j != parent) {
			dfs(j, d + 1, n, i);
		}
	}
}

vector<int> dfs_path(int p1, int p2, int n, int parent) {
	vector<int> path;
	if (p1 == p2) {
		path.push_back(p1);
		return path;
	}
	for (int i = 0; i < n; i++) {
		if (g[p1][i] && i != parent) {
			path = dfs_path(i, p2, n, p1);
			if (path.size() == 0) continue;
			path.push_back(p1);
			return path;
		}
	}
	return path;
}


vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
	vector<vector<bool> >inp(n, vector<bool>(n, false));
	vector<int> idist(n, 0);
	int distmax = 0, posmax1 = 0, posmax2 = 0;

	g.assign(inp.begin(), inp.end());
	for (int i = 0; i < edges.size(); i++) {
		g[edges.first][edges.second] = true;
		g[edges.second][edges.first] = true;
	}
	dist.assign(idist.begin(), idist.end());

	dfs(0, 0, n, -1);

	for (int i = 0; i < dist.size(); i++) {
		if (dist[i] > distmax) {
			distmax = dist[i];
			posmax1 = i;
		}
	}
	dist.assign(idist.begin(), idist.end());
	dfs(posmax1, 0, n, -1);

	for (int i = 0, distmax = 0; i < dist.size(); i++) {
		if (dist[i] > distmax) {
			distmax = dist[i];
			posmax2 = i;
		}
	}
	vector<int> ret;
	vector<int> p = dfs_path(posmax1, posmax2, n, -1);
	if(p.size() % 2) 
		ret.push_back(p[p.size()/2]);
	else {
		ret.push_back(p[p.size()/2 - 1]);
		ret.push_back(p[p.size()/2]);
	}
	return ret;
}