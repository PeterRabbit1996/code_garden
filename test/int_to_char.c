#include <stdio.h>

int main()
{
	printf("char(0) = %d\n", (char)'0');
	printf("char(4) = %d\n", (char)'4');
	printf("char(5) = %d\n", (char)'5');
	printf("char(9) = %d\n", (char)'9');

	for (int i = 0; i < 10; i++)
		printf("i = %d, to char = %c\n", i, i + 48);

	return 0;
}
