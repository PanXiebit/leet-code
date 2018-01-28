#include<vector>
#include<iostream>
#include<stack>
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
	//插入树节点
	void insert(TreeNode *root, int elem) {
		if (!root) {
			TreeNode *root = new TreeNode(elem);
		}
		else {
			if (elem < root->val)
				insert(root->left, elem);
			else insert(root->right, elem);
		}
	}

	vector<TreeNode*> generateTrees(int n) {
		//怎么判断一个序列生成的二叉搜索树是否一致？
		vector<TreeNode*> res;
		TreeNode *root;

	}
};