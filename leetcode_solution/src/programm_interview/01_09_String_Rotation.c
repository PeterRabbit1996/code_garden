/*
面试题 01.09. 字符串轮转

字符串轮转。给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成（比如，waterbottle是erbottlewat旋转后的字符串）。

示例1:
 输入：s1 = "waterbottle", s2 = "erbottlewat"
 输出：True

示例2:
 输入：s1 = "aa", "aba"
 输出：False

提示：
字符串长度在[0, 100000]范围内。

说明:
你能只调用一次检查子串的方法吗？
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isFlipedString(char* s1, char* s2)
{
	if (strlen(s1) != strlen(s2)
		|| s1 == NULL
		|| s2 == NULL)
		return false;

	bool res = false;
	int size = strlen(s1) * 2 + 1;
	char *str = (char *)malloc(sizeof(char) * size);
	if (str == NULL)
		return false;

	memset(str, '\0', size);
	memcpy(str, s1, strlen(s1));
	memcpy(str + strlen(s1), s1, strlen(s1));

	if (strstr(str, s2) != NULL)
		res = true;
	free(str);

	return res;
}

int main()
{
	/*
	char s1[] = "waterbottle";
	char s2[] = "erbottlewat";
	*/
	char s1[] = "eCQOKatuwIPRHFftkBmhQfakidjbtRVwblGdpLTtSLbjFzBwIjobHMsPvyucjIEs";
	char s2[] = "kBmhQfakidjbtRVwblGdpLTtSLbjFzBwIjobHMsPvyucjIEseCQOKatuwIPRHFft";
	printf("is fliped string = %d\n", isFlipedString(s1, s2));
}
