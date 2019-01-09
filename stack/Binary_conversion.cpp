#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;

void convert(stack<char>& S, int n, int base){//十进制到base进制的转换，递归版
		//static char digit[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B","C","D","E","F"};
		const char digit[] = 	"0123456789BCDEF";
		if (0 < n){
				S.push(digit[n % base]);
				convert (S, n/base, base);
		}
}

void convert2(stack<char> &S, int n, int base){ // 迭代版
		const char digit[] = 	"0123456789BCDEF";
		while (n >0)
		{
				int remainder = int (n % base);
				S.push(digit[remainder]);
				n /= base;
		}
}



int main(){
	stack<char> S;
	convert2(S, 10, 2);
	char a = S.top();
	while (!S.empty()){
			char a = S.top();
			cout << a <<endl;
			S.pop();
	}
	return 0;
}


