#include <stdio.h>
#include <stdlib.h>

int main()
{
	//printf("%d\n", 1 << 2);
	char *str = (char *)malloc(sizeof(char) * 1024);
	printf("sizeof(str) = %lu\n", sizeof(str));

	return 0;
}
