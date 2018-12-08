#include<vector>
#include<iostream>
#include<stack>
using namespace std;

/*解题思路：递归
迭代1~n分别为根结点。
当1为根结点时，左右子树为0，n-1
当2为根结点时，左右子树为1，n-2
当3为根结点时，左右子树为2，n-3
....
以(1~5)为例，i=3为根结点时，左子树集合left = genTree(1, 2)，右子树集合right = genTree(4, 5)
然后left=genTree(1, 2),在分别以1，2为根结点
根结点i=1时，left = genTree(1,0) right = genTree(2,2) 意思就是左子树的根结点为1时，只有右子树2
根结点i=2时，left = genTree(1,1) right = genTree(3,2) 意思就是左子树的根结点为2时，只有左子树1

同理。。。右子树情况~~

总结下来就是：1~n里面取一个根结点i，左边左子树，右边右子树
然后左子树分别从1~i为根结点，依次迭代下去~~
递归的截止情况是genTree(start,end),start=end res.push_back(new TreeNode(start));
*/

//Definition for a binary tree node.
struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<TreeNode*> genTree(int start, int end) {
		vector<TreeNode*> res;
		if (start > end) res.push_back(0);
		if (start == end) res.push_back(new TreeNode(start));
		if (start < end) {
			for (int i = start; i <= end; ++i) {
				vector<TreeNode*> left = genTree(start, i-1);   // 左子树的集合
				vector<TreeNode*> right(genTree(i + 1, end));   // 右子树的集合
				//到这里其实就递归完成了二叉搜索树的建立！~~~

				//下面的部分不过是把树节点放到vector中
				for (int j = 0; j < left.size(); j++) {
					for (int k = 0; k < right.size(); k++) {
						TreeNode *temp = new TreeNode(i);
						temp->left = left[j];
						temp->right = right[k];
						res.push_back(temp);
					}
				}

			}
		}
		return res;
		
	}

	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> res;
		if (n == 0) return res;
		return genTree(1, n);
	}
};