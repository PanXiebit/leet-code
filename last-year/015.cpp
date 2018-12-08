#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size() < 3) return res;
		int i, j, k;
		sort(nums.begin(), nums.end());
		for (i = 0; i < nums.size() - 2; ++i) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			k = nums.size() - 1;
			j = i + 1;
			while(j<k){
				if (nums[i] + nums[j] + nums[k] > 0) k--;
				else if (nums[i] + nums[j] + nums[k] < 0) j++;
				else {
					int ivec[3] = { nums[i], nums[j], nums[k] };
					vector<int> temp(ivec, ivec + 3);
					res.push_back(temp);
					while (nums[k] == nums[k - 1]) k--;
					while (nums[j] == nums[j + 1]) j++;
					k--, j++;
				}
			}
		}
		return res;
	}
};
