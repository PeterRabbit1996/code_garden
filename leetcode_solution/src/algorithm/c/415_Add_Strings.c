/*
415. 字符串相加

给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

注意：

1. num1 和num2 的长度都小于 5100.
2. num1 和num2 都只包含数字 0-9.
3. num1 和num2 都不包含任何前导零。
4. 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * addStrings(char * num1, char * num2)
{
	int num1_size = strlen(num1);
	int num2_size = strlen(num2);
	int ans_size = (num1_size > num2_size ? num1_size : num2_size) + 2;
	char *ans = (char *)malloc(sizeof(char) * ans_size);

	memset(ans, '0', sizeof(char) * ans_size);

	for (int i = num1_size - 1, j = num2_size - 1, k = ans_size - 1, carry = 0; ; )
	{
		while (i >= 0 && j >= 0)
		{
			int sum = ((int)(*(num1 + i) - '0') + (int)(*(num2 + j) - '0')) + carry;
			*(ans + k) = (char)((sum % 10) + '0');
			carry = sum / 10;

			i--; j--; k--;
			continue;
		}

		while (i >= 0)
		{
			int sum = (int)(*(num1 + i) - '0') + carry;
			*(ans + k) = (char)((sum % 10) + '0');
			carry = sum / 10;

			i--; k--;
		}
		while (j >= 0)
		{
			int sum = (int)(*(num2 + j) - '0') + carry;
			*(ans + k) = (char)((sum % 10) + '0');
			carry = sum / 10;

			j--; k--;
		}

		*(ans + k) = (char)(carry + '0');

		break;
	}

	printf("%s\n", ans);

	{
                int i = 0;
                int j = 0;

                while (j < ans_size) {
                        if (*(ans + j) != '0')
                                break;
                        j++;
                }
                while (j < ans_size) {
                        *(ans + i) = *(ans + j);
                        i++;
                        j++;
                }
                while (i < ans_size) {
                        *(ans + i) = '\0';
                        i++;
                }
        }


	if ((strlen(num1) != 0 && *(num1 + 0) == '0') || (strlen(num2) != 0 && *(num2 + 0) == '0'))
		if (*(ans + 0) == '\0')
			*(ans + 0) = '0';

	return ans;
}

int main()
{
	char *num1 = "2";
	char *num2 = "9";
	printf("num1 = %s\nnum2 = %s\nsum = %s\n", num1, num2, addStrings(num1, num2));

	return 0;
}
