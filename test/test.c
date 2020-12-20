#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num = 0x1234567;

	// 4--------0100
	// d--------1101
	num |= (1 << 15);
	num |= (1 << 12);

	printf("0x%x\n", num);

	return 0;
}
