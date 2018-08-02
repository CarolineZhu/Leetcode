/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    pair<int, int> find(TreeNode* x, int depth) {
        if (x->left == NULL && x->right == NULL) return make_pair(depth, x->val);
        if (x->left != NULL && x->right == NULL) return find(x->left, depth+1);
        if (x->right != NULL && x->left == NULL) return find(x->right, depth+1);
        pair<int, int> rl, rr;
        rl = find(x->left, depth+1);
        rr = find(x->right, depth+1);
        if (rl.first >= rr.first) return rl;
        return rr;
    }
    int findBottomLeftValue(TreeNode* root) {
        pair<int, int> res = find(root, 0);
        return res.second;
    }
};
