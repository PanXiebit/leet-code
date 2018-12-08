#include<string>
#include<stack>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class mySolution {
public:
	int longestValidParentheses(string s) {
		stack<char> str;
		stack<int> indexs;
		vector<int> nums(10000, -1);
		str.push(0);
		int i = 0;
		while (i < s.length()) {
			if (s[i] == '(') {
				str.push(s[i]);
				indexs.push(i);
			}
			else if (s[i] == ')'&& str.top() == '(')
			{
				nums[i] = i;
				nums[indexs.top()] = indexs.top();
				str.pop(); indexs.pop();
			}
			i++;
		}
		int longest = 0, cur = 0;
		vector<int>::iterator iter = nums.begin();
		while (iter != nums.end()) {
			if (*iter != -1) cur++;
			else cur = 0;
			if (cur > longest) longest = cur;
			iter++;
		}
		return longest;
	}
};

class Solution {
public:
	int longestValidParentheses(string s) {
		int n = s.length(), longest = 0;
		stack<int> st;
		for (int i = 0; i < n; i++) {
			if (s[i] == '(') st.push(i);
			else   // (s[i] == ')')
			{
				if (!st.empty()) {
					if (s[st.top()] == '(') st.pop();
					else st.push(i);
				}
				else st.push(i);
			}
		}
		if (st.empty()) longest = n;
		else {
			int a = n, b = 0;
			while (!st.empty()) {
				b = st.top(); st.pop();
				longest = max(longest, a - b - 1);
				a = b;
			}
			longest = max(longest, a);
		}
		return longest;
	}
};

int main() {
	string s = "()))(()()())((()))((((())))))()";
	Solution ss;
	int ans = ss.longestValidParentheses(s);
	cout << ans << endl;
	mySolution sss;
	int anss = sss.longestValidParentheses(s);
	cout << anss << endl;
	return 0;
}