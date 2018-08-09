#include <iostream>
#include <vector>

using namespace std;

string s;

void build(TreeNode* t) {
	if (t == NULL) return;
    s += to_string(t -> val);
    if (t -> left || t -> right) {
        s += "(";
        tree2str(t -> left);
        s += ")"; 
        if (t -> right) {
            s += "(";
            tree2str(t -> right);
            s += ")";  
        }
    }
}

string tree2str(TreeNode* t) {
	build(t);
	return s;
}