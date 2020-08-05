#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main()
{
	int a = 0;
	int b = 2;
	printf("max num is [%d]\n", MAX(++a, b));
	printf("max num is [%d]\n", MAX(a++, b));

	a = 1;
	b = 2;
	printf("max num is [%d]\n", MAX(++a, b));
	printf("max num is [%d]\n", MAX(a++, b));
	

	a = 2;
	b = 2;
	printf("max num is [%d]\n", MAX(++a, b));
	printf("max num is [%d]\n", MAX(a++, b));

	return 0;
}
