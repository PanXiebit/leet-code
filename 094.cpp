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

///不明白为啥不行？？？？
class mySolution1 {
public:
	vector<int> inorderTraversal(TreeNode* root) {   //中序遍历，先左子树，根结点，再右子树
		vector <int> res;
		if (root) {
			inorderTraversal(root->left);
			res.push_back(root->val);
			inorderTraversal(root->right);
		}
		return res;
	}
};


class Solution1 {
public:
	void inorder(TreeNode* root, vector<int>& nodes) {
		if (!root) return;
		inorder(root->left, nodes);
		nodes.push_back(root->val);
		inorder(root->right, nodes);
	}
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> nodes;
		inorder(root, nodes);
		return nodes;
	}
};


class mySolution2 {
public:
	vector<int> inorderTraversal(TreeNode* root) {   //中序遍历: 先左子树，根结点，再右子树
		vector <int> res;
		stack <TreeNode*> stack_node;
		TreeNode *cur = root;
		while (cur || !stack_node.empty()) {
			if (cur) {
				stack_node.push(cur);
				cur = cur->left;
			}
			else {
				TreeNode *tmp = stack_node.top();
				res.push_back(tmp->val);
				stack_node.pop();
				cur = tmp->right;
			}
		}
		return res;
	}
};