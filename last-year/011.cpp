/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/

/*
解题思路：两个循环O(n^2)，超时了

别人的方法：从最两端的两条line开始，i=0,j=size-1;这是最宽的情况
显然line比左边的要小的话，就要被淘汰了，所以继续右移i++,直到遇到较大的line
右边的同理，line比右边的还小，就必然淘汰了，所以继续左移j--，直到line较大的，然后选maxArea
*/

#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
	int maxArea(std::vector<int>& height) {
		int i, j;
		int maxArea = 0;
		for (i = 0; i < height.size() - 1; i++) {
			for (j = 1; j < height.size(); j++) {
				int temp = (j - i)*std::min(height[i], height[j]);
				if (temp > maxArea)
					maxArea = temp;
			}
		}
		return maxArea;
	}
};


class Solution {
public:
	int maxArea(std::vector<int>& height) {
		int water = 0;
		int i = 0, j = height.size() - 1;
		while (i < j) {
			int h = std::min(height[i], height[j]);
			water = std::max(water, (j - i) * h);
			while (height[i] <= h && i < j)
				i++;
			while (height[j] <= h && i < j)
				j--;
		}
		return water;
	}
};