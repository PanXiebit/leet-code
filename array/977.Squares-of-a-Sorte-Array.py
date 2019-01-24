"""
Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.

 

Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Note:

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A is sorted in non-decreasing order.
"""


class Solution(object):
    def sortedSquares(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        length = len(A)
        neg = []
        pos = []
        i = 0
        while (i < length):
            if A[i] < 0:
                neg.append(A[i]**2)
            else:
                pos.append(A[i]**2)
            i += 1

        j, k = len(neg)-1, 0
        res = []
        while(j >=0 and k < len(pos)):
            if neg[j] <= pos[k]:
                res.append(neg[j])
                j -= 1
            else:
                res.append(pos[k])
                k += 1
        if j < 0:
            res += pos[k:]
        else:
            while(j >= 0):
                res.append(neg[j])
                j -= 1
        return res
