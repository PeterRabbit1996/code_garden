/*
32. 最长有效括号

给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

示例 1:
输入: "(()"
输出: 2

解释: 最长有效括号子串为 "()"
示例 2:
输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"
*/

#include <stdio.h>

int longestValidParentheses(char * s)
{
	if (strlen(s) == 0)
		return 0;

	int s_size = strlen(s);
	int dp[s_size];
	int ans = 0;

	dp[0] = 0;
	for (int i = 1; i < s_size; i++) {
		if (s[i] == '(') {
			dp[i] = 0;
			continue;
		}

		if (s[i - 1] == '(')
			dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
		else if ((i - dp[i - 1]) > 0 && (s[i - dp[i - 1] - 1]) == '(')
			dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
		else
			dp[i] = 0;

		ans = (ans > dp[i] ? ans : dp[i]);
	}

	return ans;
}

int main()
{
	char *str = ")()())";
	longestValidParentheses(str);

	return 0;
}
