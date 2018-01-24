#include<string>
#include<vector>
#include<stack>
#include<cmath>
#include <iostream>
using namespace std;

class Solution {
public:
	int calculate(string s) {
		if (s.size() == 0) return 0;
		stack<double> nums;
		char op = '+';
		double cur = 0;		
		for (int i = 0; i <= s.size(); i++) {
			//处理空格' ' 
			if (i < s.size() && s[i] == ' ') {
				cur = 0;
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
				cur = calculate(s.substr(start, i - start));
			}
			//处理符号
			else {
				if (i < s.size())
					op = s[i];
				if (op == '+')
					nums.push(cur);
				else if (op == '-')
					nums.push(-cur);
				else if (op == '*') {
					double temp = nums.top(); nums.pop();
					nums.push(temp * cur);
				}
				else if (op == '/') {
					double temp = nums.top(); nums.pop();
					nums.push(floor(temp / cur));
				}
				cur = 0;
			}
		}
		int res = 0;
		int aaa = 0;
		while (!nums.empty()) {
			res += nums.top();
			nums.pop();
			aaa++;
		}
		cout << "aaa: " << aaa << endl;
		return res;
	}
};

int main() {
	Solution ss;
	string s = "1+1+5*(1+2)";
	cout << "s.size = " << s.size() << endl;
	int ans = ss.calculate(s);
	cout << ans << endl; 
	return 0;
}
