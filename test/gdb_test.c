#include <stdio.h>

int func_1(int num)
{
	if (num > 0)
	{
		printf("[%s] num = %d\n", __FUNCTION__, num);
		return 0;
	}

	printf("[%s] end of %s\n", __FUNCTION__, __FUNCTION__);
}

int func_2()
{
	printf("[%s]\n", __FUNCTION__);

	return -1;
}

int main()
{
	func_1(10);
	func_1(5);
	func_1(-2);

	return 0;
}
