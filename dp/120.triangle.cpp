/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

*/

/* 解题思路：
 * 自顶向下递归，自下而上迭代。 建立一个 map[][] 二元数组，写出i递推公式。
 * 也就是 map[i][j] 与 map[i-1][j]、map[i-1][j-1] 之间的关系
 *
 * 需要注意的是 j 的范围为 [0, i-1]. 而实际上 j 的范围是 [-1, i] 有两个超出的边界。
 *
 * 只需要将两个边界设定为 INT_MAX 即可
 *
 *
 *
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int R = triangle.size();
        int C = triangle[R-1].size();

        int map[R][C];

        map[0][0] = triangle[0][0];

        for (int i=1; i<R; i++)
            for (int j=0; j<=i; j++){
                int low = ((j-1) >= 0) ? map[i-1][j-1] : INT_MAX;
                int high = (j <= (i-1))? map[i-1][j] : INT_MAX;
                map[i][j] = min(low, high) + triangle[i][j];
            }

        int tmp = INT_MAX;

        for (int i=0; i<C; i++){
            if (map[R-1][i] < tmp)
                tmp = map[R-1][i];
        }

        return tmp;
    }
};
