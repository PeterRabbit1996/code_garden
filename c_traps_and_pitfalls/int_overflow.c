#include <stdio.h>

int main()
{
	unsigned int num = ((long int)1 << 32) - 10;
	for (int i = 0; i < (1 << 8); i++, num++)
		printf("num = %u\n", num);

	return 0;
}
