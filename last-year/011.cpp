/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/

/*
����˼·������ѭ��O(n^2)����ʱ��

���˵ķ������������˵�����line��ʼ��i=0,j=size-1;�����������
��Ȼline����ߵ�ҪС�Ļ�����Ҫ����̭�ˣ����Լ�������i++,ֱ�������ϴ��line
�ұߵ�ͬ��line���ұߵĻ�С���ͱ�Ȼ��̭�ˣ����Լ�������j--��ֱ��line�ϴ�ģ�Ȼ��ѡmaxArea
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