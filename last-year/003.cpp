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
����˼·��
��������ָ��p��qָ���ַ�����s�����ƶ�p�� 
	ÿһ���ƶ������У�����temp=q����[q,p)��Χ�����ƶ�temp������ָ��p��ָԪ�ؽ��жԱȣ�һ����ȣ�ѭ��������q�ƶ���temp+1����
	���û�г�����ȣ����qָ��û�в�����
	ͬʱ���������count��������ȵ�ʱ�������������֮ǰ����Ԫ�ؽ��бȽϡ� 
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
