#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> levelOrder(TreeNode* root) {
	vector<TreeNode* > q;
	vector<vector<int> >ret;
	int head = 0, tail = 1;

	if (root) q.push_back(root);
    else return ret;

	while (head != tail) {
		vector<int> level;
		for (int i = head; i < tail; i++) {
			level.push_back(q[i] -> val);
			if (q[i] -> left) q.push_back(q[i] -> left);
			if (q[i] -> right) q.push_back(q[i] -> right);
		}
		ret.push_back(level);
		head = tail;
		tail = q.size();
	}
	return ret;
}

int main() {
	return 0;
}