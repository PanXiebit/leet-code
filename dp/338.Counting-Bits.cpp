/*
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2]
Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
*/

/*
 * Solution 1
 */

class Solution {
public:
    int oneNumsOfBits(int num){
        int count = 0;
        while(num != 0)
        {
            count += num%2;
            num /= 2;
        }
        return count;
    }

    vector<int> countBits(int num) {
        vector<int> res(1,0);
        for (int i=1; i<num+1; i++)
        {
            res.push_back(oneNumsOfBits(i));
        }
        return res;
    }
};

/*
 * Solution 2
 *
 * 整数 i 的二进制表示中 1 的个数与 i/2 中的个数在加上 i%2 是一样的。
 * 比如 
 * 9 = 8 + 1. 8 的二进制中 1 的个数与 4 一样
 * 10 = 5 * 2 = (4 + 1) * 2. 
 *
 * 想想问什么？因为 10 相当于把 5 的二进制左移一位，多了个 0， 所以他们中的 1 的个数是一样的。
 */

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> cnt = vector<int>(num + 1, 0);
        for(int i = 1; i <= num; i++)
            cnt[i] = cnt[i >> 1] + (i & 1);
        return cnt;
    }
};


