/*
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

The expression string contains only non-negative integers, +, -, *, / operators , open ( and closing parentheses ) and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-2147483648, 2147483647].

Some examples:

"1 + 1" = 2
" 6-4 / 2 " = 4
"2*(5+5*2)/3+(6/2+8)" = 21
"(2+6* 3+5- (3*14/7+2)*5)+3"=-12
 

Note: Do not use the eval built-in library function.
*/ 
/* 
����˼·��
1.����������nums��ops�ֱ𱣴����ֺͷ��� ����������ö�ջ����������6*3/2������������������̫һ�����ſ�����queue������ʵ��double�Ϳ��ԣ� 
2.���������Լ����������õݹ������~~
3.��һ����ջ��������ans�����Ե�~������������Ҫ�ۼӵĽ�� 
4.��һ������ֱ��push(nums.front())������ans
5.Ȼ��ѭ���˳�ops������'+'��'-'��pop nums������push nums 
6. ����'*'��'/'����pop nums,�����޸�nums.top 
*/ 
#include<string>
#include<vector>
#include <stack>
#include<cmath>
#include<queue>
#include <iostream>
using namespace std;

class Solution {
public:
	int calculate(string s) {
		if (s.size() == 0) return 0;
		queue<double> nums;
		queue<char> ops;
		char op = '+';
		double cur = 0;
		for (int i = 0; i <= s.size(); i++) {     //����i <= s.size()��Ҫ�����һ������Ҳpush��ȥ����Ϊ���ֱ���Ҫ�ȵ���һ�����ŲŻ�push
			//����ո�' ' 
			if (i < s.size() && s[i] == ' ') {
				continue;
			}


			// ��������,ע���λ��
			else if (i < s.size() && isdigit(s[i])) {
				cur = cur * 10 + s[i] - '0';
			}

			//��������
			else if (i < s.size() && s[i] == '(') {
				int start = i + 1, count = 0;
				while (i < s.size()) {   //����������ŵ�������õݹ�����������ļ���
					if (s[i] == '(')  ++count;
					else if (s[i] == ')') --count;
					if (count == 0) break;
					++i;
				}
				cur = calculate(s.substr(start, i - start));  //��start��ʼ��i-start��Ԫ��
			}
			//�������
			else {
				nums.push(cur); cout << "push nums: " << cur << endl;
				cur = 0;
				if (i < s.size()) {     //���һ��'\0'���ܣ�����push������stack����
					op = s[i];
					ops.push(op); cout << "push ops :" << op << endl;
				}												
			}
		}
		cout << endl;
		stack<double> ans;
		ans.push(nums.front()); nums.pop(); cout << ans.top() << endl;
		for (int i = 0; !ops.empty(); i++) {
			cout << ops.size() << ' ' << i << endl;
			char c = ops.front(); ops.pop();
			if (c == '+') {
				ans.push(nums.front());  cout << ans.top() << endl;
				nums.pop();
			}
			else if (c == '-') {
				ans.push(-nums.front()); cout << ans.top() << endl;
				nums.pop();
			}
			else if (c == '*') {
				ans.top() *= nums.front(); cout << ans.top() << endl;
				nums.pop();
			}
			else if (c = '/') {
				ans.top() = floor(ans.top()/nums.front()); cout << ans.top() << endl;
				nums.pop();
			}
		}
		cout << endl;
		double aaa = 0;
		while (!ans.empty()) {
			aaa += ans.top(); cout << ans.top() << endl;
			ans.pop();
		}
		return aaa;
	}
};

int main() {
	Solution ss;
	string s = "1+21*(2+3)";   //106
	cout << "s.size = " << s.size() << endl;
	int aaa = ss.calculate(s);
	cout << aaa << endl;
	return 0;
}
