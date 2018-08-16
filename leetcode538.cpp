#include <iostream>
#include <vector>
#include <set>

using namespace std;

int sum = 0;

void add(TreeNode* root) {
	if (root == NULL) return;
	add(root -> right);
	int tmp = root -> val;
	root -> val += sum;
	sum += tmp;
	add(root -> left);
}

TreeNode* convertBST(TreeNode* root) {
	add(root);
	return root;
}