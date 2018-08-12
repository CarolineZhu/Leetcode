#include <iostream>
#include <vector>

using namespace std;

vector<int> root;

int find(int a) {
	if (root[a] == a) return a;
	root[a] = find(root[a]);
	return root[a];
}

int combine(int a, int b) {
	root[a] = b;
}

vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
	for (int i = 0; i < equations.size(); i++) {
		combine(equations[i].first[0] - 'a', equations[i].second[0] - 'a');
	}
}