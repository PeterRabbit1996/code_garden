/*
面试题 01.02. 判定是否互为字符重排

给定两个字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。

示例 1：

输入: s1 = "abc", s2 = "bca"
输出: true 
示例 2：

输入: s1 = "abc", s2 = "bad"
输出: false

说明：
0 <= len(s1) <= 100
0 <= len(s2) <= 100
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void str_swap(char *str, int pos_1, int pos_2)
{
	if (pos_1 == pos_2)
		return;
	*(str + pos_1) ^= *(str + pos_2);
	*(str + pos_2) ^= *(str + pos_1);
	*(str + pos_1) ^= *(str + pos_2);
}

void str_quick_sort(char *str, int left, int right)
{
	if (left >= right)
		return;

	int l = left;
	int r = right;
	int base_num = *(str + l);
	while (l < r) {
		while (l < r && *(str + r) >= base_num)
			r -= 1;
		while (l < r && *(str + l) <= base_num)
			l += 1;
		str_swap(str, l, r);
	}
	str_swap(str, left, r);

	str_quick_sort(str, left, r - 1);
	str_quick_sort(str, r + 1, right);
}

bool CheckPermutation(char* s1, char* s2)
{
	if (s1 == NULL || s2 == NULL)
		return false;

	int size_s1 = strlen(s1);
	int size_s2 = strlen(s2);
	if (size_s1 != size_s2)
		return false;

	str_quick_sort(s1, 0, size_s1 - 1);
	str_quick_sort(s2, 0, size_s2 - 1);

	for (int i = 0; i < size_s1; i++)
		if (*(s1 + i) != *(s2 + i))
			return false;

	return true;
}

int main()
{
	char s1[] = "bacb";
	char s2[] = "caba";
	printf("before s1 = %s, s2 = %s\n", s1, s2);
	printf("the result is %d\n", CheckPermutation(s1, s2));
	printf("after  s1 = %s, s2 = %s\n", s1, s2);

	return 0;
}
