/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

/*
解体思路：定义一个numrows维字符串str[numRows] 
当row=1时，step=1，row+=step;
当row=numRows-1时，step=-1,row+=step;
这里有点需要注意的是， str[]里面填充元素时，并不是一定要按照Z字形那样，隔着一个空的。。。
因为最后输出的时候按照行输出的，所以push_back()函数就可以了。。这里想了很久，怎么才能隔着空传入str[]，其实没必要。。 
*/




#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <=1)
        	return s;
     	
        const int len = (int)s.length();
        string *str = new string[numRows];
        
        int row = 0, step = 1;
        for(int i = 0; i<len; i++)
        {
        	str[row].push_back(s[i]);
        	if(row==0)
				step = 1;
			else if (row == numRows -1)
				step = -1;
			row += step; 
		}
		s.clear();
		for (int j = 0; j< numRows; j++)
		{
			s.append(str[j]);
		}
		delete [] str;
		return s;		
    }
};

//int main(){
//	string s("PAYPALISHIRING");
//	string ss = Solution().convert(s,3);
//}
