#include<vector>
#include<iostream>
#include<stack>
using namespace std;
//
////Definition for a binary tree node.
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//class mySolution {
//public:
//	vector<int> inorderTraversal(TreeNode* root) {   //中序遍历，先左子树，根结点，再右子树
//		vector <int> res;
//		if (root) {
//			inorderTraversal(root->left);
//			res.push_back(root->val);
//			inorderTraversal(root->right);
//		}
//		return res;
//	}
//};
//class Solution {
//public:
//	void inorder(TreeNode* root, vector<int>& nodes) {
//		if (!root) return;
//		inorder(root->left, nodes);
//		nodes.push_back(root->val);
//		inorder(root->right, nodes);
//	}
//	vector<int> inorderTraversal(TreeNode* root) {
//		vector<int> nodes;
//		inorder(root, nodes);
//		return nodes;
//	}
//};
//
////iterative
//vector<int> inorderTraversal(TreeNode* root) {
//	vector<int> nodes;
//	stack<TreeNode*> toVisit;
//	TreeNode* curNode = root;
//	while (curNode || !toVisit.empty()) {
//		if (curNode) {
//			toVisit.push(curNode);
//			curNode = curNode->left;
//		}
//		else {
//			curNode = toVisit.top();
//			toVisit.pop();
//			nodes.push_back(curNode->val);
//			curNode = curNode->right;
//		}
//	}
//	return nodes;
//}

int main() {
	stack<int> res;
	res.push(1);
	cout << res.empty();
}