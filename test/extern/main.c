#include <stdio.h>

extern int a;

int main()
{
	printf("num = %d\n", a);
	a = 55;
	printf("num = %d\n", a);

	return 0;
}
