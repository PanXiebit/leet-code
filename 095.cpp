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
	//�������ڵ�
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
		//��ô�ж�һ���������ɵĶ����������Ƿ�һ�£�
		vector<TreeNode*> res;
		TreeNode *root;

	}
};