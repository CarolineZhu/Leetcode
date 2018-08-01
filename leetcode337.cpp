#include <iostream>
#include <vector>

using namespace std;

vector<int> select(TreeNode* root) {
	if (root == NULL) return vector<int>(2, 0);
	vector<int> ret(2);
	vector<int> vleft = select(root -> left);
	vector<int> vright = select(root -> right);
	ret[0] = vleft[1] + vright[1] + root -> val;
	ret[1] = max(max(vleft[0] + vright[0], vleft[0] + vright[1]), max(vleft[1] + vright[0], vleft[1] + vright[1]));
	return ret;
}

int rob(TreeNode* root) {
	vector<int> r = select(root);
	return max(r[0], r[1]);
}

int main() {

}