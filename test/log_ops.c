#include <stdio.h>
#include <math.h>

int main()
{
	int num = 0;

	num = 100;
	printf("num = %d, log10(num) = %d\n", num, (int)log10(num) + 1);

	num = 999;
	printf("num = %d, log10(num) = %d\n", num, (int)log10(num) + 1);

	num = 1000;
	printf("num = %d, log10(num) = %d\n", num, (int)log10(num) + 1);

	return 0;
}
