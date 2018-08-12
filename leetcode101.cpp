#include <iostream>
#include <vector>

using namespace std;

bool check(TreeNode* l, TreeNode* r) {
	if (l == NULL && r == NULL) return true;
	if ((l == NULL && r != NULL) || (r == NULL && l != NULL)) return false;
	if (l -> val == r -> val) {
		return check(l -> left, r -> right) && check(l -> right, r -> left); 
	} else return false;
}


bool isSymmetric(TreeNode* root) {
	return(check(root, root));
}