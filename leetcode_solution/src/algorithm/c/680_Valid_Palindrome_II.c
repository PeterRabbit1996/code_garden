/*
680. 验证回文字符串 Ⅱ

给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

示例 1:

输入: "aba"
输出: True
示例 2:

输入: "abca"
输出: True
解释: 你可以删除c字符。

注意:
字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char *s, int left, int right)
{
	bool ret = true;
	int l = left;
	int r = right;
	while (l < r) {
		if(*(s + l) != *(s + r)) {
			ret = false;
			break;
		}
		l += 1;
		r -= 1;
	}

	return ret;
}

bool validPalindrome(char * s)
{
	if (s == NULL)
		return true;

	bool ret = true;
	int l = 0;
	int r = strlen(s) - 1;
	while (l < r) {
		if (*(s + l) == *(s + r)) {
			l += 1;
			r -= 1;
			continue;
		}
		ret = isValid(s, l + 1, r) || isValid(s, l, r - 1);
		break;
	}

	return ret;
}

int main()
{
	char *s = "abca";
	printf("result = %d\n", validPalindrome(s));

	return 0;
}
