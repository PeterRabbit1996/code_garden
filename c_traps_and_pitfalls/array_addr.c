#include <stdio.h>

int main()
{
	char array[] = "hello";
	printf("&array = %p\n", &array);
	printf("&array[0] = %p\n", &array[0]);
	printf("&array[1] = %p\n", &array[1]);

	return 0;
}
