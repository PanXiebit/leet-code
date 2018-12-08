/*
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

1. Insert a character
2. Delete a character
3. Replace a character


Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')


Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

*/

/* 动态规划的主要适用于重叠子问题和最优子结构性质的问题。 
 *
 * 通常许多子问题非常相似，为此动态规划法试图仅仅解决每个子问题一次，从而减少计算量：一旦某个给定子问题的解已经算出，则将其记忆化存储，以便下次需要同一个子问题解之时直接查表。 
 *
 * 那么怎么去寻找子问题呢？ 无非是两点：减而治之、分而治之。
 * 
 * 对于这个问题，有两个字符串，我们先确保其中一个不变，为 target string T[m]. 另一个为 source string S[n]. 不断增大 n 可以看作相似的子问题。
 *
 * 我们可以从递归的角度自顶而上的思考子问题之间的关系。也可以从迭代的角度自底而上去寻找子问题规模扩大的变化情况。也就是递推公式：
 *
 * 我们假设 D[i,j] 为 两个 string 长度为 i 和 j 的最小编辑距离。那么对应 insert\remove\replace 有三种情况：
 *
 * D[i,j] = D[i-1,j] + 1; remove
 * D[i,j] = D[i, j-1] + 1;  insert
 * D[i,j] = D[i-1, j-1] + 1; replece if S[i] != T[j]
 * D[i,j] = D[i-1, j-1]; if S[i] = T[j]
 *
 *
 * 写出了递推公式，就可以自底而上的填表了。其中迭代过程中会遇到重复的子问题，都可以通过差表得到。
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        int ans[n+1][m+1];
        ans[0][0] = 0;

        for (int i=1; i<n+1; i++)
            ans[i][0] = ans[i-1][0]+1;

        for (int j=1; j<m+1; j++)
            ans[0][j] = ans[0][j-1]+1;

        for (int i=1; i<n+1; i++){
            for (int j=1; j<m+1; j++){
                if (word1[i-1] != word2[j-1]){
                    int tmp = min(ans[i-1][j-1] + 1, ans[i-1][j] + 1);
                    ans[i][j] = min(tmp, ans[i][j-1] + 1);
                }
                else
                    ans[i][j] = ans[i-1][j-1];
            }
        }
        return ans[n][m];
    }
};
