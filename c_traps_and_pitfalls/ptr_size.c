#include <stdio.h>

int main()
{
	char c = 0;
	int i = 0;
	char *ptr_char = &c;
	int *ptr_int = &i;

	printf("sizeof(c) = %lu\n", sizeof(c));
	printf("sizeof(i) = %lu\n", sizeof(i));
	printf("sizeof(ptr_char) = %lu\n", sizeof(ptr_char));
	printf("sizeof(ptr_int) = %lu\n", sizeof(ptr_int));

	return 0;
}
