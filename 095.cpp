#include<vector>
#include<iostream>
#include<stack>
using namespace std;

/*����˼·���ݹ�
����1~n�ֱ�Ϊ����㡣
��1Ϊ�����ʱ����������Ϊ0��n-1
��2Ϊ�����ʱ����������Ϊ1��n-2
��3Ϊ�����ʱ����������Ϊ2��n-3
....
��(1~5)Ϊ����i=3Ϊ�����ʱ������������left = genTree(1, 2)������������right = genTree(4, 5)
Ȼ��left=genTree(1, 2),�ڷֱ���1��2Ϊ�����
�����i=1ʱ��left = genTree(1,0) right = genTree(2,2) ��˼�����������ĸ����Ϊ1ʱ��ֻ��������2
�����i=2ʱ��left = genTree(1,1) right = genTree(3,2) ��˼�����������ĸ����Ϊ2ʱ��ֻ��������1

ͬ���������������~~

�ܽ��������ǣ�1~n����ȡһ�������i��������������ұ�������
Ȼ���������ֱ��1~iΪ����㣬���ε�����ȥ~~
�ݹ�Ľ�ֹ�����genTree(start,end),start=end res.push_back(new TreeNode(start));
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
				vector<TreeNode*> left = genTree(start, i-1);   // �������ļ���
				vector<TreeNode*> right(genTree(i + 1, end));   // �������ļ���
				//��������ʵ�͵ݹ�����˶����������Ľ�����~~~

				//����Ĳ��ֲ����ǰ����ڵ�ŵ�vector��
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