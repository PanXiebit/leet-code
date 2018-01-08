#include<stdio.h>
//
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

int main(){
	char* s = {"a"};
	int maxlen;
	maxlen = lengthOfLongestSubstring(s);
	printf("%d\n",maxlen);
	return 0;
}


//int main(){
//	char *s = "abcabcabc";
//	char *p = s;
//	printf("%d\n",&s[3]-&s[0]);
//}
