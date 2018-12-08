/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

Input: [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?
*/



/*Brute Force [Time Limit Exceeded]: recursive*/

int lenofLIS(vector<int> &nums, int prev, int curpos);

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return lenofLIS(nums, INT_MIN, 0);
    }
};

int lenofLIS(vector<int> &nums, int prev, int curpos){
    if (curpos == nums.size())
        return 0;
    int taken = 0;
    if (nums[curpos] > prev)
        taken = 1 + lenofLIS(nums, nums[curpos], curpos+1);
    int notaken = lenofLIS(nums, prev, curpos+1);
    return max(taken, notaken);
}

/* time complexity O(2^n)*/



// dynamic programmer


int lenofLIS(vector<int> &nums, int prev, int curpos);

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int dp[nums.size()];
        dp[0] = 1;
        for (int i=1; i< nums.size(); i++){
            dp[i] = 1;
            for (int j=0; j < i; j++){
                if (nums[i] > nums[j] && dp[i] < dp[j]+1){
                    dp[i] = dp[j] + 1;
                }
            }
        }
        return *max_element(dp, dp+nums.size());
    }
};
/*Time complexity O(n^2)*/








