/*
实现 pow(x, n) ，即计算 x 的 n 次幂函数。

示例 1:

输入: 2.00000, 10
输出: 1024.00000
示例 2:

输入: 2.10000, 3
输出: 9.26100
示例 3:

输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25

说明:
-100.0 < x < 100.0
n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。
*/
#include <stdio.h>

#define PLUS	1
#define MINUS	0

double myPow(double x, int n)
{
	double ans = 1.0;
	double pro = x;
	long int power = n;
	int sign = PLUS;

	if (power < 0) {
		power = -power;
		sign = MINUS;
	}

	while (power != 0) {
		if (power % 2 == 1) {
			ans *= pro;
		}
		pro *= pro;
		power /= 2;
	}

	if (sign == MINUS)
		ans = 1.0 / ans;

	return ans;
}

int main()
{
	double x = 0;
	int n = 0;

	x = 0;
	n = 0;
	printf("x = %lf, n = %d, ans = %lf\n", x, n, myPow(x, n));

	x = 2;
	n = 0;
	printf("x = %lf, n = %d, ans = %lf\n", x, n, myPow(x, n));

	x = 0;
	n = 2;
	printf("x = %lf, n = %d, ans = %lf\n", x, n, myPow(x, n));

	x = 2;
	n = 5;
	printf("x = %lf, n = %d, ans = %lf\n", x, n, myPow(x, n));


	return 0;
}
