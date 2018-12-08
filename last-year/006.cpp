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
����˼·������һ��numrowsά�ַ���str[numRows] 
��row=1ʱ��step=1��row+=step;
��row=numRows-1ʱ��step=-1,row+=step;
�����е���Ҫע����ǣ� str[]�������Ԫ��ʱ��������һ��Ҫ����Z��������������һ���յġ�����
��Ϊ��������ʱ����������ģ�����push_back()�����Ϳ����ˡ����������˺ܾã���ô���ܸ��ſմ���str[]����ʵû��Ҫ���� 
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
