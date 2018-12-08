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
解题思路：
1.用两个队列nums、ops分别保存数字和符号 ，本来想的用堆栈，后来发现6*3/2逆序输出和正序输出不太一样，才考虑用queue。。其实用double就可以？ 
2.对于括号以及多重括号用递归来解决~~
3.用一个堆栈或者数组ans都可以的~来保存最终需要累加的结果 
4.第一个数字直接push(nums.front())到数组ans
5.然后循环退出ops，遇到'+'或'-'，pop nums，并且push nums 
6. 遇到'*'或'/'，则pop nums,并且修改nums.top 
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
		for (int i = 0; i <= s.size(); i++) {     //这里i <= s.size()是要把最后一个数字也push进去，因为数字必须要等到下一个符号才会push
			//处理空格' ' 
			if (i < s.size() && s[i] == ' ') {
				continue;
			}


			// 处理数字,注意多位数
			else if (i < s.size() && isdigit(s[i])) {
				cur = cur * 10 + s[i] - '0';
			}

			//处理括号
			else if (i < s.size() && s[i] == '(') {
				int start = i + 1, count = 0;
				while (i < s.size()) {   //处理多重括号的情况，用递归解决括号里面的计算
					if (s[i] == '(')  ++count;
					else if (s[i] == ')') --count;
					if (count == 0) break;
					++i;
				}
				cur = calculate(s.substr(start, i - start));  //从start开始，i-start个元素
			}
			//处理符号
			else {
				nums.push(cur); cout << "push nums: " << cur << endl;
				cur = 0;
				if (i < s.size()) {     //最后一个'\0'不管，不用push到符号stack里面
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
