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
����˼·��
1. ��stringת��ΪC�е�char�ַ����� c_str()��Ȼ����ָ����ʵ��
2.��Ҫ���ǵ����������
	1--ָ��ΪNULL
	2--���ַ�����
	3--�����븺�ŵĴ���
	4--�������   INT_MAX  INT_MIN
	5--��������쳣�ַ���ô����
3. int long long�ķ�Χ
unsigned   int   0��4294967295
int   2147483648��2147483647
unsigned long 0��4294967295
long   2147483648��2147483647
long long�����ֵ��9223372036854775807
long long����Сֵ��-9223372036854775808
unsigned long long�����ֵ��1844674407370955161

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

	long long ans = 0;    //������������ýϴ�Χ��Ȼ����INT_MAX INT_MIN�Ƚ�

	if (*pStr == '\0')   //���ַ�
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

