/*
204. 计数质数

统计所有小于非负整数 n 的质数的数量。

示例:

输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int countPrimes(int n)
{
	int ans = 0;
	bool *is_prime = (bool *)malloc(sizeof(bool) * n);

	for (int i = 0; i < n; i++)
		is_prime[i] = true;

	for (int i = 2; i * i < n; i++)
		if (is_prime[i] == true)
			for (int j = i * i; j < n; j += i)
				is_prime[j] = false;

	for (int i = 2; i < n; i++)
		if (is_prime[i] == true)
			ans++;

	return ans;
}

int main()
{
	int n = 0;

	n = 10;
	printf("n = %d, ans = %d\n", n, countPrimes(n));

	return 0;
}
