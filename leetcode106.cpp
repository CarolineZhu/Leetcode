#include <iostream>
#include <vector>

using namespaces std;

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	if (inorder.size() == 0) return NULL;
	TreeNode* root = new TreeNode(postorder[postorder.size() - 1]);
	if (inorder.size() == 1) return root;
	int i;
	for (i = 0; i < inorder.size(); i++) {
        if (inorder[i] == postorder[postorder.size() - 1]) break;
    }
    vector<int> inLeftTree, inRightTree, postLeftTree, postRightTree;
    inLeftTree.assign(inorder.begin(), inorder.begin() + i);
    inRightTree.assign(inorder.begin() + i + 1, inorder.end());
    postLeftTree.assign(postorder.begin(), postorder.begin() + i);
    postRightTree.assign(postorder.begin() + i, postorder.end() - 1);
    root -> left = buildTree(inLeftTree, postLeftTree);
    root -> right = buildTree(inRightTree, postRightTree);
    return root;
}