#include <stdio.h>
#include <string.h>

int main()
{
	char *ptr = "hello!";

	printf("%s\n", ptr);
	printf("ptr = %p\n", ptr);
	printf("(ptr + 1) = %p\n", ptr + 1);
	printf("*ptr = %c\n", *ptr);
	printf("*(ptr + 1) = %c\n", *(ptr + 1));
	printf("strlen(ptr) = %lu\n", strlen(ptr));
	//*(ptr + 1) = 'E';
	//printf("%s\n", ptr);

	return 0;
}
