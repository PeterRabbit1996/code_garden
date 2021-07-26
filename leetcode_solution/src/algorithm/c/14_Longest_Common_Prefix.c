/*
14. 最长公共前缀

编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:
输入: ["flower","flow","flight"]
输出: "fl"

示例 2:
输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * longestCommonPrefix(char ** strs, int strsSize)
{
	if (strsSize <= 0)
		return "";
	else if (strsSize == 1)
		return *strs;

	int max_size = 0;
	for (int i = 0; i < strsSize; i++)
		max_size = max_size > strlen(*(strs + i)) ? max_size : strlen(*(strs + i));
	if (max_size <= 0)
		return "";

	char *res = (char *)malloc(sizeof(char) * (max_size + 1));
	memset(res, 0, sizeof(char) * (max_size + 1 ));

	for (int i = 0; *(*strs + i) != '\0'; i++) {
		for (int j = 0; j < strsSize - 1; j++) {
			if (*(*(strs + j) + i) != *(*(strs + j + 1) + i))
				return res;
		}

		*(res + i) = *(*strs + i);
	}

	return res;
}

int main()
{
	char *str[] = {"c","c"};
	//char *str[] = {"flower","flow","flight"};
	//char *str[] = {"dog","racecar","car"};
	printf("the common prefix = %s\n", longestCommonPrefix(str, 3));

	return 0;
}
