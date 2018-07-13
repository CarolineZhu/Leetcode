#include <iostream>
#include <vector>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

int valmax = -9999;
pair<int, int> maxPathSumRec(TreeNode* root) {
    pair<int, int> lpair, rpair;
    int mleft, mright;
    int nodeval;
    
    if (root -> left == NULL && root -> right == NULL) {
        mleft = 0;
        mright = 0;
    } else if (root -> left == NULL) {
        rpair = maxPathSumRec(root -> right);
        mleft = 0;
        mright = root -> right -> val + max(max(rpair.first, rpair.second), 0);
    } else if (root -> right == NULL) {
        lpair = maxPathSumRec(root -> left);
        mleft = root -> left -> val + max(max(lpair.first, lpair.second), 0);
        mright = 0;
    } else {
        lpair = maxPathSumRec(root -> left);
        rpair = maxPathSumRec(root -> right);
        mleft = root -> left -> val + max(max(lpair.first, lpair.second), 0);
        mright = root -> right -> val + max(max(rpair.first, rpair.second), 0);
        // cout << mleft << " " << mright << endl;
    }
    nodeval = root -> val;
    if (mleft >= 0)
        nodeval += mleft;
    if(mright >= 0)
        nodeval += mright;
    // root -> val = mleft + mright + root -> val;
    if (nodeval > valmax) valmax = nodeval;
    // cout << nodeval<< endl;
    return make_pair(mleft, mright);
}
int maxPathSum(TreeNode* root) {
    pair<int, int> m = maxPathSumRec(root);
    return valmax;
}

int main() {
	return 0;
}