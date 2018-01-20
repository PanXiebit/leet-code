#include<iostream>


class Solution {
public:
	bool isPalindrome(int x) {
		int m = 0;
		int temp = x;
		if (x>INT_MAX || x<INT_MIN)
			return 0;
		else
			while (temp) {
				m = 10 * m + temp % 10;
				temp /= 10;
			}
		return (x>0 && m == x);
	}
};

int main() {
	int x = -123;
	Solution aa;
	bool ans = aa.isPalindrome(x);
	std::cout << ans;
	return 0;
}
