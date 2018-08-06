#include <iostream>
#include <vector>

using namespace std;

vector<TreeNode*> printPath(TreeNode* n, TreeNode* p) {
	vector<TreeNode*> path;
	while (n) {
		path.push_back(n);
		if (n -> val == p -> val) break;
		else if (n -> val > p -> val) n = n -> left;
		else n = n -> right;
	}
	return path;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	TreeNode* n = root;
	vector<TreeNode*> ppath = printPath(n, p);
	n = root;
	vector<TreeNode*> qpath = printPath(n, q);
	int i;
	for (i = 0; i < min(ppath.size(), qpath.size()); i++) {
		if (ppath[i] -> val != qpath[i] -> val) break;
	}
	return ppath[i - 1];
}