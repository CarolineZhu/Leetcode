#include <iostream>
#include <vector>

using namespace std;

vector<int> root;

int find(int x) {
    if (root[x - 1] == x) return x;
    root[x - 1] = find(root[x - 1]);
    return root[x - 1];
}

void combine(int x, int y) {
    root[find(y) - 1] = find(x);
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    for (int i = 0; i < edges.size(); i++)
        root.push_back(i + 1);
    int i;
    for (i = 0; i < edges.size(); i++) {
        if (find(edges[i][0]) == find(edges[i][1])) {
            break;
        }
        else
            combine(edges[i][0], edges[i][1]);
    }
    return edges[i];
}

int main() {
	return 0;
}