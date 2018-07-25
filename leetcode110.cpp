#include <iostream>
#include <vector>

using namespace std;

int height(TreeNode* root) {
	if (root == NULL) return 0;
	int hleft = height(root -> left);
	int hright = height(root -> right);
	if (hleft == -1 || hright == -1) return -1;
	if (abs(hleft - hright) > 1) return -1;
	return max(hleft + 1, hright + 1);
}

bool isBalanced(TreeNode* root) {
	int ans = height(root);
	if (ans == -1) return false;
	else return true;
}