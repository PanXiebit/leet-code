#include<stdio.h>
/*
Given a string, find the length of the longest substring without repeating characters.
Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, 
"pwke" is a subsequence and not a substring.
*/

/*
解体思路：
定义两个指针p、q指向字符数组s，逐步移动p： 
	每一步移动过程中，定义temp=q，在[q,p)范围内逐步移动temp，并与指针p所指元素进行对比，一旦相等，循环结束，q移动到temp+1处，
	如果没有出现相等，则对q指针没有操作。
	同时定义计数器count，出现相等的时候记下树，并与之前最大的元素进行比较。 
*/
int lengthOfLongestSubstring(char* s) {
    char *p = s;
    char *q = s;
    int cnt = 0;
    int maxlen = 0;
    if (s[0]=='\0'){
    	return 0;
	}
	if(s[1]=='\0'){
		return 1;
	}
	else{
		while(*(++p)!='\0'){
    	char *temp = q;
        while(temp!=p){
        	if(*temp==*p){
        		q = temp+1;
        		break;
			}
			temp++;
		}
		cnt = p-q+1;
        if(cnt>maxlen){
            maxlen = cnt;            
        }
    }
    return maxlen;
	}  
}
