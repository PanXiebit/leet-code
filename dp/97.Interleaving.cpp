/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

Example 1:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
*/

/*
先理解题目的意思，给出的第一个 true 的例子可以看作:

s1 划分成 aa bc c,
s2 划分成 dbbc a, 
那么交替下来就是 aa dbbc bc a c. 

可以看到每一次的子串可以是 s1 和 s2 的任意长度，所以 s1 和 s2 交替的话有很多很多种情况，但是给定 s3 之后，只有一条路径可以走到头，但是对于 s3 的部分子串却是有多种情况，也就是动态规划中的重复的子问题


解题思路：

字符串 s3 的长度必须等于 s1+s2 的长度。

采用减而治之的思路：

当 s1 长度只有 i ，s2 长度为 j 时，s3[i+j] 是否也是 s1 与 s2 的交替字符串。

于是，我们可以构建这样一个表格，map[s1.length()+1][s2.length()+1]. 

自下而上迭代的填表过程实际上就是找出递推公式：

map[i][j] 为 true 的情况有两种：

1. 左边为 true, 也就是 map[i][j-1] = true, 并且 s2[j-1] = s3[i+j-1]
2. 上面为 true, 也就是 map[i-1][j] = true，并且 s1[i-1] = s3[i+j-1]

迭代基，也就是边界情况需要特殊对待。

*/


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int R = s1.length();
        int C = s2.length();

        if (s3.length() != R + C) return false;
        bool map[R+1][C+1];

        map[0][0] = true;

        // j=0
        for (int i=1; i<R+1; i++)
        {
            if (s1[i-1] == s3[i-1] && map[i-1][0])
                map[i][0] = true;
        }

        // i=0
        for (int j=1; j<C+1; j++)
        {
            if (s2[j-1] == s3[j-1] && map[0][j-1])
                map[0][j] = true;
        }

        for (int i=1; i<R+1; i++)
            for (int j=1; j<C+1; j++)
            {
                map[i][j] = (map[i-1][j] && s1[i-1] == s3[i+j-1]) || (map[i][j-1] && s2[j-1] == s3[i+j-1]);
            }

        return map[R][C];
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s1 = stringToString(line);
        getline(cin, line);
        string s2 = stringToString(line);
        getline(cin, line);
        string s3 = stringToString(line);

        bool ret = Solution().isInterleave(s1, s2, s3);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
