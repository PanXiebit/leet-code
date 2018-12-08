#include<stdio.h>
#include<string.h>
/*
Given a string s, find the longest palindromic substring in s. 
You may assume that the maximum length of s is 1000.
Example:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example:
Input: "cbbd"
Output: "bb"
*/

/*
解题思路：对每一个元素，遍历检查其作为中心是否满足奇数回文和偶数回文。
这样的话，时间复杂度，最差情况应该是n个字符全部相等的情况 O(N^2)
*/
char* longestPalindrome(char* s) {
    char *p=s;
	int i=0,j;
	int longest=0;
	int beg,end;
	static char ans[1001];   //字符数组 
	while(p[i]!='\0'){
		/*奇数回文*/
		for(j=0;(i-j)>=0&&(i+j<strlen(p));j++){
			if(p[i-j]!=p[i+j])
				break;
			if(2*j+1>longest){
				longest = 2*j+1;
				beg = i-j;
				end = i+j;
			}
		}		
		/*偶数回文*/
		for(j=0;(i+1-j)>=0&&(i+j)<strlen(p);j++){
			if(p[i+1-j]!=p[i+j]){
				break;
			}
			if(2*j>longest){
				longest =2*j;
				beg = i+1-j;
				end = i+j;
			}
		}
		i++;
	}
	int k,n;
	for(n=0,k=beg;k<=end;k++,n++){
		ans[n]= p[k];
	}
	ans[n] = '\0';
	return ans;
}

int main(){
	char s[] ={"cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc"};
	char *ans = longestPalindrome(s);
	puts(ans);
	return 0;
}
