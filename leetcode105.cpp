#include <iostream>
#include <vector>

using namespaces std;

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	if (preorder.size() == 0) return NULL;
    TreeNode* root = new TreeNode(preorder[0]);
    if (preorder.size() == 1) return root;
    int i;
    for (i = 0; i < inorder.size(); i++) {
        if (inorder[i] == preorder[0]) break;
    }
    vector<int> inLeftTree, inRightTree, preLeftTree, preRightTree;
    inLeftTree.assign(inorder.begin(), inorder.begin() + i);
    inRightTree.assign(inorder.begin() + i + 1, inorder.end());
    preLeftTree.assign(preorder.begin() + 1, preorder.begin() + i + 1);
    preRightTree.assign(preorder.begin() + i + 1, preorder.end());
    root -> left = buildTree(preLeftTree, inLeftTree);
    root -> right = buildTree(preRightTree, inRightTree);
    return root;
}