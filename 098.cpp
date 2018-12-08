#include<iostream>
#include <limits.h>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return help(root, LONG_MIN, LONG_MAX);
	}

	bool help(TreeNode* root, long min, long max) {
		if (!root)   return true;
		if (root->val <= min || root->val >= max)  return false;
		return help(root->left, min, root->val) && help(root->right, root->val, max);
	}
};

int main() {
	TreeNode *p = new TreeNode(10);
	TreeNode *p1 = new TreeNode(5);
	TreeNode *p2 = new TreeNode(15);
	p->left = p1;
	p->right = p2;
	TreeNode *p3 = new TreeNode(6);
	TreeNode *p4 = new TreeNode(20);
	p2->left = p3;
	p2->right = p4;
	Solution ss;
	bool res = ss.isValidBST(p);
	cout << res << endl;
}