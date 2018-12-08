/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, 
please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs).
You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument,
please click the reload button  to reset your code definition.
*/

/*
解体思路：
1. 将string转换为C中的char字符数组 c_str()，然后用指针来实现
2.需要考虑的特殊情况：
	1--指针为NULL
	2--空字符处理
	3--正号与负号的处理
	4--溢出处理   INT_MAX  INT_MIN
	5--如果遇到异常字符怎么处理
3. int long long的范围
unsigned   int   0～4294967295
int   2147483648～2147483647
unsigned long 0～4294967295
long   2147483648～2147483647
long long的最大值：9223372036854775807
long long的最小值：-9223372036854775808
unsigned long long的最大值：1844674407370955161

*/

#include <iostream>       // std::cout
#include <string>         // std::string
#include <locale>         // std::locale, std::isspace
#include <vector>
#include <cassert> 
using namespace std;

int myAtoi(string str)
{
	const char* pStr = str.c_str();
	if (pStr == NULL)
		return 0;
	int flag = 1;

	long long ans = 0;    //溢出处理，先设置较大范围，然后与INT_MAX INT_MIN比较

	if (*pStr == '\0')   //空字符
		return (int)ans;

	if (*pStr == '-')
		flag = -1;

	if (*pStr == '+' || *pStr == '-')
		pStr++;

	while (isspace(*pStr))
		pStr++;

	while (*pStr != '\0') {
		if ((*pStr >= '0') && (*pStr <= '9')) {
			ans = ans * 10 + flag * (*pStr - '0');
			if (ans > INT_MAX || ans < INT_MIN) {
				ans = 0;
				break;
			}
		}
		else
			break;
		pStr++;
	}
	return ans;
}

int main() {
	string arr = "+004500";
	int ans = 0;
	ans = myAtoi(arr);
	cout << ans;
	return 0;
}

