/*
5. 最长回文子串

给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：
输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。

示例 2：
输入: "cbbd"
输出: "bb"
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * longestPalindrome(char * s)
{
	unsigned int s_size = strlen(s);
	unsigned int aux_str_size = s_size * 2 + 1;
	char *aux_str = (char *)malloc(sizeof(char) * aux_str_size);
	int *p = (int *)malloc(sizeof(int) * aux_str_size);
	memset(aux_str, 0, sizeof(char) * aux_str_size);
	memset(p, 0, sizeof(int) * aux_str_size);

	for (int i = 0; i < s_size; i++) {
		aux_str[i * 2] = '#';
		aux_str[i * 2 + 1] = *(s + i);
	}
	aux_str[aux_str_size - 1] = '#';

	int max_sub_start = 0;
	int max_sub_len = 1;
	int center = 0;
	int max_right = 0;
	for (int i = 0; i < aux_str_size; i++) {
		if (i < max_right) {
			int i_mirror = 2 * center - i;
			p[i] = p[i_mirror] > max_right - i ? max_right - 1 : p[i_mirror];
		}

		int left = i - (p[i] + 1);
		int right = i + (p[i] + 1);
		while (left >= 0 && right < aux_str_size && aux_str[left] == aux_str[right]) {
			left -= 1;
			right += 1;
			p[i] += 1;
		}

		if (max_right < p[i] + i) {
			center = i;
			max_right = p[i] + 1;
		}
		if (max_sub_len < p[i]) {
			max_sub_len = p[i];
			max_sub_start = (i - max_sub_len) / 2;
		}
		printf("i = %d, p[i] = %d\n", i, p[i]);
	}

	char *res = (char *)malloc(sizeof(char) * (max_sub_len + 1));
	memset(res, 0, sizeof(char) * (max_sub_len + 1));
	for (int i = 0; i < max_sub_len; i++)
		*(res + i) = *(s + max_sub_start + i);

	return res;
}

int main()
{
	//char *str = "abbbab";
	char *str = "babad";
	printf("str = %s, max_sub = %s\n", str, longestPalindrome(str));

	return 0;
}
