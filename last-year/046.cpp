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
解题思路：
全排列是将一组数按一定顺序进行排列，如果这组数有n个，那么全排列数为n!个。现以{1, 2, 3, 4, 5}为例说明如何编写全排列的递归算法。
1、首先看最后两个数4, 5。 它们的全排列为4 5和5 4, 即以4开头的5的全排列和以5开头的4的全排列。由于一个数的全排列就是其本身，从而得到以上结果。
2、再看后三个数3, 4, 5。它们的全排列为3 4 5、3 5 4、 4 3 5、 4 5 3、 5 3 4、 5 4 3 六组数。
即以3开头的和4,5的全排列的组合、以4开头的和3,5的全排列的组合和以5开头的和3,4的全排列的组合。
对于（1，2，3，4，5....n）
那么递归应该是这样的：
1.for循环：对开头第一位，从0开始循环遍历所有的可能
	2.假设是开头是i，把i交换到开头，然后全排列后面n-1个数，
		1）全排列n-1个数，也是开头遍历遍历除i之外的所有数
			2）全排列n-2个数
				。。。
					n)全排列n-1,n-2,n-3...2,1只剩一个数时，就是它本身了
	3.把i放回原来的位置
上面就是递归的过程~~

那么递归的截止条件：
全排列只剩个数之后就结束了~
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
