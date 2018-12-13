# include <vector>
# include <iostream>
# include <algorithm>
using namespace std;

/*
 *Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 * */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        if (nums.size() == 1) return nums[0];
        
        int maxval = nums[0];
        int minval = nums[0];
        int res = nums[0];
        for (int i=1; i<nums.size(); i++){
            if (nums[i] >= 0){
                maxval = max(maxval*nums[i], nums[i]);
                minval = min(minval*nums[i], nums[i]);
            }
            if (nums[i] < 0){
                int tmp = maxval;
                maxval = max(minval*nums[i], nums[i]);
                minval = min(tmp*nums[i], nums[i]);                
            }
                
            if (maxval > res)
                res = maxval;
        }
        return res;      
    }
};

int main()
{
		int arr[] = {-4, -3, -2};
		int len = sizeof(arr)/sizeof(arr[0]);
		vector<int> nums;
		for (int i=0; i < len; i++)
				nums.push_back(arr[i]);
		Solution ss;
		int ans = ss.maxProduct(nums);
		cout << ans << endl;
}

/* 解题思路： 依旧是减而治之的思想，不过这里不需要保存子问题的值，只需要跟踪前一步的值即可
 * 			考虑到当前 nums[i]可能为负，需要记录最大值 maxval 和最小值 minval。
 * 			但是这里的最大值和最小值是包含当前位置的连续序列的最大值和最小值，而不是全局的最大值和最小值。
 * 			全局的最大值需要用 res 记录。
 *
 * 所以这里的减而治之的子问题并不是我们最终想要的结果，而是为了更好的递推下去。
 * 
 *
 * 考虑从 nums[i-1] 到 nums[i]， 有三种情况：
 * 
 * 1. nums[i] > 0,  maxval = max(maxval*nums[i], nums[i]), minval=min(minval*nums[i], nums[i])
 *		maxval 为什么是这样呢？
 *		因为 maxval 原本为正就是 maxval*nums[i], 原本为负或者0,那就是 nums[i]
 *		minval 为什么是这样呢？
 *		因为 minval 原本为正就是 nums[i], 原本为负或者0, 那就是 minval*nums[i]
 * 
 * 2. nums[i] < 0, 最小值和最大值交换即可
 *
 * 3. nums[i] = 0, 那么就都是 0 了。
 * */
