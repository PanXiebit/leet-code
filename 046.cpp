/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
[1,2,3],
[1,3,2],
[2,1,3],
[2,3,1],
[3,1,2],
[3,2,1]
]
*/
/*
����˼·��
ȫ�����ǽ�һ������һ��˳��������У������������n������ôȫ������Ϊn!��������{1, 2, 3, 4, 5}Ϊ��˵����α�дȫ���еĵݹ��㷨��
1�����ȿ����������4, 5�� ���ǵ�ȫ����Ϊ4 5��5 4, ����4��ͷ��5��ȫ���к���5��ͷ��4��ȫ���С�����һ������ȫ���о����䱾���Ӷ��õ����Ͻ����
2���ٿ���������3, 4, 5�����ǵ�ȫ����Ϊ3 4 5��3 5 4�� 4 3 5�� 4 5 3�� 5 3 4�� 5 4 3 ��������
����3��ͷ�ĺ�4,5��ȫ���е���ϡ���4��ͷ�ĺ�3,5��ȫ���е���Ϻ���5��ͷ�ĺ�3,4��ȫ���е���ϡ�
���ڣ�1��2��3��4��5....n��
��ô�ݹ�Ӧ���������ģ�
1.forѭ�����Կ�ͷ��һλ����0��ʼѭ���������еĿ���
	2.�����ǿ�ͷ��i����i��������ͷ��Ȼ��ȫ���к���n-1������
		1��ȫ����n-1������Ҳ�ǿ�ͷ����������i֮���������
			2��ȫ����n-2����
				������
					n)ȫ����n-1,n-2,n-3...2,1ֻʣһ����ʱ��������������
	3.��i�Ż�ԭ����λ��
������ǵݹ�Ĺ���~~

��ô�ݹ�Ľ�ֹ������
ȫ����ֻʣ����֮��ͽ�����~
*/


#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<vector<int> > permute(vector<int> &nums) {
		vector<vector<int> > result;
		permuteRecursive(nums, 0, result);
		return result;
	}
	void permuteRecursive(vector<int>& nums, int begin, vector<vector<int>> &res) {
		if (begin == nums.size()) {
			res.push_back(nums);
			return;
		}
		for (int i = begin; i < nums.size(); i++) {
			swap(nums[begin], nums[i]);
			permuteRecursive(nums, begin + 1, res);
			swap(nums[begin], nums[i]);
		}
	}
};
