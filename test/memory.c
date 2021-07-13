#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *data = (char *)malloc(16);
	memset(data, 'a', 2048);
	// printf("%s\n", data);

	char str[16];
	str[1024] = 10;
	printf("num = %c\n", str[1025]);

	int num = 10;
	*(int *)(&num + 1) = 100;
	printf("addr = %p\n", &num);
	printf("num = %d\n", *(int *)(&num + 1));

	return 0;
}
