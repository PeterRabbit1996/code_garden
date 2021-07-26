/*
43. 字符串相乘

给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:
输入: num1 = "2", num2 = "3"
输出: "6"

示例 2:
输入: num1 = "123", num2 = "456"
输出: "56088"

说明：
num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_debug(char *num, int num_size)
{
	for (int i = 0; i < num_size; i++)
		printf("%c", *(num + i));
	printf("\n");

}

char *multiply(char * num1, char * num2)
{
	if ((strlen(num1) != 0 && *(num1 + 0) == '0') || (strlen(num2) != 0 && *(num2 + 0) == '0'))
	{
		char *ans = (char *)malloc(sizeof(char) * 2);
		*(ans + 0) = '0';
		*(ans + 1) = '\0';

		return ans;
	}

	int num1_size = strlen(num1);
	int num2_size = strlen(num2);
	int ans_size = num1_size + num2_size + 1;
	char *ans = (char *)malloc(sizeof(char) * ans_size);

	memset(ans, '0', sizeof(char) * ans_size);

	for (int i = num1_size - 1; i >= 0; i--)
	{
		int carry = 0;
		int factor_1 = (int)(*(num1 + i) - '0');
		for (int j = num2_size - 1; j >= 0; j--)
		{
			int factor_2 = (int)(*(num2 + j) - '0');
			int product = factor_1 * factor_2 + carry + (*(ans + i + j + 2) - '0');
			*(ans + i + j + 2) = (char)(product % 10 + '0');
			carry = product / 10;

		}
		*(ans + i + 1) = (char)(carry + '0'); // j equals to 0.

		carry = 0;
	}

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

	return ans;
}

int main()
{ char *num1 = "12345";
	char *num2 = "678";
	printf("num1 = %s\nnum2 = %s\nsum = %s\n", num1, num2, multiply(num1, num2));

	return 0;
}
