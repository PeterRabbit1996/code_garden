/*
面试题 01.06. 字符串压缩

字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。比如，字符串aabcccccaaa会变为a2b1c5a3。若“压缩”后的字符串没有变短，则返回原先的字符串。你可以假设字符串中只包含大小写英文字母（a至z）。

示例1:
 输入："aabcccccaaa"
 输出："a2b1c5a3"

示例2:
 输入："abbccd"
 输出："abbccd"
 解释："abbccd"压缩后为"a1b2c2d1"，比原字符串长度更长。

提示：
字符串长度在[0, 50000]范围内。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/****************
 * OMG rubbish!!!
 * gcc -O -g -fsanitize=address 01_06_Compress_String.c -o 01_06_Compress_String
****************/
char* compressString(char* S)
{
	const int size = strlen(S);
	char *str = (char *)malloc(sizeof(char) * (size * 2 + 1));

	if (str == NULL)
		return NULL;
	memset(str, '\0', size * 2 + 1);

	for (int i = 0, j = 0; i < size; i++, j++) {
		int cnt = 1;
		char c = *(S + i);
		*(str + j) = c;
		while (i < (size - 1) && *(S + i + 1) == c) {
			i += 1;
			cnt += 1;
		}

		int cnt_size = (int)log10(cnt) + 1;
		int k = j + cnt_size;
		while (cnt_size > 0) {
			*(str + j + cnt_size) = cnt % 10 + '0';
			cnt /= 10;
			cnt_size -= 1;
		}
		j = k;
	}

	if (strlen(S) <= strlen(str))
		return S;

	return str;
}

int main()
{
	//char *s = "aaabbbc";
	//char  *s = "aabcccccaa";
	char  *s = "aabbcc";
	printf("before compression: %s\n", s);
	printf("after compression: %s\n", compressString(s));

	return 0;
}
