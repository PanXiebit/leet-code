#include <iostream>
#include <stdlib.h>
using namespace std;


class Solution {
public:
    int reverse(int x) {
        long long y = 0;   //需要注意的 
		while(x){
			y = 10*y + x%10;
			x/=10;				
		} 
		return (y<INT_MIN || y>INT_MAX) ? 0 : y;    //  
    }
};

int main()
{
	int x = 1534236469;
	Solution aa;
	int y = aa.reverse(x);
	cout << y <<endl;
	return 0;
}
